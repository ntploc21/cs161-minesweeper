#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "screen.h"

class MenuScreen : public Screen {
private:
    const int kGameTitleCorner_x = 370;
    const int kGameTitleCorner_y = 200;
    const int kGameTitleFontSize = 72;

    const int kPlayCorner_x = 300;
    const int kPlayCorner_y = 330;
    const ButtonType kPlayButton = ButtonType::kLargeButton;
    const char kPlayText[100] = "New game";

    const int kContinueCorner_x = 300;
    const int kContinueCorner_y = 390;
    const ButtonType kContinueButton = ButtonType::kLargeButton;
    const char kContinueText[100] = "Continue";

    const int kHighScoreCorner_x = 300;
    const int kHighScoreCorner_y = 450;
    const ButtonType kHighScoreButton = ButtonType::kSmallButton;
    const char kHighScoreText[100] = "Leaderboard";

    const int kQuitGameCorner_x = 605;
    const int kQuitGameCorner_y = 450;
    const ButtonType kQuitGameButton = ButtonType::kSmallButton;
    const char kQuiteGameText[100] = "Quit game";

public:
    //void interact();

    void Interact(Game *game);
    
    void Draw(Game *game);

    MenuScreen();
};

#endif // MENU_SCREEN_H