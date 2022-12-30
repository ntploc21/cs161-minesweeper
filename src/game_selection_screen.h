#ifndef GAME_SELECTION_SCREEN_H
#define GAME_SELECTION_SCREEN_H

#include "screen.h"

class GameSelectionScreen : public Screen {
private:
    /* Buttons */
    const int kLargeButtonWidth = 600;
    const int kLargeButtonHeight = 50;

    const int kSmallButtonWidth = 295;
    const int kSmallButtonHeight = 50;

    const int kTitleCorner_x = 295;
    const int kTitleCorner_y = 200;
    const int kTitleFontSize = 72;

    const int kBeginnerCorner_x = 300;
    const int kBeginnerCorner_y = 330;

    const int kIntermediateCorner_x = 300;
    const int kIntermediateCorner_y = 390;

    const int kExpertCorner_x = 300;
    const int kExpertCorner_y = 450;

    const int kCustomCorner_x = 300;
    const int kCustomCorner_y = 510;

    const int kCancelCorner_x = 605;
    const int kCancelCorner_y = 510;
    
    /* */
    bool custom_mode = false;

    /* */
public:
    void Interact(Game *game);

    void DrawMainScreen(Game *game);

    void DrawCustomScreen(Game *game);
    
    void Draw(Game *game);

    GameSelectionScreen();
};

#endif // GAME_SELECTION_SCREEN_H