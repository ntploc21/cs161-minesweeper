#include "gameplay.h"

#include "globals.h"
#include "game.h"

#include "raylib.h"
#include "raygui.h"

#include <iostream>

GameMode Gameplay::GetGameMode() {
    int board_width = table.GetWidth();
    int board_height = table.GetHeight();
    int mines = table.GetNumBomb();

    if(board_width == global::kBeginnerTableWidth &&
        board_height == global::kBeginnerTableHeight &&
        mines == global::kBeginnerTableMines) {
        return GameMode::Beginner;
    }
    
    if(board_width == global::kIntermediateTableWidth &&
        board_height == global::kIntermediateTableHeight &&
        mines == global::kIntermediateTableMines) {
        return GameMode::Intermediate;
    }

    if(board_width == global::kExpertTableWidth &&
        board_height == global::kExpertTableHeight &&
        mines == global::kExpertTableMines) {
        return GameMode::Expert;
    }

    return GameMode::Undefined;
}

void Gameplay::Interact(Game *game) {
    if(game_state != GameState::Playing) return;

    const auto [table_x, table_y] =
        table.GetCoordsFromPos(GetMouseX(), GetMouseY());
    if(table_x == -1 || table_y == -1) return;

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int reveal_value = table.RevealCell(table_x, table_y, first_click);
        first_click = 0;
        
        if(reveal_value == -1) {
            game_state = GameState::Lost;
        } else if(reveal_value == 1) {
            game_state = GameState::Won;
            for(int i=0;i<table.GetWidth();i++) {
                for(int j=0;j<table.GetHeight();j++) {
                    if(table.GetCell(i, j).GetValue() == Cell::kBombCellValue &&
                        table.GetCell(i, j).GetCellState() == CellState::Closed) {
                        table.GetCell(i, j).ToggleFlagged();
                    }
                }
            }
            table.CalculateNumFlagged();
            score = time_elapsed * 60 + frame_counter;

            config->WriteConfigHighScore(GetGameMode(), score);
        }
    } else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        table.GetCell(table_x, table_y).ToggleFlagged();
        table.CalculateNumFlagged();
    }
}

bool Gameplay::DrawFrame() {
    ClearBackground(WHITE);
    DrawTexture(sprite.GetBackground(), 0, 0, WHITE);
    DrawMessages();

    int num_displayed_bomb_unrevealed = table.GetNumBomb() - table.GetNumFlagged();
    if(game_state != GameState::Playing) num_displayed_bomb_unrevealed = 0;

    DrawCounter(num_displayed_bomb_unrevealed, kCounterBomb_x, kCounterBom_y);
    DrawCounter(time_elapsed, kCounterTime_x, kCounterTime_y);

    return DrawFace();
}

void Gameplay::DrawMessages() {
    if(game_state == GameState::Playing ||
        game_state == GameState::Paused) return;

    std::string messagesTitle;
    std::string scoreMessage;
    std::string timeMessage;

    if(game_state == GameState::Won) {
        messagesTitle = kMessagesTitleWon;
    } else if(game_state == GameState::Lost) {
        messagesTitle = kMessagesTitleLost;
    }

    DrawTextEx(font, messagesTitle.c_str(), {(float)kMessagesTitlePos_x, (float)kMessagesTitlePos_y}, 14, 0.3, BLACK);
    std::string time = std::to_string(time_elapsed) + "." + std::to_string(frame_counter * 100 / 60);

    scoreMessage = "Score: " + std::to_string(score);
    timeMessage = "Time: " + time + " sec";
    
    DrawTextEx(font, timeMessage.c_str(), {(float)kMessagesTimePos_x, (float)kMessagesTimePos_y}, 14, 0.3, BLACK);
    
    DrawTextEx(font, scoreMessage.c_str(), {(float)kMessagesScorePos_x, (float)kMessagesScorePos_y}, 14, 0.3, BLACK);
}

