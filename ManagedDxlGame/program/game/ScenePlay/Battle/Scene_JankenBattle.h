#pragma once
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "../../SceneStageMap/Symbol/StageSymbol.h"
#include "../Hand/Hand.h"
#include "../Boss/EnemyBoss.h"
#include "../Slider/SliderEvent.h"
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"

constexpr static int SYMBOL_ALLNUM = 6;

class Hand;

class Scene_JankenBattle : public SceneBase
{
public:

	enum class GameState {

		START, // ゲーム開始
		PLAY,  // ゲームプレイ中
		LOSE,  // ゲームオーバーメニューを開く
		WIN    // マップへ戻る
	};

	Scene_JankenBattle();
	Scene_JankenBattle(const int) {}

	void Update(float deltaTime) override;
	void ReleaseMem() override;
	void ResetGame();

	static void InitPlayerHP();

private:

	// ゲーム開始直後１回だけ表示、次ターンからは表示しない
	void RenderIntroText_BattleStart();

	// ゲーム開始時にする処理をまとめた関数
	void GameState_StartLogic();

	// ゲームロジック全体を管理する関数
	void ExecuteLogic_ByBattleState(float deltaTime);

	// ExecuteLogicByBattleState 関数を複数のBool変数で制御。全てエンターキーで処理
	void ChangeGameStateByBools();

	void RenderPlayerHP();

	void RenderJankenResult_Player();

	// 1勝負ごとの結果を返す。続行、勝利、敗北のいずれかである
	Scene_JankenBattle::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);

private:

	GameState    CURRENT_STATE = GameState::START;

	EnemyBoss*   _bossRef_ptr = nullptr;
	SliderEvent* _sliderRef_ptr = nullptr;
	Hand*        _handRef_ptr = nullptr;

	tnl::Sequence<Scene_JankenBattle> _sequence = tnl::Sequence<Scene_JankenBattle>(this, &Scene_JankenBattle::SeqLoadMem);
	bool SeqLoadMem(float delta_time);

public:

	static int   _playerHP;

private:

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
};