#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "screen.h"
#include "sprite.h"
#include "table.h"

enum class GameState {
    Playing,
    Won,
    Lost
};

class Gameplay : public Screen {
private:
    /* */
    const int kCounterTime_x = 1100;
    const int kCounterTime_y = 20;
    
    const int kCounterBomb_x = 22;
    const int kCounterBom_y = 20;

    /* */
    GameState game_state;

    int frame_counter;
    int time_elapsed;
    /* */

    Table table;
    Sprite sprite = Sprite();

    bool first_click = 1;

    void UpdateFrameCount();

    const int kCounterWidth = 24;
    const int kCounterHeight = 44;
    void DrawCounter(int value, int x, int y);
public:
    void Interact(Game *game);

    void Draw(Game *game);

    Gameplay();

    void Start(int width, int height, int mines);
    void Initialize();
};

#endif // GAMEPLAY_H