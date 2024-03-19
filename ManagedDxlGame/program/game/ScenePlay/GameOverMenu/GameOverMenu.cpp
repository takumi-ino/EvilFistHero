#include "GameOverMenu.h"
#include "../../Manager/SceneManager/SceneManager.h"
#include "../../Manager/SoundManager/SoundManager.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../ScenePlay/Battle/ScenePlay.h"
#include "../../SceneTitle/SceneTitle.h"
#include "../../../utility/DxLib_Engine.h"


struct GameOverMenu::MenuElement gameOverMenuItems[] = {

	{80,150,"リトライ"},
	{100,300,"マップにもどる"},
	{100,450,"タイトル画面にもどる"}
};


int GameOverMenu::gameOverMenuIndex;


void GameOverMenu::SelectGameOverMenu() {

	for (int i = 0; i < (int)GameOverMenu::NEXT::MAX_NUM; i++) {

		DrawFormatString(gameOverMenuItems[i].x, gameOverMenuItems[i].y, GetColor(255, 255, 255), "・ %s", gameOverMenuItems[i].name);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {
		gameOverMenuIndex = (gameOverMenuIndex + ((int)GameOverMenu::NEXT::MAX_NUM - 1)) % (int)GameOverMenu::NEXT::MAX_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {
		gameOverMenuIndex = (gameOverMenuIndex + 1) % (int)GameOverMenu::NEXT::MAX_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP) || tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {

		for (int i = 0; i < (int)GameOverMenu::NEXT::MAX_NUM; i++) {

			if (i == gameOverMenuIndex) 
				gameOverMenuItems[i].x = 90;
			else                      
				gameOverMenuItems[i].x = 110;
		}
	}
}



void GameOverMenu::BranchProcess_ByGameOverMenu() {

	switch (static_cast<GameOverMenu::NEXT>(gameOverMenuIndex))
	{

	case GameOverMenu::NEXT::RETRY:
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new ScenePlay(SymbolOfStageMap::_episodeID));

			[](ScenePlay* j) {

				j = new ScenePlay();
				j->ResetGame();

				delete j;
				j = nullptr;
			};
		}
		break;
	}
	case GameOverMenu::NEXT::RETURNMAP:
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneStageMap());
		}
		break;
	}
	case  GameOverMenu::NEXT::BACKTITLE:
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneTitle());
		}
		break;
	}
	}
}