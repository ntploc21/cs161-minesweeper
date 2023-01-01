#include "config.h"

#include "gameplay.h"

#include <fstream>
#include <sstream>
#include <algorithm>

#include <iostream>

GameStateInInt Config::GetGameStateInInt(GameState game_state) {
    GameStateInInt game_state_;
    switch(game_state) {
        case GameState::Playing:
        case GameState::Paused:
            game_state_ = GameStateInInt::Playing;
        break;
        case GameState::Won:
            game_state_ = GameStateInInt::Won;
        break;
        case GameState::Lost:
            game_state_ = GameStateInInt::Lost;
        break;
        default: break;
    }
    return game_state_;
}

CellStateInInt Config::GetCellStateInInt(CellState cell_state) {
    CellStateInInt cell_state_;
    switch(cell_state) {
        case CellState::Opened:
            cell_state_ = CellStateInInt::Opened;
        break;
        case CellState::Closed:
            cell_state_ = CellStateInInt::Closed;
        break;
        case CellState::Flagged:
            cell_state_ = CellStateInInt::Flagged;
        break;
        default: break;
    }
    return cell_state_;
}

GameState Config::GetGameState(int game_state_) {
    GameState game_state;
    switch(game_state_) {
        case GameStateInInt::Playing:
            game_state = GameState::Playing;
        break;
        case GameStateInInt::Won:
            game_state = GameState::Won;
        break;
        case GameStateInInt::Lost:
            game_state = GameState::Lost;
        break;
        default: break;
    }
    return game_state;
}
CellState Config::GetCellState(int cell_state_) {
    CellState cell_state;
    switch(cell_state_) {
        case CellStateInInt::Opened:
            cell_state = CellState::Opened;
        break;
        case CellStateInInt::Closed:
            cell_state = CellState::Closed;
        break;
        case CellStateInInt::Flagged:
            cell_state = CellState::Flagged;
        break;
        default: break;
    }
    return cell_state;
}

void Config::WriteConfigGame(Gameplay &game) {
    Table table = game.GetTable();
    int board_width = table.GetWidth();
    int board_height = table.GetHeight();
    auto [time_elapsed, frames] = game.GetTimePlayed();
    GameStateInInt game_state = GetGameStateInInt(
                                game.GetGameState());

    int board_value[board_width][board_height];
    CellStateInInt board_state[board_width][board_height];
    for(int x=0;x<board_width;x++) {
        for(int y=0;y<board_height;y++) {
            board_value[x][y] = table.GetCell(x, y).GetValue();
            board_state[x][y] = GetCellStateInInt(
                table.GetCell(x, y).GetCellState());
        }
    }

    /* */
    std::ofstream game_file(kLastGamePath);

    game_file << board_width << " "
            << board_height << " "
            << time_elapsed <<" "
            << frames << " "
            << game_state << "\n";

    for(int y=0;y<board_height;y++) {
        for(int x=0;x<board_width;x++) {
            game_file << board_value[x][y];

            if(x < board_width - 1) game_file << " ";
        }
        game_file << "\n";
    }

    for(int y=0;y<board_height;y++) {
        for(int x=0;x<board_width;x++) {
            game_file << board_state[x][y];

            if(x < board_width - 1) game_file << " ";
        }
        game_file << "\n";
    }

    game_file.close();
}

bool Config::ReadConfigGameAndReCreate(Gameplay &gameplay) {
    std::ifstream game_file(kLastGamePath);
    if(!game_file.is_open()) return false;

    int board_width, board_height;
    int time_elapsed, frames, game_state_;
    
    game_file   >> board_width
                >> board_height
                >> time_elapsed
                >> frames
                >> game_state_;

    if(board_width < 3 ||
        board_height < 3) return false;

    /*std::cout << board_width << " "
            << board_height << " "
            << time_elapsed <<" "
            << frames << " "
            << game_state_ << "\n";*/
    
    std::vector<int> board_value(board_width * board_height);
    std::vector<CellState> board_state(board_width * board_height);
    GameState game_state = GetGameState(game_state_);

    for(int y=0;y<board_height;y++) {
        for(int x=0;x<board_width;x++) {
            int i = y * board_width + x;
            game_file >> board_value[i];
        }
    }

    for(int y=0;y<board_height;y++) {
        for(int x=0;x<board_width;x++) {
            int i = y * board_width + x;
            int cur_cell_state;
            game_file >> cur_cell_state;
            board_state[i] = GetCellState(cur_cell_state);
        }
    }

    gameplay.RestoreGame(board_width,
                        board_height,
                        time_elapsed,
                        frames,
                        game_state,
                        board_value,
                        board_state);
    game_file.close();

    return 1;
}

bool Config::WriteConfigHighScore(GameMode game_mode, int score) {
    std::vector<int> *scores;
    switch(game_mode) {
        case GameMode::Beginner:
            scores = &beginner_highscores;
        break;
        case GameMode::Intermediate:
            scores = &intermediate_highscores;
        break;
        case GameMode::Expert:
            scores = &expert_highscores;
        break;
        default: return false;
        break;
    }
    scores->push_back(score);
    std::sort(scores->begin(), scores->end());
    scores->resize(kNumHighscoreSaved);
    
    WriteConfigHighScore();

    return (scores->back() >= score);
}

void Config::WriteConfigHighScore() {
    std::ofstream score_file(kHighScorePath);
    if(!score_file.is_open()) {
        std::cout << "[Config Error] <Write> Cannot load file config high score." << std::endl;
        return;
    }

    for(int score:beginner_highscores) score_file << score << "\n";
    for(int score:intermediate_highscores) score_file << score << "\n";
    for(int score:expert_highscores) score_file << score << "\n";

    score_file.close();
}

void Config::LoadConfigHighScore() {
    std::ifstream score_file(kHighScorePath);
    if(!score_file.is_open()) {
        std::cout << "[Config Error] <Read> Cannot load file config high score." << std::endl;
        return;
    }

    auto ReadInt = [&] () -> int {
        if(score_file.eof()) return 0;
        int num;
        score_file >> num;
        return num;
    };

    for(int &score:beginner_highscores) score = ReadInt();
    for(int &score:intermediate_highscores) score = ReadInt();
    for(int &score:expert_highscores) score = ReadInt();

    score_file.close();
}

std::vector<int> Config::GetBeginnerHighScores() {
    return beginner_highscores;
}

std::vector<int> Config::GetIntermediateHighScores() {
    return intermediate_highscores;
}

std::vector<int> Config::GetExpertHighScores() {
    return expert_highscores;
}

Config::Config():
    beginner_highscores(kNumHighscoreSaved),
    intermediate_highscores(kNumHighscoreSaved),
    expert_highscores(kNumHighscoreSaved)
{
    for(int &score:beginner_highscores)  score = kInfiniteScore;
    for(int &score:intermediate_highscores) score = kInfiniteScore;
    for(int &score:expert_highscores) score = kInfiniteScore;
    LoadConfigHighScore();

}