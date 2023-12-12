#include "SceneTitle.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../SceneTitle_SelectMenu/SceneTitle_SelectMenu.h"


bool SceneTitle::SeqIdle(float deltaTime) {

	if (_sequence.isStart()) {

		SoundManager::GetInstance().LoadBGM("sound/BGM/Title_BGM.mp3");

		_bgImage_hdl = LoadGraph("graphics/Title.png");
		_logoImage_hdl = LoadGraph("graphics/TitleLogo.png");

		SoundManager::GetInstance().PlayBGM();
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneTitle_SelectMenu());
	}

	return true;	
}


void SceneTitle::Update(float deltaTime) {

	_sequence.update(deltaTime);
}


void SceneTitle::Render(float deltaTime) {

	DrawRotaGraph(_BG_X, _BG_Y, 0.8f, 0, _bgImage_hdl, true);   // îwåi

	DrawRotaGraph(_LOGO_X, _LOGO_Y, 2.0f, 0, _logoImage_hdl, true);// ÉçÉS

	SetFontSize(55);
	DrawFormatString(440, 600, -1, "Enter to Start");
}


void SceneTitle::ReleaseMem() {

	DeleteGraph(_bgImage_hdl);
	DeleteGraph(_logoImage_hdl);
}