#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "ScenePlay.h"
#include "../Boss/EnemyBoss.h"
#include "../../SceneStageMap/Symbol/SymbolOfStageMap.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "../../Manager/SceneManager/SceneManager.h"
#include "../../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include "../../Manager/SoundManager/SoundManager.h"
#include "../GameOverMenu/GameOverMenu.h"
#include "../Slider/SliderEvent.h"
#include "../Hand/Hand.h"


int ScenePlay::_playerHP = 0;


namespace {

	// ゲームリセット時に使用する const 変数群
	const bool IS_BATTLE_START = true;
	const bool IS_SLIDER_CHALLENGE = false;
	const bool IS_MOVING_SLIDER = false;
	const bool IS_SELECT_MYHAND = false;
	const bool CAN_SUBTRACT_HP = false;
	const bool IS_SHOW_RESULT = false;

	bool isBattleStart = IS_BATTLE_START;
	bool isSliderChallenge = IS_SLIDER_CHALLENGE;
	bool isMovingSlider = IS_MOVING_SLIDER;
	bool isSelectMyHand = IS_SELECT_MYHAND;
	bool canSubtractHP = CAN_SUBTRACT_HP;
	bool isShowResult = IS_SHOW_RESULT;

	const char* _stageBGM_path[SYMBOL_ALLNUM] =
	{
	"sound/BGM/EP1_BattleBGM.mp3",
	"sound/BGM/EP2_BattleBGM.mp3",
	"sound/BGM/EP3_BattleBGM.mp3",
	"sound/BGM/EP4_BattleBGM.mp3",
	"sound/BGM/EP5_BattleBGM.mp3",
	"sound/BGM/EP6_BattleBGM.mp3",
	};
}


ScenePlay::ScenePlay() {

	_boss = new EnemyBoss(SymbolOfStageMap::_episodeID);
	_sliderRef = new SliderEvent();
	_handRef = new Hand();

	LoadBattleBGM();
}


void ScenePlay::LoadBattleBGM() {

	switch (SymbolOfStageMap::_episodeID)
	{
	case SymbolOfStageMap::FOREST: // ステージ１

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::FOREST - 1]);
		break;
	case SymbolOfStageMap::VILLAGE: // ステージ２

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::VILLAGE - 1]);
		break;
	case SymbolOfStageMap::CITY: // ステージ３

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::CITY - 1]);
		break;
	case SymbolOfStageMap::THEOCRACY: // ステージ４

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::THEOCRACY - 1]);
		break;
	case SymbolOfStageMap::KINGDOM: // ステージ５

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::KINGDOM - 1]);
		break;
	case SymbolOfStageMap::CONTINENT: // ステージ６

		SoundManager::GetInstance().LoadBGM(
			_stageBGM_path[SymbolOfStageMap::CONTINENT - 1]);
		break;
	}
}



bool ScenePlay::SeqCheckPlayBGM(float deltaTime) {

	if (_sequence.isStart()) {

		SoundManager::GetInstance().PlayBGM();
	}

	if (_CURRENT_STATE == GameState::WIN) {

		SoundManager::GetInstance().StopBGM();
	}

	return true;
}



void ScenePlay::InitPlayerHP() {

	switch (SymbolOfStageMap::_episodeID)
	{
	case SymbolOfStageMap::FOREST:    // ステージ１

		_playerHP = 6;
		break;
	case SymbolOfStageMap::VILLAGE:   // ステージ２

		_playerHP = 5;
		break;
	case SymbolOfStageMap::CITY:      // ステージ３

		_playerHP = 4;
		break;
	case SymbolOfStageMap::THEOCRACY: // ステージ４

		_playerHP = 3;
		break;
	case SymbolOfStageMap::KINGDOM:   // ステージ５

		_playerHP = 2;
		break;
	case SymbolOfStageMap::CONTINENT: // ステージ６

		_playerHP = 1;
		break;
	}
}



void ScenePlay::RenderPlayerHP() {

	SetFontSize(30);
	DrawFormatString(50, 688, 0xFFFF0000, "PlayerHP:%d", _playerHP);
}



void ScenePlay::RenderBattleStartIntroText() {

	SetFontSize(90);
	DrawFormatString(360, 250, -1, "Battle Start!");
}



void ScenePlay::RenderPlayersJankenResult() {

	DrawRotaGraphF(
		Hand::RESULT_PLAYER_HAND_POS.x - 30,
		Hand::RESULT_PLAYER_HAND_POS.y - 15,
		0.5f,
		0,
		Hand::_gpc_handImageHandle[Hand::_playerHandIndex], 
		true
	);

	DrawStringEx(
		Hand::RESULT_PLAYER_HAND_POS.x - 50,
		Hand::RESULT_PLAYER_HAND_POS.y + 50, 
		-1, 
		"PLAYER"
	);
}



void ScenePlay::ResetGame() {

	isBattleStart = IS_BATTLE_START;
	isSliderChallenge = IS_SLIDER_CHALLENGE;
	isMovingSlider = IS_MOVING_SLIDER;
	isSelectMyHand = IS_SELECT_MYHAND;
	canSubtractHP = CAN_SUBTRACT_HP;
	isShowResult = IS_SHOW_RESULT;
}