void Gameplay::Draw(Game *game) {
    bool playing = false;
    if(game_state != GameState::Won &&
        game_state != GameState::Lost) {
        playing = true;
    }
    if(playing) {
        game_state = GameState::Playing;
    }

    UpdateFrameCount();
    /* */
    
    if(DrawFrame()) {
        if(playing) game_state = GameState::Paused;
        game->ScreenToIngameMenu();
    }
    table.DrawTable();
}

void Gameplay::Initialize() {
    sprite.Initialize();
    font = LoadFont("assets/carme-regular.ttf");
}

void Gameplay::Start(int width, int height, int mines) {
    game_state = GameState::Playing;
    table = Table(width, height, mines, &sprite);
    first_click = 1;

    time_elapsed = 0;
    frame_counter = 0;
    score = 0;
}

Gameplay::Gameplay() {
}

std::pair<int, int> Gameplay::GetTimePlayed() {
    return {time_elapsed, frame_counter};
}

GameState Gameplay::GetGameState() {
    return game_state;
}

Table& Gameplay::GetTable() {
    return table;
}

void Gameplay::RestoreGame(int width,
                        int height,
                        int prev_time_elapsed,
                        int prev_frame_counter,
                        GameState prev_game_state,
                        std::vector<int> board_value,
                        std::vector<CellState> board_state) {
    game_state = prev_game_state;
    first_click = 1;
    int mines = 0;
    time_elapsed = prev_time_elapsed;
    frame_counter = prev_frame_counter;
    if(game_state == GameState::Won) {
        score = time_elapsed * 60 + frame_counter;
    }

    for(int i=0;i<width*height;i++) {
        mines+= (board_value[i] == Cell::kBombCellValue ||
                board_value[i] == Cell::kExplodedCellValue);
        first_click&= (board_state[i] == CellState::Closed);
    }

    table = Table(width, height, mines, &sprite);
    for(int i=0;i<width*height;i++) {
        int x = i % width;
        int y = i / width;
        table.GetCell(x, y).SetValue(board_value[i]);
        table.GetCell(x, y).SetSprite(&sprite);
        switch(board_state[i]) {
            case CellState::Opened:
                table.GetCell(x, y).Reveal();
            break;
            case CellState::Flagged:
                table.GetCell(x, y).ToggleFlagged();
            break;
            case CellState::Closed: break;
        }
    }

}

void Gameplay::UpdateFrameCount() {
    if(first_click) return;
    if(game_state == GameState::Playing) {
        frame_counter++;
    }

    if(frame_counter == global::kFramesPerSecond) {
        frame_counter = 0;
        time_elapsed++;
    }
}

void Gameplay::DrawCounter(int value, int x, int y) {
    Texture2D counterNumberTexture[3];
    if(value < 0 || value >= 1000) {
        // undefined
        for(int i=0;i<3;i++) {
            counterNumberTexture[i] = sprite.GetCounterUndefined();
        }
    } else {
        int hundred = value / 100;
        int tenth = (value - hundred * 100) / 10;
        int unit = value % 10;

        counterNumberTexture[0] = sprite.GetCounterNumber(hundred);
        counterNumberTexture[1] = sprite.GetCounterNumber(tenth);
        counterNumberTexture[2] = sprite.GetCounterNumber(unit);
    }

    for(int i=0;i<3;i++) {
        DrawTexture(counterNumberTexture[i],
            x + i * (kCounterWidth),
            y,
            WHITE
        );
    }
}

bool Gameplay::DrawFace() {
    Texture2D Face;
    switch(game_state) {
        case GameState::Playing:
            Face = sprite.GetFaceNeutral();
        break;
        case GameState::Paused:
            Face = sprite.GetFaceNeutralClicked();
        break;
        case GameState::Won:
            Face = sprite.GetFaceWon();
        break;
        case GameState::Lost:
            Face = sprite.GetFaceLost();
        break;
        default: break;
    }
    bool face_clicked = GuiButton({kFace_x, kFace_y, 48, 48}, "");
    DrawTexture(Face,
        kFace_x,
        kFace_y,
        WHITE
    );


    return face_clicked;
}

void Gameplay::SetConfig(Config *config) {
    this->config = config;
}