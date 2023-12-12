#include "SceneTitle_SelectMenu.h"
#include "../SceneTitle/SceneTitle.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../Button/DialogueButtons.h"



struct SceneTitle_SelectMenu::SelectMenu selectItems[] = {

{80,110,"�Q�[���J�n"},
{100,260,"�Q�[���I��"},
{100,410,"���ǂ�"}

};



bool SceneTitle_SelectMenu::SeqIdle(float deltaTime) {

	if (_sequence.isStart()) {

		_bgImage_hdl = LoadGraph("graphics/TitleMenu.png");
	}

	return true;
}



void SceneTitle_SelectMenu::SelectMenuByInput() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) {
		_menu_index = (_menu_index + (_MENU_ALLITEM_NUM - 1)) % _MENU_ALLITEM_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) {
		_menu_index = (_menu_index + 1) % _MENU_ALLITEM_NUM;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		if (0 == _menu_index) {

			// �X�e�[�W�}�b�v�ŕ\������V���{����������
			[](DialogueButtons* sc) {

				sc = new DialogueButtons();
				sc->Instantiate_DialogueButton();
				delete sc;
				sc = nullptr;
			};

			if(SceneConversation::Prologue_Epilogue != 0)  SceneConversation::Prologue_Epilogue = 0;

			// �v�����[�O��
			SoundManager::GetInstance().StopBGM();

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneConversation());
		}
		else if (1 == _menu_index) {

			DxLib_End();
		}
		else if (2 == _menu_index) {

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneTitle());
		}
	}

	// �I�𒆂̍��ڂ̍��W���ړ�
	for (int i = 0; i < _MENU_ALLITEM_NUM; i++) {

		if (i == _menu_index) 	selectItems[i].menu_x = 90;
		else 	                selectItems[i].menu_x = 110;
	}
}



void SceneTitle_SelectMenu::ShowMenu() {

	DrawRotaGraph(300, 325, 1.0f, 0, _bgImage_hdl, true);
}


void SceneTitle_SelectMenu::Update(float deltaTime) {

	SelectMenuByInput();
	_sequence.update(deltaTime);
}


void SceneTitle_SelectMenu::Render(float deltaTime) {

	ShowMenu();

	for (int i = 0; i < _MENU_ALLITEM_NUM; i++) {

		DrawFormatString(
			selectItems[i].menu_x, 
			selectItems[i].menu_y, 
			GetColor(255, 255, 255), 
			"�E %s", selectItems[i].menu_name);
	}

	SetFontSize(40);
	DrawString(1070, 640, "Enter", -1);
}


void SceneTitle_SelectMenu::ReleaseMem() {

	DeleteGraph(_bgImage_hdl);
}