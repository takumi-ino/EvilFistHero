#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "SceneStageMap.h"
#include "../ScenePlay/Boss/EnemyBoss.h"
#include "../ScenePlay/Battle/ScenePlay.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"


namespace {

	// エピソードタイトルの座標
	const int    _EPISODE_TITLE_POS_X = 395;
	const int    _EPISODE_TITLE_POS_Y = 175;

	// 背景画像の座標
	const int    _BG_IMAGE_POS_X = 640;
	const int    _BG_IMAGE_POS_Y = 360;
	const double _BG_EXRATE = 0.47;
}


SceneStageMap::SceneStageMap() {

	_symbolOfStageMap = new SymbolOfStageMap();
}


bool SceneStageMap::SeqIdle(float deltaTime) {

	if (_sequence.isStart()) {

		_backGroundImage_hdl = LoadGraph("graphics/WorldMap.png");

		SoundManager::GetInstance().LoadBGM("sound/BGM/WorldMap_BGM.mp3");
		SoundManager::GetInstance().PlayBGM();
	}

	return true;
}



void SceneStageMap::ResetHP_BeforeStartGame(const SymbolOfStageMap::TYPE symbol) {

	//　ボスHP初期化処理
	EnemyBoss* boss = new EnemyBoss();
	boss->InitBossHP(symbol);                  
	delete boss;
	boss = nullptr;

	//　プレイヤーHP初期化
	ScenePlay::InitPlayerHP();
}


void SceneStageMap::GameStartByInput() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		SoundManager::GetInstance().StopBGM();            // BGM停止

		switch (SymbolOfStageMap::_episodeID)
		{
		case SymbolOfStageMap::TYPE::FOREST:
		{
			ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::FOREST);
			MoveToScenePlay();
			break;
		}

		case SymbolOfStageMap::TYPE::VILLAGE:
		{
			ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::VILLAGE);
			MoveToScenePlay();
			break;
		}

		case SymbolOfStageMap::TYPE::CITY:
		{
			ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::CITY);
			MoveToScenePlay();
			break;
		}

		case SymbolOfStageMap::TYPE::THEOCRACY:
		{
			ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::THEOCRACY);
			MoveToScenePlay();
			break;
		}

		case SymbolOfStageMap::TYPE::KINGDOM:
		{
			// エピローグからスタート
			SceneConversation::Prologue_Epilogue = 1;

			MoveToScenePlay();
			break;
		}
		case SymbolOfStageMap::TYPE::CONTINENT:
		{
			ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::CONTINENT);
			MoveToScenePlay();
			break;
		}
		}
	}
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_BACK)) {

		_symbolOfStageMap->_onSelectedSymbol = false;
	}
}


void SceneStageMap::MoveToScenePlay()
{
	auto scene = SceneManager::GetInstance();
	scene->ChangeScene(new ScenePlay());
}


void SceneStageMap::ShowFinalCheck_BeforeStartGame() {

	if (!_symbolOfStageMap->_onSelectedSymbol) {

		_symbolOfStageMap->RenderSymbolMark();
	}
	else {

		SetFontSize(55);
		// エピソードタイトル表示
		DrawString(
			_EPISODE_TITLE_POS_X,
			_EPISODE_TITLE_POS_Y, 
			SymbolOfStageMap::_EPISODE_TITLE,
			-1
		);

		SetFontSize(50);
		DrawStringEx(350, 400, -1, "はじめる：Enter");
		DrawStringEx(350, 450, -1, "もどる：BackSpace");

		// エンターでゲームスタート！
		GameStartByInput();
	}
}


void SceneStageMap::Render(const float deltaTime) {

	SetDrawBright(255, 255, 255);

	DrawRotaGraph(
		_BG_IMAGE_POS_X,
		_BG_IMAGE_POS_Y,
		_BG_EXRATE,
		0,
		_backGroundImage_hdl,
		true
	);

	ShowFinalCheck_BeforeStartGame();
}


void SceneStageMap::Update(const float deltaTime) {

	_sequence.update(deltaTime);
}


void SceneStageMap::ReleaseMem() {

	delete _symbolOfStageMap;
	_symbolOfStageMap = nullptr;
}