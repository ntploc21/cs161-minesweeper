
/*
#include "screen.h"
#include "menu_screen.h"
*/

#include "game.h"

//#include "globals.h"

int main() {
    //InitWindow(global::kScreenWidth, global::kScreenHeight, "CS161 - Minesweeper");
    //SetTargetFPS(global::kFramesPerSecond);

    
    Game _game = Game();
    _game.InitGame();
    while(!_game.WindowClosed()) {
    //while(!WindowShouldClose()) {
        _game.RenderGame();
        /*BeginDrawing();
        bool new_game_selected = GuiButton({100, 100, 100, 100},
                                            "New game");

        //if(WindowClosed()) CloseWindow();

        EndDrawing();*/
    }
    _game.CloseGameWindow();
    
}