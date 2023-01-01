#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "menu_screen.h"
#include "game_selection_screen.h"
#include "gameplay.h"
#include "gameplay_menu_screen.h"
#include "config.h"

#include "globals.h"

class Game {
private:
    bool closed = false;
    Gameplay gameplay = Gameplay();
    MenuScreen menu_screen = MenuScreen();
    GameSelectionScreen game_selection_screen = GameSelectionScreen();
    GameplayMenuScreen gameplay_menu_screen = GameplayMenuScreen();
    Config config = Config();

    Screen *screen = &menu_screen;
    //Screen *screen = &game_selection_screen;
public:
    Game();
    
    // Game screen
    void ScreenToMenu();
    void ScreenToGameSelection(bool in_game);
    void ScreenToGameplay(int width, int height, int mines);
    void ScreenToGameplay();
    void ScreenToSettings();
    void ScreenToIngameMenu();

    void EndGame();
    void CloseGameWindow();
    bool WindowClosed();
    
    void InitGame();
    void RenderGame();

    Gameplay& GetGameplay();

    void SaveCurrentGame();
    void LoadPreviousGame();
    // 
};

#endif // GAME_H