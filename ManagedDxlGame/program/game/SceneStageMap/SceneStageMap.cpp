#include "SceneStageMap.h"
#include "../SceneTitle/SceneTitle.h"
#include "../ScenePlay/Battle/Scene_JankenBattle.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/ImageManager/use/ImageManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"


SceneStageMap::SceneStageMap() {

	_bossRef_ptr = new EnemyBoss();
	_symbolRef_ptr = new StageSymbol();
}


bool SceneStageMap::SeqIdle(float deltaTime) {

	if (_sequence.isStart()) {

		_bgImage_hdl = LoadGraph("graphics/WorldMap.png");

		SoundManager::GetInstance().LoadBGM("sound/BGM/WorldMap_BGM.mp3");

		SoundManager::GetInstance().PlayBGM();
	}

	return true;
}



void SceneStageMap::Update(float deltaTime) {

	_sequence.update(deltaTime);
}



void SceneStageMap::SetStageInfo_BeforeStartGame(const StageSymbol::Symbol symbol) {

	_bossRef_ptr->InitBossHP(symbol);

	Scene_JankenBattle::InitPlayerHP();

	if (symbol == StageSymbol::KINGDOM)
		ImageManager::GetInstance().Load_BackGroundImage("ステージ5");

	auto scene = SceneManager::GetInstance();
	scene->ChangeScene(new Scene_JankenBattle());
}



void SceneStageMap::GameStartByInput() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		switch (StageSymbol::_episodeID)
		{
		case StageSymbol::Symbol::FOREST:
		{
			SetStageInfo_BeforeStartGame(StageSymbol::Symbol::FOREST);
			break;
		}

		case StageSymbol::Symbol::VILLAGE:
		{
			SetStageInfo_BeforeStartGame(StageSymbol::Symbol::VILLAGE);
			break;
		}

		case StageSymbol::Symbol::CITY:
		{
			SetStageInfo_BeforeStartGame(StageSymbol::Symbol::CITY);
			break;
		}

		case StageSymbol::Symbol::THEOCRACY:
		{
			SetStageInfo_BeforeStartGame(StageSymbol::Symbol::THEOCRACY);
			break;
		}

		case StageSymbol::Symbol::KINGDOM:
		{
			// エピローグからスタート
			SceneConversation::Prologue_Epilogue = 1;

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneConversation());
			break;
		}

		case StageSymbol::Symbol::CONTINENT:
		{
			SetStageInfo_BeforeStartGame(StageSymbol::Symbol::CONTINENT);
			break;
		}

		default:
			break;
		}
	}
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_BACK)) {

		_symbolRef_ptr->_onSelectedSymbol = false;
	}
}



void SceneStageMap::ShowFinalCheck_BeforeStartGame() {

	if (!_symbolRef_ptr->_onSelectedSymbol) {

		_symbolRef_ptr->RenderSymbolMark();
	}
	else {

		SetFontSize(55);
		// エピソードタイトル表示
		DrawStringEx(_EPISODE_TITLE_POS_X, _EPISODE_TITLE_POS_Y, -1, StageSymbol::_EPISODE_TITLE);

		SetFontSize(50);
		DrawStringEx(350, 400, -1, "はじめる：Enter");
		DrawStringEx(350, 450, -1, "もどる：BackSpace");

		GameStartByInput();
	}
}



void SceneStageMap::Render(float deltaTime) {

	SetDrawBright(255, 255, 255);

	DrawRotaGraph(_BG_IMAGE_POS_X, _BG_IMAGE_POS_Y, _BG_EXRATE, 0, _bgImage_hdl, true);

	ShowFinalCheck_BeforeStartGame();
}


void SceneStageMap::ReleaseMem() {

	delete _bossRef_ptr;
	_bossRef_ptr = nullptr;

	delete _symbolRef_ptr;
	_symbolRef_ptr = nullptr;
}