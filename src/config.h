#ifndef CONFIG_H
#define CONFIG_H

/*  save high score

*/

#include "game_state.h"
#include "cell.h"
#include "globals.h"

//#include "gameplay.h"
class Gameplay;

#include <vector>

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

enum class GameMode {
    Beginner,
    Intermediate,
    Expert,
    Undefined
};

class Config {
private:
    const char kLastGamePath[100] = "last_game.dat";
    const char kHighScorePath[100] = "high_score.dat";

    /* */
    const int kNumHighscoreSaved = 5;
    std::vector<int> beginner_highscores;
    std::vector<int> intermediate_highscores;
    std::vector<int> expert_highscores;

    /* */
    GameStateInInt GetGameStateInInt(GameState game_state);
    CellStateInInt GetCellStateInInt(CellState cell_state);

    GameState GetGameState(int game_state_);
    CellState GetCellState(int cell_state_);

public:
    constexpr static int kInfiniteScore = (int) 1e9 + 7;

    /* */
    void WriteConfigGame(Gameplay &gameplay);
    bool ReadConfigGameAndReCreate(Gameplay &gameplay);
    bool WriteConfigHighScore(GameMode game_mode, int score);
    void WriteConfigHighScore();
    void LoadConfigHighScore();

    Config();

    std::vector<int> GetBeginnerHighScores();
    std::vector<int> GetIntermediateHighScores();
    std::vector<int> GetExpertHighScores();
};

#endif // CONFIG_H