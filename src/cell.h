#ifndef CELL_H
#define CELL_H

enum class CellState {
    Opened,
    Closed,
    Flagged
};

class Cell {
private:
    int value;
    CellState cell_state;

    int screen_pos_x;
    int screen_pos_y;
public:
    static constexpr int bomb_cell_value = -1;

    void SetScreenPos(int x, int y);

    void SetValue(int value);
    int GetValue() const;
    CellState GetCellState() const;

    bool Reveal();
    void ToggleFlagged();
    Cell();
};

#endif // CELL_H