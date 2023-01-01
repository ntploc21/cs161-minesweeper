#include "leaderboard_screen.h"

#include "game.h"

#include "raylib.h"
#include "raygui.h"

void LeaderboardScreen::Interact(Game *game) {

}

void LeaderboardScreen::Draw(Game *game) {
    ClearBackground(WHITE);

    DrawText("Leaderboard", kLeaderboardTitleCorner_x,
            kLeaderboardTitleCorner_y, kLeaderboardTitleFontSize, BLACK);
    
    DrawLeaderboard();

    bool to_menu_clicked = DrawButton(kBackToMenuCorner_x, kBackToMenuCorner_y,
            kBackToMenuButton, kBackToMenuText);
    
    if(to_menu_clicked) {
        if(in_game) game->ScreenToIngameMenu();
        else game->ScreenToMenu();
    }
}

void LeaderboardScreen::DrawLeaderboard() {
    GuiGroupBox((Rectangle){kBoardCorner_x, kBoardCorner_y,
                        kBoardWidth, kBoardHeight}, NULL);
    
    DrawLineEx({(float)kBoardCorner_x + kBoardSectionWidth, (float)kBoardCorner_y + kBoardMargin},
                {(float)kBoardCorner_x + kBoardSectionWidth, (float)kBoardCorner_y + kBoardHeight - kBoardMargin}, 1, LIGHTGRAY);
    
    DrawLineEx({(float)kBoardCorner_x + 2*kBoardSectionWidth, (float)kBoardCorner_y + kBoardMargin},
                {(float)kBoardCorner_x + 2*kBoardSectionWidth, (float)kBoardCorner_y + kBoardHeight - kBoardMargin}, 1, LIGHTGRAY);

    DrawText("Beginner",
            kBeginnerSectionTitleCorner_x,
            kBeginnerSectionTitleCorner_y,
            kBeginnerSectionTitleFontSize,
            BLACK);
    
    DrawText("Intermediate",
            kIntermediateSectionTitleCorner_x,
            kIntermediateSectionTitleCorner_y,
            kIntermediateSectionTitleFontSize,
            BLACK);
    
    DrawText("Expert",
            kExpertSectionTitleCorner_x,
            kExpertSectionTitleCorner_y,
            kExpertSectionTitleFontSize,
            BLACK);
    
    /* */
	DrawHighScoreSection(config->GetBeginnerHighScores(),
		kBeginnerSectionCorner_x, kBeginnerSectionCorner_y);
	DrawHighScoreSection(config->GetIntermediateHighScores(),
		kIntermediateSectionCorner_x, kIntermediateSectionCorner_y);
	DrawHighScoreSection(config->GetExpertHighScores(),
		kExpertSectionCorner_x, kExpertSectionCorner_y);
}

void LeaderboardScreen::DrawHighScoreSection(std::vector<int> scores, int x, int y) {
	for(int i=0;i<scores.size();i++) {
		DrawHighSCoreText(i+1, scores[i], x, y + 24*i);
	}
}

void LeaderboardScreen::DrawHighSCoreText(int index, int score, int x, int y) {
	std::string displayedScore;
	if(score >= Config::kInfiniteScore) {
		displayedScore = "---";
	} else displayedScore = std::to_string(score);
	displayedScore = std::to_string(index) + ". " + displayedScore;

	DrawText(displayedScore.c_str(), x, y, 20, BLACK);
}

LeaderboardScreen::LeaderboardScreen() {}

void LeaderboardScreen::SetConfig(Config *config) {
	this->config = config;
}

void LeaderboardScreen::SetIngame(bool _in_game) {
    in_game = _in_game;
}