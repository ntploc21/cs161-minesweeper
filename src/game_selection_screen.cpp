#include "game_selection_screen.h"

#include "game.h"
#include "globals.h"

#include "raylib.h"
#include "raygui.h"

void GameSelectionScreen::Interact(Game *game) {

}

void GameSelectionScreen::DrawMainScreen(Game *game) {
    DrawText("Create new game", kTitleCorner_x, kTitleCorner_y, kTitleFontSize, BLACK);
    
    bool beginner_selected = DrawLargeButton(kBeginnerCorner_x, kBeginnerCorner_y,
                                "Beginner");
    bool intermdiate_selected = DrawLargeButton(kIntermediateCorner_x, kIntermediateCorner_y,
                                "Intermediate");
    bool expert_selected = DrawLargeButton(kExpertCorner_x, kExpertCorner_y,
                                "Expert");
    bool custom_selected = DrawSmallButton(kCustomCorner_x, kCustomCorner_y,
                                "Custom");
    bool cancel_selected = DrawSmallButton(kCancelCorner_x, kCancelCorner_y,
                                "Cancel");
    if(beginner_selected) {
        game->ScreenToGameplay(global::kBeginnerTableWidth,
                                global::kBeginnerTableHeight,
                                global::kBeginnerTableMines);
    } else if(intermdiate_selected) {
        game->ScreenToGameplay(global::kIntermediateTableWidth,
                                global::kIntermediateTableHeight,
                                global::kIntermediateTableMines);
    } else if(expert_selected) {
        game->ScreenToGameplay(global::kExpertTableWidth,
                                global::kExpertTableHeight,
                                global::kExpertTableMines);
    } else if(custom_selected) {
        custom_mode = true;
    } else if(cancel_selected) {
        if(in_game) game->ScreenToIngameMenu();
        else game->ScreenToMenu();
    }
}

void GameSelectionScreen::DrawCustomScreen(Game *game) {
    DrawText(kTitleText, kTitleCorner_x, kTitleCorner_y, kTitleFontSize, BLACK);
    DrawText(kSubtitle_Custom_Text, kSubtitle_Custom_Corner_x, kSubtitle_Custom_Corner_y, kSubtitle_Custom_FontSize, BLACK);

    bool width_spinner = GuiSpinner({kBoardWidthSpinnerCorner_x, kBoardWidthSpinnerCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                "width ", &custom_board_width, 3, global::kMaxWidth, false);
    bool height_spinner = GuiSpinner({kBoardHeightSpinnerCorner_x, kBoardHeightSpinnerCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                "height ", &custom_board_height, 3, global::kMaxHeight, false);
    bool mines_spinner = GuiSpinner({kBoardMinesSpinnerCorner_x, kBoardMinesSpinnerCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                "mines ", &custom_board_mines, 1, custom_board_height * custom_board_width - 1, false);

    bool play_selected = DrawSmallButton(kPlay_Custom_Corner_x, kPlay_Custom_Corner_y,
                                "Play");
    bool back_selected = DrawSmallButton(kCancelCorner_x, kCancelCorner_y,
                                "Back");

    if(back_selected) {
        BackToMainSelection();
    } else if(play_selected) {
        game->ScreenToGameplay(custom_board_width,
                                custom_board_height,
                                custom_board_mines);
    }
}

void GameSelectionScreen::BackToMainSelection() {
    custom_mode = false;
    /*custom_board_width = 9;
    custom_board_height = 9;
    custom_board_mines = 10;*/
}

void GameSelectionScreen::Draw(Game *game) {
    ClearBackground(WHITE);
    if(!custom_mode) DrawMainScreen(game);
    else DrawCustomScreen(game);
}

GameSelectionScreen::GameSelectionScreen() {

}

bool GameSelectionScreen::SetIngame(bool _in_game) {
    in_game = _in_game;
}