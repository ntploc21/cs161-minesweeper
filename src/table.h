#ifndef TABLE_H
#define TABLE_H

#include "cell.h"
#include <vector>

class Table {
private:
    int board_corner_x;
    int board_corner_y;

    int board_width;
    int board_height;
    int num_bomb;
    std::vector<Cell> board;
    
public:
    
    void SetScreenPos();

    void DrawCell(Cell cell);
    
    void FillTable();
    void DrawTable();
    Table();
    Table(int width, int height, int numBomb);
};

#endif // TABLE_H