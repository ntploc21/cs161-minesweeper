#include "table.h"

Table::Table():
    board_width(0),
    board_height(0),
    num_bomb(0) {}

Table::Table(int width, int height, int m_num_bomb):
    board_width(width),
    board_height(height),
    num_bomb(m_num_bomb),
    board(width * height) {
    FillTable();
    SetScreenPos();
}

void Table::FillTable() {
    
}

void Table::DrawCell(Cell cell) {

}

void Table::DrawTable() {

}