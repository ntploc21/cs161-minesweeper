#ifndef CONFIG_H
#define CONFIG_H

/*  save high score

*/

#include "gameplay.h"

enum GameStateInInt {
    Playing = 0,
    Won = 1,
    Lost = 2
};

enum CellStateInInt {
    Opened = 0,
    Closed = 1,
    Flagged = 2
};

class Config {
private:
    const char kLastGamePath[100] = "last_game.dat";
    const char kHighScorePath[100] = "high_score.dat";

    /* */
    GameStateInInt GetGameStateInInt(GameState game_state);
    CellStateInInt GetCellStateInInt(CellState cell_state);

    GameState GetGameState(int game_state_);
    CellState GetCellState(int cell_state_);

public:
    void WriteConfigGame(Gameplay &gameplay);
    bool ReadConfigGameAndReCreate(Gameplay &gameplay);
    void WriteConfigHighScore();

    Config();
};

#endif // CONFIG_H