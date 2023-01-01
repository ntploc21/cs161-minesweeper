#include "gameplay_menu_screen.h"

#include "game.h"

void GameplayMenuScreen::Interact(Game *game) {

}

void GameplayMenuScreen::Draw(Game *game) {
    Gameplay &gameplay = game->GetGameplay();
    bool to_game_selected = gameplay.DrawFrame();

    to_game_selected|= DrawButton(kBackToGameCorner_x, kBackToGameCorner_y, kBackToGameButton, "Continue");

    bool restart_selected = DrawButton(kRestartCorner_x, kRestartCorner_y, kRestartButton, "Restart");

    bool new_game_selected = DrawButton(kNewGameCorner_x, kNewGameCorner_y, kNewGameButton, "New game");
    
    bool leader_board_selected = DrawButton(kLeaderboardCorner_x, kLeaderboardCorner_y, kLeaderboardButton, "Leaderboard");
    
    bool to_menu_selected = DrawButton(kBackToMenuCorner_x, kBackToMenuCorner_y, kBackToMenuButton, "Back to menu");

    if(to_game_selected) {
        game->ScreenToGameplay();
    } else if(restart_selected) {
        Table table = gameplay.GetTable();

        game->ScreenToGameplay(table.GetWidth(), table.GetHeight(), table.GetNumBomb());
    } else if(new_game_selected) {
        game->ScreenToGameSelection(true);
    } else if(leader_board_selected) {
        
    } else if(to_menu_selected) {
        /* save game here ...*/
        game->SaveCurrentGame();

        game->ScreenToMenu();
    }
}

GameplayMenuScreen::GameplayMenuScreen() {

}