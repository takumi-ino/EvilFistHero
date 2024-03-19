#include "../Manager/SceneManager/SceneManager.h"
#include "SceneTitle_SelectMenu.h"
#include "../SceneTitle/SceneTitle.h"
#include "../Button/DialogueButtons.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"


namespace {

	const int _MENU_ALLITEM_NUM = 3;
	const int _BG_X = 30;
	const int _BG_Y = 30;
}


struct SceneTitle_SelectMenu::SelectMenu selectItems[] =
{

{80,110,"ゲーム開始"},
{100,260,"ゲーム終了"},
{100,410,"もどる"}

};


SceneTitle_SelectMenu::SceneTitle_SelectMenu() {

	_backGroundImage_hdl = LoadGraph("graphics/TitleMenu.png");
}


void SceneTitle_SelectMenu::SelectMenuByInput() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {

		_menuIndex--;
		if (_menuIndex < 0) _menuIndex = _MENU_ALLITEM_NUM - 1;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {

		_menuIndex++;
		if (_menuIndex >= _MENU_ALLITEM_NUM) _menuIndex = 0;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		if (0 == _menuIndex) {

			// ステージマップで表示するシンボルを初期化
			[](DialogueButtons* sc) {

				sc = new DialogueButtons();
				sc->Instantiate_DialogueButton();
				delete sc;
				sc = nullptr;
				};

			// プロローグからスタートに設定し直す
			if (SceneConversation::Prologue_Epilogue != 0) {

				SceneConversation::Prologue_Epilogue = 0;
			}

			// プロローグへ
			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneConversation());
		}
		else if (1 == _menuIndex) {

			// ゲーム終了
			DxLib_End();
		}
		else if (2 == _menuIndex) {

			//　タイトルに戻る
			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneTitle());
		}
	}

	// 選択中の項目の座標を移動
	for (int i = 0; i < _MENU_ALLITEM_NUM; i++) {

		if (i == _menuIndex)
			selectItems[i].posX = 90;
		else
			selectItems[i].posX = 110;
	}
}


void SceneTitle_SelectMenu::ShowMenu() {

	DrawRotaGraph(300, 325, 1.0f, 0, _backGroundImage_hdl, true);

	for (int i = 0; i < _MENU_ALLITEM_NUM; i++) {

		DrawFormatString(
			selectItems[i].posX,
			selectItems[i].posY,
			GetColor(255, 255, 255),
			"・ %s", selectItems[i].name
		);
	}
}


void SceneTitle_SelectMenu::Render(const float deltaTime) {

	ShowMenu();

	SetFontSize(40);
	DrawString(1070, 640, "Enter", -1);
}


void SceneTitle_SelectMenu::Update(const float deltaTime) {

	SelectMenuByInput();
}


void SceneTitle_SelectMenu::ReleaseMem() {

	DeleteGraph(_backGroundImage_hdl);
}