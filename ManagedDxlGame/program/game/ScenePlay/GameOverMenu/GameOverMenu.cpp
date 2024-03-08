#include "GameOverMenu.h"
#include "../../Manager/SceneManager/SceneManager.h"
#include "../../Manager/SoundManager/SoundManager.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../ScenePlay/Battle/Scene_JankenBattle.h"
#include "../../SceneTitle/SceneTitle.h"
#include "../../../utility/DxLib_Engine.h"


struct GameOverMenu::MenuElement gameOverMenuItems[] = {

	{80,150,"���g���C"},
	{100,300,"�}�b�v�ɂ��ǂ�"},
	{100,450,"�^�C�g����ʂɂ��ǂ�"}
};


int GameOverMenu::gameOverMenuIndex;


void GameOverMenu::SelectGameOverMenu() {

	for (int i = 0; i < MENU_MAX_NUM; i++) {

		DrawFormatString(gameOverMenuItems[i].x, gameOverMenuItems[i].y, GetColor(255, 255, 255), "�E %s", gameOverMenuItems[i].name);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {
		gameOverMenuIndex = (gameOverMenuIndex + (MENU_MAX_NUM - 1)) % MENU_MAX_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {
		gameOverMenuIndex = (gameOverMenuIndex + 1) % MENU_MAX_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP) || tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {

		for (int i = 0; i < MENU_MAX_NUM; i++) {

			if (i == gameOverMenuIndex) 
				gameOverMenuItems[i].x = 90;
			else                      
				gameOverMenuItems[i].x = 110;
		}
	}
}



void GameOverMenu::BranchProcess_ByGameOverMenu() {

	switch (gameOverMenuIndex)
	{

	case GameOverMenu::MENU_RETRY:
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new Scene_JankenBattle(StageSymbol::episodeID));

			[](Scene_JankenBattle* j) {

				j = new Scene_JankenBattle();
				j->ResetGame();

				delete j;
				j = nullptr;
			};
		}
		break;
	}
	case RetryMenu::MENU_RETURNMAP:
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneStageMap());
		}
		break;
	}
	case RetryMenu::MENU_BACKTITLE:
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