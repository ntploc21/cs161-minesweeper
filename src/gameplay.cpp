#include "gameplay.h"

#include "game.h"
#include "raylib.h"
#include "raygui.h"

#include <iostream>

void Gameplay::Interact(Game *game) {

}

void Gameplay::Draw(Game *game) {

    ClearBackground(GRAY);

    for(int i=1;i<=20;i++) {
        for(int j=1;j<=30;j++) {
            bool cell = GuiButton({
                                j*31, i*31, 30, 30
                                }, "x");
            DrawTexture(sprite.GetFlaggedCell(),
                            j*31, i*31, WHITE);

        }
    }
}

void Gameplay::Initialize() {
    sprite.Initialize();
}

Gameplay::Gameplay() {
}