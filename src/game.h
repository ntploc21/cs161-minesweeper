#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "menu_screen.h"
#include "game_selection_screen.h"
#include "gameplay.h"

#include "globals.h"

class Game {
private:
    bool closed = false;

    Gameplay gameplay = Gameplay();
    MenuScreen menu_screen = MenuScreen();
    GameSelectionScreen game_selection_screen = GameSelectionScreen();

    Screen *screen = &menu_screen;
public:
    Game();
    
    // Game screen
    void ScreenToMenu();
    void ScreenToGameSelection();
    void ScreenToGameplay(int width, int height, int mines);
    void ScreenToContinue();
    void ScreenToSettings();

    void EndGame();
    void CloseGameWindow();
    bool WindowClosed();
    
    void InitGame();
    void RenderGame();
    // 
};

#endif // GAME_H