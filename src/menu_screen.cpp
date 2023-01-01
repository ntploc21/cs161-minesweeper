#include "menu_screen.h"

#include "game.h"
#include "raylib.h"
#include "raygui.h"

void MenuScreen::Interact(Game *game) {

}

void MenuScreen::Draw(Game *game) {
    ClearBackground(WHITE);

    DrawText("Minesweeper", kGameTitleCorner_x, kGameTitleCorner_y, kGameTitleFontSize, BLACK);
    
    bool new_game_selected = DrawButton(kPlayCorner_x, kPlayCorner_y, kPlayButton, kPlayText);

    bool continue_selected = DrawButton(kContinueCorner_x, kContinueCorner_y, kContinueButton, kContinueText);
    
    bool leader_board_selected = DrawButton(kHighScoreCorner_x, kHighScoreCorner_y, kHighScoreButton, kHighScoreText);
    
    bool quit_selected = DrawButton(kQuitGameCorner_x, kQuitGameCorner_y, kQuitGameButton, kQuiteGameText);

    if(new_game_selected) {
        game->ScreenToGameSelection(false);
    } else if(continue_selected) {
        game->LoadPreviousGame();
    } else if(leader_board_selected) {
        game->ScreenToLeaderboard(false);
    } else if(quit_selected) {
        game->EndGame();
    }
}

MenuScreen::MenuScreen() {

}