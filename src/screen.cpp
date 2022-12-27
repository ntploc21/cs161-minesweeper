#include "screen.h"

namespace global {
    static ScreenType screen_type = ScreenType::kMenu;

    // default screen
    void ScreenToMenu() {
        screen_type = ScreenType::kMenu;
    }

    void ScreenToGameSelection() {
        screen_type = ScreenType::kGameplay;
    }

    void ScreenToGameplay() {
        screen_type = ScreenType::kGameplay;
    }

    void ScreenToContinue() {
        screen_type = ScreenType::kGameplay;
    }

    void ScreenToSettings() {
        screen_type = ScreenType::kSettings;
    }

    ScreenType GetScreenType() {
        return screen_type;
    }
}