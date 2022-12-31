#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "menu_screen.h"
#include "game_selection_screen.h"
#include "gameplay.h"
#include "gameplay_menu_screen.h"

#include "globals.h"

class Game {
private:
    bool closed = false;
    Gameplay gameplay = Gameplay();
    MenuScreen menu_screen = MenuScreen();
    GameSelectionScreen game_selection_screen = GameSelectionScreen();
    GameplayMenuScreen gameplay_menu_screen = GameplayMenuScreen();

    Screen *screen = &menu_screen;
public:
    Game();
    
    // Game screen
    void ScreenToMenu();
    void ScreenToGameSelection(bool in_game);
    void ScreenToGameplay(int width, int height, int mines);
    void ScreenToGameplay();
    void ScreenToContinue();
    void ScreenToSettings();
    void ScreenToIngameMenu();

    void EndGame();
    void CloseGameWindow();
    bool WindowClosed();
    
    void InitGame();
    void RenderGame();

    Gameplay& GetGameplay();
    // 
};

#endif // GAME_H