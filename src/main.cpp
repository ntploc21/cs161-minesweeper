#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "globals.h"

int main() {

    InitWindow(global::kScreenWidth, global::kScreenHeight, "CS161 - Minesweeper");
    SetTargetFPS(global::kFramesPerSecond);

    while(!WindowShouldClose()) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
}