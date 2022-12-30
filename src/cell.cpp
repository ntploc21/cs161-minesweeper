#include "cell.h"

#include "raylib.h"
#include "raygui.h"

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
    return value == kBombCellValue;
}

void Cell::SetExploded() {
    value = kExplodedCellValue;
}

bool Cell::ToggleFlagged() {
    if(cell_state == CellState::Opened) return false;
    
    if(cell_state == CellState::Flagged) {
        cell_state = CellState::Closed;
    } else if(cell_state == CellState::Closed) {
        cell_state = CellState::Flagged;
    }
    
    return cell_state == CellState::Flagged;
}

// return true when clicked
void Cell::DrawCell() {

    switch(cell_state) {
        case CellState::Opened:
            Texture2D cell_texture;
            if(value == kBombCellValue) {
                cell_texture = sprite->GetBombCell();
            } else if(value == kExplodedCellValue) {
                cell_texture = sprite->GetExplodedCell();
            } else {
                cell_texture = sprite->GetRevealedEmptyCell(value);
            }

            DrawTexture(cell_texture,
                screen_pos_x,
                screen_pos_y,
                LIGHTGRAY
            );

        break;
        case CellState::Closed:
            DrawTexture(sprite->GetUnrevealedCell(),
                screen_pos_x,
                screen_pos_y,
                LIGHTGRAY);
            
        break;
        case CellState::Flagged:
            DrawTexture(sprite->GetFlaggedCell(),
                screen_pos_x,
                screen_pos_y,
                LIGHTGRAY
            );
            
        break;
        default: break;
    }
}

void Cell::SetSprite(Sprite *sprite) {
    this->sprite = sprite;
}