#include "game_selection_screen.h"

#include "game.h"
#include "globals.h"

#include "raylib.h"
#include "raygui.h"

void GameSelectionScreen::Interact(Game *game) {

}

void GameSelectionScreen::DrawMainScreen(Game *game) {
    DrawText("Create new game", kTitleCorner_x, kTitleCorner_y, kTitleFontSize, BLACK);
    
    bool beginner_selected = GuiButton({kBeginnerCorner_x, kBeginnerCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                                "Beginner");
        
    bool intermdiate_selected = GuiButton({kIntermediateCorner_x, kIntermediateCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                                "Intermediate");
    bool expert_selected = GuiButton({kExpertCorner_x, kExpertCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                                "Expert");
    bool custom_selected = GuiButton({kCustomCorner_x, kCustomCorner_y, kSmallButtonWidth, kSmallButtonHeight},
                                "Custom");

    bool cancel_selected = GuiButton({kCancelCorner_x, kCancelCorner_y, kSmallButtonWidth, kSmallButtonHeight},
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
        game->ScreenToMenu();
    }
}

void GameSelectionScreen::DrawCustomScreen(Game *game) {
    DrawText("Create new game", kTitleCorner_x, kTitleCorner_y, kTitleFontSize, BLACK);
    
}

void GameSelectionScreen::Draw(Game *game) {
    ClearBackground(WHITE);
    if(!custom_mode) DrawMainScreen(game);
    else DrawCustomScreen(game);
}

GameSelectionScreen::GameSelectionScreen() {

}