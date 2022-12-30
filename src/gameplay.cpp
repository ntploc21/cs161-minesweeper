#include "gameplay.h"

#include "globals.h"
#include "game.h"

#include "raylib.h"
#include "raygui.h"

#include <iostream>

void Gameplay::Interact(Game *game) {
    if(game_state != GameState::Playing) return;

    const auto [table_x, table_y] =
        table.GetCoordsFromPos(GetMouseX(), GetMouseY());
    if(table_x == -1 || table_y == -1) return;
    //Cell &cell = ;


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

        }
    } else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        table.GetCell(table_x, table_y).ToggleFlagged();
        table.CalculateNumFlagged();
    }
}

void Gameplay::Draw(Game *game) {
    UpdateFrameCount();
    /* */
    ClearBackground(LIGHTGRAY);
    DrawTexture(sprite.GetBackground(), 0, 0, WHITE);
    
    //DrawFrame();

    table.DrawTable();

    DrawCounter(table.GetNumBomb() - table.GetNumFlagged(), kCounterBomb_x, kCounterBom_y);
    DrawCounter(time_elapsed, kCounterTime_x, kCounterTime_y);
    
    /*for(int i=1;i<=15;i++) {
        for(int j=1;j<=15;j++) {
            DrawTexture(sprite.GetBombCell(),
                            200 + j*31, 150 + i*31, WHITE);

        }
    }*/
}

void Gameplay::Initialize() {
    sprite.Initialize();
}

void Gameplay::Start(int width, int height, int mines) {
    game_state = GameState::Playing;
    table = Table(width, height, mines, &sprite);

    time_elapsed = 0;
    frame_counter = 0;
}

Gameplay::Gameplay() {
}

void Gameplay::UpdateFrameCount() {
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
    }
    int hundred = value / 100;
    int tenth = (value - hundred * 100) / 10;
    int unit = value % 10;

    counterNumberTexture[0] = sprite.GetCounterNumber(hundred);
    counterNumberTexture[1] = sprite.GetCounterNumber(tenth);
    counterNumberTexture[2] = sprite.GetCounterNumber(unit);


    for(int i=0;i<3;i++) {
        DrawTexture(counterNumberTexture[i],
            x + i * (kCounterWidth),
            y,
            GRAY
        );
    }
}