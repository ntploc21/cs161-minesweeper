#include "screen.h"

#include "raylib.h"
//#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "game.h"

bool Screen::DrawSmallButton(int x, int y, const char text[]) {
    bool clicked = GuiButton({x, y, kSmallButtonWidth, kSmallButtonHeight}, text);
    return clicked;
}

bool Screen::DrawLargeButton(int x, int y, const char text[]) {
    bool clicked = GuiButton({x, y, kLargeButtonWidth, kLargeButtonHeight}, text);
    return clicked;
}

bool Screen::DrawButton(int x, int y, ButtonType button_type, const char text[]) {
    if(button_type == ButtonType::kLargeButton) {
        return DrawLargeButton(x, y, text);
    } else if(button_type == ButtonType::kSmallButton) {
        return DrawSmallButton(x, y, text);
    }
}

void Screen::Interact(Game *game) {}

void Screen::Draw(Game *game) {}

Screen::Screen() {

}