#include "sprite.h"
#include <iostream>

Sprite::Sprite() {}

Texture2D Sprite::GetBackground() {
    return background_texture;
}

Texture2D Sprite::GetTexture(int x, int y, int spriteWidth, int spriteHeight, int actualWidth, int actualHeight) {
    Image object_image_sprite = ImageFromImage(image_sprite, {
            x,
            y,
            spriteWidth,
            spriteHeight
        });
    ImageResize(&object_image_sprite, actualWidth, actualHeight);

    Texture2D object_sprite = LoadTextureFromImage(object_image_sprite);
    return object_sprite;    
}

Texture2D Sprite::GetTextureCell(int x, int y) {
    return GetTexture(x,
        y,
        kCellSizeInSprite,
        kCellSizeInSprite,
        kCellSize,
        kCellSize);
}

void Sprite::Initialize() { // load sprites
    //std::cout << GetWorkingDirectory() << std::endl;
    image_background = LoadImage(backgroundPath);
    background_texture = LoadTextureFromImage(image_background);


    image_sprite = LoadImage(spritePath);
    /* */
    int max_neighboring_bombs = 8;
    for(int i=1;i<=max_neighboring_bombs;i++) {
        RevealedEmptyCell[i] = GetTextureCell(
            kEmptyCellSpritesStartFromOne_x + (kCellSizeInSprite + 2) * (i - 1),
            kEmptyCellSpritesStartFromOne_y
        );
    }
    RevealedEmptyCell[0] = GetTextureCell(
        kZeroEmptyCellSprite_x,
        kZeroEmptyCellSprite_y
    );

    /* */
    UnrevealedCell = GetTextureCell(
        kUnrevealedCellSprite_x,
        kUnrevealedCellSprite_y
    );
    
    /* */
    ClickedCell = GetTextureCell(
        kClickedCell_x,
        kClickedCell_y
    );

    /* */
    FlaggedCell = GetTextureCell(
        kFlaggedCellSprite_x,
        kFlaggedCellSprite_y
    );

    /* */
    BombCell = GetTextureCell(
        kBombCellSprite_x,
        kBombCellSprite_y
    );

    ExplodedCell = GetTextureCell(
        kExplodedCellSprite_x,
        kExplodedCellSprite_y
    );

    /* */
    int number_of_num_counter = 10;
    for(int i=1;i<=number_of_num_counter;i++) {
        CounterNumber[i%10] = GetTexture(
            kCounterSpritesStartFromOne_x + (kCounterSpriteWidth + 2) * (i - 1),
            kCounterSpritesStartFromOne_y,
            kCounterSpriteWidth,
            kCounterSpriteHeight,
            kCounterWidth,
            kCounterHeight
        );
    }

    CounterUndefined = GetTexture(
        kCounterUndefinedSprite_x,
        kCounterUndefinedSprite_y,
        kCounterSpriteWidth,
        kCounterSpriteHeight,
        kCounterWidth,
        kCounterHeight
    );
}

Texture2D Sprite::GetCounterNumber(int number) {
    return CounterNumber[number];
}

Texture2D Sprite::GetCounterUndefined() {
    return CounterUndefined;
}

Texture2D Sprite::GetRevealedEmptyCell(int num_neighboring_bomb) {
    return RevealedEmptyCell[num_neighboring_bomb];
}

Texture2D Sprite::GetUnrevealedCell() {
    return UnrevealedCell;
}

Texture2D Sprite::GetClickedCell() {
    return ClickedCell;
}

Texture2D Sprite::GetFlaggedCell() {
    return FlaggedCell;
}

Texture2D Sprite::GetBombCell() {
    return BombCell;
}

Texture2D Sprite::GetExplodedCell() {
    return ExplodedCell;
}