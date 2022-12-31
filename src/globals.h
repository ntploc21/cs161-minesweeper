#ifndef GLOBAL_H
#define GLOBAL_H

namespace global {
    constexpr int kScreenWidth = 1200;
    constexpr int kScreenHeight = 800;
    constexpr int kFramesPerSecond = 60;

    /* */
    constexpr int kBeginnerTableWidth = 9;
    constexpr int kBeginnerTableHeight = 9;
    constexpr int kBeginnerTableMines = 10;

    constexpr int kIntermediateTableWidth = 16;
    constexpr int kIntermediateTableHeight = 16;
    constexpr int kIntermediateTableMines = 40;
    
    constexpr int kExpertTableWidth = 24;
    constexpr int kExpertTableHeight = 20;
    constexpr int kExpertTableMines = 99;

    constexpr int kMaxWidth = 25;
    constexpr int kMaxHeight = 20;
}

#endif // GLOBAL_H