#include "game.h"

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <iostream>

void Game::InitGame() {
    InitWindow(global::kScreenWidth, global::kScreenHeight, "CS161 - Minesweeper");
    SetTargetFPS(global::kFramesPerSecond);
    gameplay.Initialize();
    gameplay.SetConfig(&config);
    leaderboard_screen.SetConfig(&config);
}

void Game::EndGame() {
    config.WriteConfigGame(gameplay);
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

void Game::ScreenToGameSelection(bool in_game = false) {
    game_selection_screen.SetIngame(in_game);
    screen = &game_selection_screen;
}

void Game::ScreenToGameplay(int width, int height, int mines) {
    gameplay.Start(width, height, mines);
    ScreenToGameplay();
}

void Game::ScreenToGameplay() {
    screen = &gameplay;
}

void Game::ScreenToIngameMenu() {
    screen = &gameplay_menu_screen;
}

void Game::ScreenToLeaderboard(bool in_game = false) {
    leaderboard_screen.SetIngame(in_game);
    screen = &leaderboard_screen;
}

Gameplay& Game::GetGameplay() {
    return gameplay;
}

void Game::SaveCurrentGame() {
    config.WriteConfigGame(gameplay);
}

void Game::LoadPreviousGame() {
    if(config.ReadConfigGameAndReCreate(gameplay)) {
        ScreenToGameplay();
    }
}

//

Game::Game() {
}