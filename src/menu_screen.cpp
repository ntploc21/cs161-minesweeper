#include "menu_screen.h"

#include "game.h"
#include "raylib.h"
#include "raygui.h"

void MenuScreen::Interact(Game *game) {

}

void MenuScreen::Draw(Game *game) {
    ClearBackground(WHITE);

    DrawText("Minesweeper", kGameTitleCorner_x, kGameTitleCorner_y, kGameTitleFontSize, BLACK);

    bool new_game_selected = GuiButton({kPlayCorner_x, kPlayCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                                "New game");
        
    bool continue_selected = GuiButton({kContinueCorner_x, kContinueCorner_y, kLargeButtonWidth, kLargeButtonHeight},
                                "Continue");
    bool settings_selected = GuiButton({kSettingsCorner_x, kSettingsCorner_y, kSmallButtonWidth, kSmallButtonHeight},
                                "Options");
    bool quit_selected = GuiButton({kQuitGameCorner_x, kQuitGameCorner_y, kSmallButtonWidth, kSmallButtonHeight},
                                "Quit game");

    if(new_game_selected) {
        game->ScreenToGameSelection();
    } else if(continue_selected) {
        
    } else if(settings_selected) {
        
    } else if(quit_selected) {
        game->EndGame();
    }
}

MenuScreen::MenuScreen() {

}