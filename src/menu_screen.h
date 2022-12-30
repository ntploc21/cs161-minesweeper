#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "screen.h"

class MenuScreen : public Screen {
private:
    enum class ButtonType {
        kLargeButton,
        kSmallButton
    };

    const int kLargeButtonWidth = 600;
    const int kLargeButtonHeight = 50;

    const int kSmallButtonWidth = 295;
    const int kSmallButtonHeight = 50;

    const int kGameTitleCorner_x = 370;
    const int kGameTitleCorner_y = 200;
    const int kGameTitleFontSize = 72;

    const int kPlayCorner_x = 300;
    const int kPlayCorner_y = 330;
    const ButtonType kPlayButton = ButtonType::kLargeButton;

    const int kContinueCorner_x = 300;
    const int kContinueCorner_y = 390;
    const ButtonType kContinueButton = ButtonType::kLargeButton;

    const int kSettingsCorner_x = 300;
    const int kSettingsCorner_y = 450;
    const ButtonType kSettingsButton = ButtonType::kSmallButton;

    const int kQuitGameCorner_x = 605;
    const int kQuitGameCorner_y = 450;
    const ButtonType kQuitGameButton = ButtonType::kSmallButton;

public:
    //void interact();

    void Interact(Game *game);
    
    void Draw(Game *game);

    MenuScreen();
};

#endif // MENU_SCREEN_H