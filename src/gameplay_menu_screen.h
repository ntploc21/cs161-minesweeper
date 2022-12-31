#ifndef GAMEPLAY_MENU_SCREEN_H
#define GAMEPLAY_MENU_SCREEN_H

#include "screen.h"

class GameplayMenuScreen: public Screen {
private:
    const int kSubtitle_Custom_Corner_x = 310;
    const int kSubtitle_Custom_Corner_y = 280;
    const int kSubtitle_Custom_FontSize = 36;
    const char kSubtitle_Custom_Text[100] = "In-game menu";

    
    const int kBackToGameCorner_x = 300;
    const int kBackToGameCorner_y = 330;
    const ButtonType kBackToGameButton = ButtonType::kLargeButton;

    const int kRestartCorner_x = 300;
    const int kRestartCorner_y = 390;
    const ButtonType kRestartButton = ButtonType::kLargeButton;

    const int kNewGameCorner_x = 300;
    const int kNewGameCorner_y = 450;
    const ButtonType kNewGameButton = ButtonType::kLargeButton;

    const int kLeaderboardCorner_x = 300;
    const int kLeaderboardCorner_y = 510;
    const ButtonType kLeaderboardButton = ButtonType::kSmallButton;

    const int kBackToMenuCorner_x = 605;
    const int kBackToMenuCorner_y = 510;
    const ButtonType kBackToMenuButton = ButtonType::kSmallButton;

public:
    void Interact(Game *game);

    void Draw(Game *game);

    //void Draw(Game *game, );

    GameplayMenuScreen();
};

#endif // GAMEPLAY_MENU_SCREEN_H