#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include "raygui.h"

class Sprite {
private:
    const char backgroundPath[100] = "assets/background.png";
    Image image_background;
    Texture2D background_texture;
    
    const char spritePath[100] = "assets/sprites.png";
    Image image_sprite;

    const int kCellSizeInSprite = 15;
    const int kCellSize = 30;

    const int kCounterSpriteWidth = 12;
    const int kCounterSpriteHeight = 22;
    const int kCounterWidth = 24;
    const int kCounterHeight = 44;
    
    /* */
    const int kEmptyCellSpritesStartFromOne_x = 0;
    const int kEmptyCellSpritesStartFromOne_y = 66;

    const int kZeroEmptyCellSprite_x = 17;
    const int kZeroEmptyCellSprite_y = 49;

    Texture2D RevealedEmptyCell[9];

    //
    const int kUnrevealedCellSprite_x = 0;
    const int kUnrevealedCellSprite_y = 49;
    Texture2D UnrevealedCell;

    //
    const int kFlaggedCellSprite_x = 34;
    const int kFlaggedCellSprite_y = 49;
    Texture2D FlaggedCell;

    //
    const int kBombCellSprite_x = 85;
    const int kBombCellSprite_y = 49;
    Texture2D BombCell;

    const int kExplodedCellSprite_x = 102;
    const int kExplodedCellSprite_y = 49;
    Texture2D ExplodedCell;

    //
    const int kClickedCell_x = 17;
    const int kClickedCell_y = 49;
    Texture2D ClickedCell;

    //
    const int kCounterSpritesStartFromOne_x = 0;
    const int kCounterSpritesStartFromOne_y = 0;
    Texture2D CounterNumber[10];

    const int kCounterUndefinedSprite_x = 140;
    const int kCounterUndefinedSprite_y = 0;
    Texture2D CounterUndefined;

public:

    Sprite();

    Texture2D GetBackground();

    Texture2D GetTextureCell(int x, int y);
    Texture2D GetTexture(int x, int y, int spriteWidth, int spriteHeight, int actualWidth, int actualHeight);
    void Initialize();

    //
    Texture2D GetCounterNumber(int number);
    Texture2D GetCounterUndefined();

    Texture2D GetRevealedEmptyCell(int num_neighboring_bomb);
    Texture2D GetUnrevealedCell();
    Texture2D GetClickedCell();
    Texture2D GetFlaggedCell();
    Texture2D GetBombCell();
    Texture2D GetExplodedCell();
};

#endif // SPRITE_H