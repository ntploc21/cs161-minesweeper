#ifndef GAME_SELECTION_SCREEN_H
#define GAME_SELECTION_SCREEN_H

#include "screen.h"

class GameSelectionScreen : public Screen {
private:
    /* Buttons */

    const int kTitleCorner_x = 295;
    const int kTitleCorner_y = 200;
    const int kTitleFontSize = 72;
    const char kTitleText[100] = "Create new game";

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
    int custom_board_width = 9;
    int custom_board_height = 9;
    int custom_board_mines = 10;

    const int kSubtitle_Custom_Corner_x = 310;
    const int kSubtitle_Custom_Corner_y = 280;
    const int kSubtitle_Custom_FontSize = 36;
    const char kSubtitle_Custom_Text[100] = "Customize your game as you wish!";

    const int kBoardWidthSpinnerCorner_x = 300;
    const int kBoardWidthSpinnerCorner_y = 330;
    
    const int kBoardHeightSpinnerCorner_x = 300;
    const int kBoardHeightSpinnerCorner_y = 390;

    const int kBoardMinesSpinnerCorner_x = 300;
    const int kBoardMinesSpinnerCorner_y = 450;
    
    const int kPlay_Custom_Corner_x = 300;
    const int kPlay_Custom_Corner_y = 510;

    bool in_game = false;
    /* */
public:
    void Interact(Game *game);

    void DrawMainScreen(Game *game);

    void DrawCustomScreen(Game *game);
    
    void Draw(Game *game);

    void BackToMainSelection();

    GameSelectionScreen();

    bool SetIngame(bool _in_game);
};

#endif // GAME_SELECTION_SCREEN_H