#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "Scene_JankenBattle.h"
#include "../Boss/EnemyBoss.h"
#include "../../SceneStageMap/Symbol/StageSymbol.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "../../Manager/SceneManager/SceneManager.h"
#include "../../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include "../../Manager/SoundManager/SoundManager.h"
#include "../GameOverMenu/GameOverMenu.h"
#include "../Slider/SliderEvent.h"
#include "../Hand/Hand.h"


int Scene_JankenBattle::_playerHP = 0;


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


Scene_JankenBattle::Scene_JankenBattle() {

	_bossRef_ptr = new EnemyBoss(StageSymbol::_episodeID);
	_sliderRef_ptr = new SliderEvent();
	_handRef_ptr = new Hand();

	LoadBattleBGM();
}


void Scene_JankenBattle::LoadBattleBGM() {

	switch (StageSymbol::_episodeID)
	{
	case StageSymbol::FOREST:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::FOREST - 1]);
		break;
	case StageSymbol::VILLAGE:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::VILLAGE - 1]);
		break;
	case StageSymbol::CITY:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::CITY - 1]);
		break;
	case StageSymbol::THEOCRACY:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::THEOCRACY - 1]);
		break;
	case StageSymbol::KINGDOM:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::KINGDOM - 1]);
		break;
	case StageSymbol::CONTINENT:

		SoundManager::GetInstance().LoadBGM(_stageBGM_path[StageSymbol::CONTINENT - 1]);
		break;
	}
}



bool Scene_JankenBattle::SeqCheckPlayBGMOrNot(float delta_time) {

	if (_sequence.isStart()) {

		SoundManager::GetInstance().PlayBGM();
	}

	if (_CURRENT_STATE == GameState::WIN) {

		SoundManager::GetInstance().StopBGM();
	}

	return true;
}



void Scene_JankenBattle::InitPlayerHP() {

	switch (StageSymbol::_episodeID)
	{
	case StageSymbol::FOREST:

		_playerHP = 6;
		break;
	case StageSymbol::VILLAGE:

		_playerHP = 5;
		break;
	case StageSymbol::CITY:

		_playerHP = 4;
		break;
	case StageSymbol::THEOCRACY:

		_playerHP = 3;
		break;
	case StageSymbol::KINGDOM:

		_playerHP = 2;
		break;
	case StageSymbol::CONTINENT:

		_playerHP = 1;
		break;
	}
}



void Scene_JankenBattle::RenderPlayerHP() {

	SetFontSize(30);
	DrawFormatString(50, 688, 0xFFFF0000, "PlayerHP:%d", _playerHP);
}



void Scene_JankenBattle::RenderIntroText_BattleStart() {

	SetFontSize(90);
	DrawFormatString(360, 250, -1, "Battle Start!");
}



void Scene_JankenBattle::RenderJankenResult_Player() {

	DrawRotaGraphF(
		Hand::RESULT_PLAYER_HAND_POS.x - 30,
		Hand::RESULT_PLAYER_HAND_POS.y - 15,
		0.5f, 0,
		Hand::_gpc_hand_hdl[Hand::_playerHandIndex], true
	);

	DrawStringEx(
		Hand::RESULT_PLAYER_HAND_POS.x - 50,
		Hand::RESULT_PLAYER_HAND_POS.y + 50, -1, "PLAYER"
	);
}



void Scene_JankenBattle::ResetGame() {

	isBattleStart = IS_BATTLE_START;
	isSliderChallenge = IS_SLIDER_CHALLENGE;
	isMovingSlider = IS_MOVING_SLIDER;
	isSelectMyHand = IS_SELECT_MYHAND;
	canSubtractHP = CAN_SUBTRACT_HP;
	isShowResult = IS_SHOW_RESULT;
}



Scene_JankenBattle::GameState Scene_JankenBattle::CheckIsOverJankenBattle(const int playerHP, const int bossHP) {

	if (playerHP != 0 && bossHP == 0) {

		return GameState::WIN;
	}
	if (playerHP == 0 && bossHP != 0) {

		return GameState::LOSE;
	}

	return GameState::PLAY;
}



