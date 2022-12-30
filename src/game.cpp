#include "game.h"

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <iostream>

void Game::InitGame() {
    InitWindow(global::kScreenWidth, global::kScreenHeight, "CS161 - Minesweeper");
    SetTargetFPS(global::kFramesPerSecond);
    gameplay.Initialize();
}

void Game::EndGame() {
    closed = true;
}

void Game::CloseGameWindow() {
    CloseWindow();
}

bool Game::WindowClosed() {
    return closed;
}

void Game::RenderGame() {
    screen->Interact(this);
    BeginDrawing();
    
    screen->Draw(this);
    
    EndDrawing();

    if(WindowShouldClose()) EndGame();
}

//
void Game::ScreenToMenu() {
    screen = &menu_screen;
}

void Game::ScreenToGameSelection() {
    screen = &game_selection_screen;
}

void Game::ScreenToGameplay(int width, int height, int mines) {
    gameplay.Start(width, height, mines);
    screen = &gameplay;
}
//

Game::Game() {
}