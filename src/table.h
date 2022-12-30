#ifndef TABLE_H
#define TABLE_H

#include "cell.h"
#include <vector>
#include "sprite.h"

class Table {
private:
    static constexpr int base_x = 200;
    static constexpr int base_y = 60;
    static constexpr int cell_size = 30;

    int board_corner_x;
    int board_corner_y;

    int table_width;
    int table_height;
    int board_width;
    int board_height;
    int num_bomb;
    int num_flagged;
    std::vector<Cell> board;

    Sprite *sprite;
public:
    static constexpr int kMaxWidth = 25;
    static constexpr int kMaxHeight = 20;

    Cell& GetCell(int x, int y);
    int GetWidth();
    int GetHeight();
    int GetNumBomb();
    void CalculateNumFlagged();
    int GetNumFlagged();
    
    void SetScreenPos();

    int RevealCell(int x, int y, bool first_click);
    
    void FillTable(int mustEmpty_x = -1, int mustEmpty_y = -1);
    void DrawTable();

    void ClearNearbyCells(int src_coord_x, int src_coord_y);

    bool CoordsInBoard(int x, int y);
    std::pair<int, int> GetCoordsFromPos(int x, int y);

    Table();
    Table(int width, int height, int numBomb, Sprite *sprite);
};

#endif // TABLE_H