void Scene_JankenBattle::GameStart_FirstTransaction() {

	if (_sliderRef_ptr == nullptr) {

		_sliderRef_ptr = new SliderEvent();
	}

	if (_bossRef_ptr == nullptr) {

		_bossRef_ptr = new EnemyBoss(StageSymbol::_episodeID);
		_bossRef_ptr->InitBossHP(StageSymbol::_episodeID);
	}

	if (_handRef_ptr == nullptr) {

		_handRef_ptr = new Hand();
		_handRef_ptr->LoadAllHandHandle();
	}

	InitPlayerHP();

	// ゲーム開始時、最初の1回だけ表示したい文字列の制御
	RenderIntroText_BattleStart();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		isSliderChallenge = true;
		isBattleStart = false;

		_CURRENT_STATE = GameState::PLAY;
	}
}



void Scene_JankenBattle::ChangeGameStateByBools() {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		if (isSliderChallenge) {

			isMovingSlider = true;
			isSliderChallenge = false;
		}
		else if (isMovingSlider) {

			isSelectMyHand = true;
			isMovingSlider = false;
		}
		else if (isSelectMyHand) {

			if (canSubtractHP) {

				canSubtractHP = false;
			}

			isShowResult = true;
			isSelectMyHand = false;
		}
		else if (isShowResult) {

			Hand::_canSelectBossHand = true;

			canSubtractHP = true;
			isSliderChallenge = true;
			isShowResult = false;
		}
	}
}



void Scene_JankenBattle::ExecuteLogic_ByBattleState(float deltaTime) {

	if (_CURRENT_STATE != GameState::WIN) {

		switch (_CURRENT_STATE)
		{
		case Scene_JankenBattle::GameState::START:
		{
			GameStart_FirstTransaction();
		}
		break;
		case Scene_JankenBattle::GameState::PLAY:
		{				
			ChangeGameStateByBools();

			if (isSliderChallenge && !isMovingSlider) {

				_sliderRef_ptr->SliderFuncUpdate_PerFrame(deltaTime, StageSymbol::_episodeID, EnemyBoss::bossHP);
			}

			if (isMovingSlider && !isSelectMyHand) {

				// グー、チョキ、パーの出す確率を毎回変える
				_bossRef_ptr->Shuffle_BossHandProbTable();
				_sliderRef_ptr->ShowSliderGrade();
			}

			if (isSelectMyHand) {

				RenderPlayerHP();
				// 敵が手を選択
				if (Hand::_canSelectBossHand) {

					Hand::_bossSelectedHand = rand() % Hand::HAND_TYPE_MAX;
					Hand::_canSelectBossHand = false;
				}

				_bossRef_ptr->RenderBossEnemy(StageSymbol::_episodeID);
				_bossRef_ptr->RenderBossHP();
				_bossRef_ptr->RenderBossHandProb(_sliderRef_ptr);

				_handRef_ptr->SelectMyHand_UpdateCursorPos();
			}


			if (isShowResult) {

				_handRef_ptr->RenderJankenResultImage();
				_handRef_ptr->RenderJankenResultText(_playerHP, EnemyBoss::bossHP);
			}


			if (canSubtractHP) {

				_handRef_ptr->SubtractLosersHP(_playerHP, EnemyBoss::bossHP);

				// HPの結果によってゲームクリア、ゲームオーバー、ゲーム続行かが決まる
				_CURRENT_STATE = CheckIsOverJankenBattle(_playerHP, EnemyBoss::bossHP);

				if (_CURRENT_STATE == GameState::WIN) goto WIN;

				canSubtractHP = false;
			}
		}
		break;
		case Scene_JankenBattle::GameState::LOSE:
		{
			GameOverMenu::SelectGameOverMenu();
			GameOverMenu::BranchProcess_ByGameOverMenu();
		}

		break;
		case Scene_JankenBattle::GameState::WIN:
		{
		WIN:
			ResetGame();

			std::this_thread::sleep_for(std::chrono::milliseconds(300));

			auto scene = SceneManager::GetInstance();
			scene->ChangeScene(new SceneStageMap());
		}
		break;
		default:
			break;
		}
	}
}



void Scene_JankenBattle::Update(float deltaTime) {

	SetDrawBright(255, 255, 255);

	_sequence.update(deltaTime);

	_bossRef_ptr->RenderBackGround(StageSymbol::_episodeID);

	ExecuteLogic_ByBattleState(deltaTime);
}



void Scene_JankenBattle::ReleaseMem() {

	delete _sliderRef_ptr;
	_sliderRef_ptr = nullptr;
	
	delete _bossRef_ptr;
	_bossRef_ptr = nullptr;
	
	delete _handRef_ptr;
	_handRef_ptr = nullptr;
}