#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "screen.h"
#include "sprite.h"
#include "table.h"

#include <string>

enum class GameState {
    Playing,
    Paused,
    Won,
    Lost
};

class Gameplay : public Screen {
private:
    /* */
    const int kCounterTime_x = 1100;
    const int kCounterTime_y = 20;
    
    const int kCounterBomb_x = 22;
    const int kCounterBom_y = 20;

    const int kFace_x = 576;
    const int kFace_y = 19;

    /* */
    GameState game_state = GameState::Lost;

    int frame_counter;
    int time_elapsed;
    int score;
    /* */

    Table table;
    Sprite sprite = Sprite();

    bool first_click = 1;


    /* */

    const int kCounterWidth = 24;
    const int kCounterHeight = 44;

    bool DrawFace();
    void DrawCounter(int value, int x, int y);
    
    void UpdateFrameCount();

    /* */
    Font font;
    const std::string kMessagesTitleWon = "Congratulation! You win.";
    const std::string kMessagesTitleLost = "Oops... try again";

    const int kMessagesTitlePos_x = 1005;
    const int kMessagesTitlePos_y = 190;

    const int kMessagesScorePos_x = 1010;
    const int kMessagesScorePos_y = 205;

    const int kMessagesTimePos_x = 1010;
    const int kMessagesTimePos_y = 217;
public:
    Table& GetTable();

    void Interact(Game *game);

    bool DrawFrame();
    void DrawMessages();

    void Draw(Game *game);

    Gameplay();

    void Start(int width, int height, int mines);
    void Initialize();

    std::pair<int, int> GetTimePlayed();
    GameState GetGameState();

    void RestoreGame(int width,
                    int height,
                    int prev_time_elapsed,
                    int prev_frame_counter,
                    GameState prev_game_state,
                    std::vector<int> board_value,
                    std::vector<CellState> board_state);
};

#endif // GAMEPLAY_H