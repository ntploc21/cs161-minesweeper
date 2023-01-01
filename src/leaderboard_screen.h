#ifndef LEADERBOARD_SCREEN_H
#define LEADERBOARD_SCREEN_H

#include "screen.h"
#include "config.h"

class LeaderboardScreen : public Screen {
private:
    bool in_game = false;

    Config *config;

    /* */

    const int kLeaderboardTitleCorner_x = 370;
    const int kLeaderboardTitleCorner_y = 200;
    const int kLeaderboardTitleFontSize = 72;


    const int kBackToMenuCorner_x = 300;
    const int kBackToMenuCorner_y = 680;
    const ButtonType kBackToMenuButton = ButtonType::kLargeButton;
    const char kBackToMenuText[100] = "Back to menu";
    
    /* */
    const int kBoardCorner_x = 200;
    const int kBoardCorner_y = 290;
    const int kBoardWidth = 800;
    const int kBoardHeight = 320;
    const int kBoardSectionWidth = 266;
    const int kBoardMargin = 5;

    const int kBeginnerSectionTitleCorner_x = 280;
    const int kBeginnerSectionTitleCorner_y = 300;
    const int kBeginnerSectionTitleFontSize = 24;
    const int kBeginnerSectionCorner_x = 220;
    const int kBeginnerSectionCorner_y = 330;

    const int kIntermediateSectionTitleCorner_x = 515;
    const int kIntermediateSectionTitleCorner_y = 300;
    const int kIntermediateSectionTitleFontSize = 24;
    const int kIntermediateSectionCorner_x = 486;
    const int kIntermediateSectionCorner_y = 330;

    const int kExpertSectionTitleCorner_x = 815;
    const int kExpertSectionTitleCorner_y = 300;
    const int kExpertSectionTitleFontSize = 24;
    const int kExpertSectionCorner_x = 752;
    const int kExpertSectionCorner_y = 330;

    void DrawLeaderboard();
    void DrawHighScoreSection(std::vector<int> scores, int x, int y);
    void DrawHighSCoreText(int index, int score, int x, int y);
public:

    void Interact(Game *game);
    void Draw(Game *game);

    LeaderboardScreen();

    void SetIngame(bool _in_game);

    void SetConfig(Config *config);
};

#endif // LEADERBOARD_SCREEN_H