ScenePlay::GameState ScenePlay::CheckIsOverJankenBattle(const int playerHP, const int bossHP) {

	if (playerHP != 0 && bossHP == 0) {

		return GameState::WIN;
	}
	if (playerHP == 0 && bossHP != 0) {

		return GameState::LOSE;
	}

	return GameState::PLAY;
}



void ScenePlay::ResetAllWhenGameStart() {

	if (_sliderRef == nullptr) {

		_sliderRef = new SliderEvent();
	}

	if (_boss == nullptr) {

		_boss = new EnemyBoss(SymbolOfStageMap::_episodeID);
		_boss->InitBossHP(SymbolOfStageMap::_episodeID);
	}

	if (_handRef == nullptr) {

		_handRef = new Hand();
		_handRef->LoadAllHandHandle();
	}

	InitPlayerHP();

	// ゲーム開始時、最初の1回だけ表示したい文字列の制御
	RenderBattleStartIntroText();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		isSliderChallenge = true;
		isBattleStart = false;

		_CURRENT_STATE = GameState::PLAY;
	}
}



void ScenePlay::ManageGamePlayStateBools() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		// スライダーイベント開始ターン（まだ開始していない）
		if (isSliderChallenge) {

			isMovingSlider = true;
			isSliderChallenge = false;
		}
		// スライダーイベント開始
		else if (isMovingSlider) {

			isSelectMyHand = true;
			isMovingSlider = false;
		}
		// 自分の手を選んだか
		else if (isSelectMyHand) {

			// HPが０でない場合HPを1つ減らし、falseへ戻す
			if (canSubtractHP) {

				canSubtractHP = false;
			}

			isShowResult = true;
			isSelectMyHand = false;
		}
		// リザルト表示中か
		else if (isShowResult) {

			Hand::_canSelectBossHand = true;

			canSubtractHP = true;
			isSliderChallenge = true;
			isShowResult = false;
		}
	}
}


void ScenePlay::UpdateGamePlayState(const float deltaTime) {

	//　スライダーイベント開始前
	if (isSliderChallenge && !isMovingSlider) {

		_sliderRef->SliderFuncUpdate_PerFrame(
			deltaTime, 
			SymbolOfStageMap::_episodeID,
			EnemyBoss::_bossHP
		);
	}

	//　スライダーイベント終了
	if (isMovingSlider && !isSelectMyHand) {

		// グー、チョキ、パーの出す確率を毎回変える
		_boss->ShuffleBossHandProbabilityTable();
		_sliderRef->ShowSliderGrade();
	}

	//　プレイヤーの手の選択
	if (isSelectMyHand) {

		RenderPlayerHP();
		// 敵が手を選択
		if (Hand::_canSelectBossHand) {

			Hand::_bossSelectedHand = rand() % Hand::HAND_TYPE_MAX;
			Hand::_canSelectBossHand = false;
		}

		_boss->RenderBossEnemy(SymbolOfStageMap::_episodeID);
		_boss->RenderBossHP();
		_boss->RenderBossHandProb(_sliderRef);

		_handRef->UpdateSelectHandCursorPos();
	}

	//　選択後の結果
	if (isShowResult) {

		_handRef->RenderJankenResultImage();
		_handRef->RenderJankenResultText(_playerHP, EnemyBoss::_bossHP);
	}
}


void ScenePlay::ExecuteBattleStateLogic(const float deltaTime) {

	// まだ勝敗がついていなければ
	if (_CURRENT_STATE != GameState::WIN) {

		switch (_CURRENT_STATE)
		{
		case ScenePlay::GameState::START:
		{
			// 全て初期化
			ResetAllWhenGameStart();
		}
		break;
		case ScenePlay::GameState::PLAY:
		{
			// bool 変数を制御
			ManageGamePlayStateBools();

			// bool 変数制御の結果を実行
			UpdateGamePlayState(deltaTime);

			if (canSubtractHP) {

				_handRef->SubtractLosersHP(_playerHP, EnemyBoss::_bossHP);

				// HPの結果によってゲームクリア、ゲームオーバー、ゲーム続行かが決まる
				_CURRENT_STATE = CheckIsOverJankenBattle(_playerHP, EnemyBoss::_bossHP);

				if (_CURRENT_STATE == GameState::WIN) goto WIN;

				canSubtractHP = false;
			}
		}
		break;
		// 負け
		case ScenePlay::GameState::LOSE:
		{
			GameOverMenu::SelectGameOverMenu();
			GameOverMenu::BranchProcess_ByGameOverMenu();
		}

		break;
		// 勝ち
		case ScenePlay::GameState::WIN:
		{
		WIN:
			ResetGame();

			std::this_thread::sleep_for(std::chrono::milliseconds(300));

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneStageMap());
		}
		break;
		}
	}
}



void ScenePlay::Update(const float deltaTime) {

	SetDrawBright(255, 255, 255);

	_sequence.update(deltaTime);

	_boss->RenderBackGround(SymbolOfStageMap::_episodeID);

	ExecuteBattleStateLogic(deltaTime);
}



void ScenePlay::ReleaseMem() {

	delete _sliderRef;
	_sliderRef = nullptr;
	
	delete _boss;
	_boss = nullptr;
	
	delete _handRef;
	_handRef = nullptr;
}