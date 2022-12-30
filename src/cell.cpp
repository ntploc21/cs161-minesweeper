#include "cell.h"

Cell::Cell():
    value(0),
    screen_pos_x(0),
    screen_pos_y(0),
    cell_state(CellState::Closed) {}

void Cell::SetScreenPos(int x, int y) {
    screen_pos_x = x;
    screen_pos_y = y;
}

void Cell::SetValue(int value) {
    this->value = value;
}

int Cell::GetValue() const {
    return value;
}

CellState Cell::GetCellState() const {
    return cell_state;
}

// return true if clicked on bomb
bool Cell::Reveal() {
    if(cell_state != CellState::Opened) {
        cell_state = CellState::Opened;
    }
    return value == bomb_cell_value;
}

void Cell::ToggleFlagged() {
    if(cell_state == CellState::Opened) return;
    
    if(cell_state == CellState::Flagged) {
        cell_state = CellState::Closed;
    } else if(cell_state == CellState::Closed) {
        cell_state = CellState::Flagged;
    }
}