#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#include "table.h"
#include "globals.h"

Table::Table():
    board_width(0),
    board_height(0),
    num_bomb(0) {}

Table::Table(int width, int height, int m_num_bomb, Sprite *sprite):
    board_width(width),
    board_height(height),
    num_bomb(m_num_bomb),
    num_flagged(0) {
    this->sprite = sprite;
    FillTable();
    SetScreenPos();
}

bool Table::CoordsInBoard(int x, int y) {
    return (0 <= x && x < board_width &&
        0 <= y && y < board_height);
}

std::pair<int, int> Table::GetCoordsFromPos(int x, int y) {
    if(x < board_corner_x || x > board_corner_x + table_width ||
        y < board_corner_y || y > board_corner_y + table_height) {
        return {-1, -1};
    }
    x-= board_corner_x, y-= board_corner_y;

    return {x / (cell_size + 1),
            y / (cell_size + 1)};
}

Cell& Table::GetCell(int x, int y) {
    return board.at(y * board_width + x);
}


void Table::FillTable(int mustEmpty_x, int mustEmpty_y) {
    board = std::vector<Cell>(board_width * board_height);
    for(Cell &cell:board) {
        cell.SetSprite(sprite);
    }
    /* */
    std::random_device rd;
    std::mt19937 mt(rd());

    auto Rand = [&] (int l, int r) -> int {
        return l + mt() % (r - l + 1);
    };

    auto GenSubset = [&] (std::vector<int> v, int size_subset) -> std::vector<int> {
        if(size_subset > v.size()) return v;

        int num_of_Shuffle = 5;
        for(int i=1;i<=num_of_Shuffle;i++) {
            std::shuffle(v.begin(), v.end(), mt);
        }
        v.resize(size_subset);
        return v;
    };
    //

    auto CountNeighborBombs = [&] (int x, int y) -> int {
        int num_neighbor_bombs = 0;
        for(int offset_x = -1; offset_x <= 1;offset_x++) {
            for(int offset_y = -1; offset_y <= 1;offset_y++) {
                if(offset_x == 0 && offset_y == 0) {
                    // not nearby cell
                    continue;
                }
                int nearby_x = x + offset_x;
                int nearby_y = y + offset_y;
                if(!CoordsInBoard(nearby_x, nearby_y)) continue;
                num_neighbor_bombs+= (GetCell(nearby_x, nearby_y).GetValue()
                                        == Cell::kBombCellValue);
            }
        }
        return num_neighbor_bombs;
    };

    /* */

    std::vector<int> bomb_cells(board_width * board_height);
    std::iota(bomb_cells.begin(), bomb_cells.end(), 0);

    auto it = find(bomb_cells.begin(),
                    bomb_cells.end(),
                    mustEmpty_x + mustEmpty_y * board_width);
    if(it != bomb_cells.end()) bomb_cells.erase(it);

    bomb_cells = GenSubset(bomb_cells, num_bomb);

    for(int cell_idx:bomb_cells) {
        board[cell_idx].SetValue(Cell::kBombCellValue);

        int x = cell_idx % board_width;
        int y = cell_idx / board_width;
    }

    for(int x=0;x<board_width;x++) {
        for(int y=0;y<board_height;y++) {
            Cell &cell = GetCell(x, y);
            if(cell.GetValue() == Cell::kBombCellValue) continue;
            cell.SetValue(CountNeighborBombs(x, y));
        }
    }
}

void Table::ClearNearbyCells(int src_coord_x, int src_coord_y) {
    const int x_offsets[8] {-1, -1, -1, 0, 0, 1, 1, 1};
    const int y_offsets[8] {-1, 0, 1, -1, 1, -1, 0, 1};

    std::queue<std::pair<int, int>> _queue;
    _queue.push({src_coord_x, src_coord_y});


    for(;!_queue.empty();_queue.pop()) {
        int current_x, current_y;
        std::tie(current_x, current_y) = _queue.front();
        
        for(int i=0;i<8;i++) {
            int next_x = current_x + x_offsets[i];
            int next_y = current_y + y_offsets[i];


            if(!CoordsInBoard(next_x, next_y)) continue;
            Cell &next_cell = GetCell(next_x, next_y);

            if(next_cell.GetCellState() == CellState::Opened) continue;
            next_cell.Reveal();
            if(next_cell.GetValue() == 0) {
                _queue.push({next_x, next_y});
            }
        }
    }
}

void Table::SetScreenPos() {
    table_width = board_width * cell_size + (board_width - 1);
    table_height = board_height * cell_size + (board_height - 1);
    
    board_corner_x = (global::kScreenWidth - table_width) / 2;
    board_corner_y = base_y + (global::kScreenHeight - base_y - table_height) / 2;

    auto GetScreenPosFromCoords = [&] (int x, int y) -> std::pair<int, int> {
        return {board_corner_x + x * (cell_size + 1),
                board_corner_y + y * (cell_size + 1)};
    };

    for(int i=0;i<board_width * board_height;i++) {
        int x = i % board_width;
        int y = i / board_width;

        int screen_pos_x, screen_pos_y;
        std::tie(screen_pos_x, screen_pos_y) = GetScreenPosFromCoords(x, y);
        
        board[i].SetScreenPos(screen_pos_x, screen_pos_y);
    }
}

/* return -1 if clicked  on bomb
    return 1 if all non-bomb cells are cleared
    return 0 otherwise
*/
int Table::RevealCell(int x, int y, bool first_click) {
    if(GetCell(x, y).GetCellState() != CellState::Closed) return 0;

    if(first_click) {
        FillTable(x, y);
        SetScreenPos();
    }
    Cell &cell = GetCell(x, y);
    
    bool clicked_on_bomb = cell.Reveal();

    if(clicked_on_bomb) {
        cell.SetExploded();
        for(int i=0;i<board_width * board_height;i++) {
            board[i].Reveal();
        }
        return -1;
    }
    
    if(cell.GetValue() == 0) {
        ClearNearbyCells(x, y);
    }

    int num_revealed = 0;
    for(int i=0;i<board_width * board_height;i++) {
        num_revealed+= (board[i].GetCellState() == CellState::Opened);
    }
    if(num_revealed == board_width * board_height - num_bomb) {
        return 1;
    }

    CalculateNumFlagged();
    return 0;
}

int Table::GetWidth() {
    return board_width;
}
int Table::GetHeight() {
    return board_height;
}
int Table::GetNumBomb() {
    return num_bomb;
}
void Table::CalculateNumFlagged() {
    for(int i=0;i<board_width * board_height;i++) {
        num_flagged+= board[i].GetCellState() == CellState::Flagged;
    }
}

int Table::GetNumFlagged() {
    return num_flagged;
}

void Table::DrawTable() {
    for(int i=0;i<board_width * board_height;i++) {
        board[i].DrawCell();
    }
}