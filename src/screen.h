#ifndef SCREEN_H
#define SCREEN_H

class Game;

/*enum class ScreenType {
    kMenu,
    kGameSelection,
    kGameplay,
    kSettings
};*/

class Screen {
public:
    Screen();
    virtual void Interact(Game *game);
    virtual void Draw(Game *game);
};

#endif // SCREEN_H