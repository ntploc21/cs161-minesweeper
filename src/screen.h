#ifndef SCREEN_H
#define SCREEN_H

enum class ScreenType {
    kMenu,
    kGameplay,
    kGameSettings,
    kSettings
};

namespace global {
    void ScreenToMenu();
    void ScreenToGameSelection();
    void ScreenToGameplay();
    void ScreenToContinue();
    void ScreenToSettings();
    
    ScreenType GetScreenType();
}

#endif // SCREEN_H