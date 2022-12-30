#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "screen.h"
#include "sprite.h"

class Gameplay : public Screen {
private:
    const int kCellSize = 30;

    Texture2D RevealedEmptyCell[9];
    
    Sprite sprite = Sprite();

    bool first_run = 0;
public:
    void Interact(Game *game);

    void Draw(Game *game);

    Gameplay();

    void Initialize();
};

#endif // GAMEPLAY_H