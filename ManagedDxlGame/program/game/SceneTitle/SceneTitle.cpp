#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "SceneTitle.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../SceneTitle_SelectMenu/SceneTitle_SelectMenu.h"


namespace {

	const int _LOGO_X = 630;
	const int _LOGO_Y = 170;
	const int _BG_X = 30;
	const int _BG_Y = 30;
}


SceneTitle::SceneTitle() {

	_backGroundImage_hdl = LoadGraph("graphics/Title.png");
	_logoImage_hdl = LoadGraph("graphics/TitleLogo.png");

	SoundManager::GetInstance().LoadBGM("sound/BGM/Title_BGM.mp3");
	SoundManager::GetInstance().PlayBGM();
}


void SceneTitle::Render(const float deltaTime) {

	DrawRotaGraph(_BG_X, _BG_Y, 0.8f, 0, _backGroundImage_hdl, true);

	DrawRotaGraph(_LOGO_X, _LOGO_Y, 2.0f, 0, _logoImage_hdl, true);

	SetFontSize(55);
	DrawFormatString(430, 600, -1, "Enter to Start");
}


void SceneTitle::Update(const float deltaTime) {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneTitle_SelectMenu());
	}
}


void SceneTitle::ReleaseMem() {

	DeleteGraph(_backGroundImage_hdl);
	DeleteGraph(_logoImage_hdl);
}