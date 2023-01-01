#include "game.h"

int main() {
    Game _game = Game();
    _game.InitGame();
    while(!_game.WindowClosed()) {
        _game.RenderGame();
    }
    _game.CloseGameWindow();
    
}