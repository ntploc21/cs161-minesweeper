#ifndef SCREEN_H
#define SCREEN_H

class Game;

class Screen {
protected:
    enum class ButtonType {
        kLargeButton,
        kSmallButton
    };
    static constexpr int kLargeButtonWidth = 600;
    static constexpr const int kLargeButtonHeight = 50;

    static constexpr int kSmallButtonWidth = 295;
    static constexpr int kSmallButtonHeight = 50;

    bool DrawLargeButton(int x, int y, const char text[]);
    bool DrawSmallButton(int x, int y, const char text[]);
    bool DrawButton(int x, int y, ButtonType button_type, const char text[]);
public:
    Screen();
    virtual void Interact(Game *game);
    virtual void Draw(Game *game);
};

#endif // SCREEN_H