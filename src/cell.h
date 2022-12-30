#ifndef CELL_H
#define CELL_H

#include "sprite.h"

enum class CellState {
    Opened,
    Closed,
    Flagged
};

class Cell {
private:
    Sprite *sprite;

    int value;
    CellState cell_state;

    int screen_pos_x;
    int screen_pos_y;
public:
    static constexpr int kCellSize = 30;
    static constexpr int kBombCellValue = -1;
    static constexpr int kExplodedCellValue = -2;

    void SetScreenPos(int x, int y);

    void SetValue(int value);
    int GetValue() const;
    CellState GetCellState() const;

    bool Reveal();
    bool ToggleFlagged();
    void SetExploded();

    void DrawCell();

    void SetSprite(Sprite *sprite);

    Cell();
};

#endif // CELL_H