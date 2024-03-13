#pragma once
#include "../../Manager/SceneManager/SceneBase.h"


constexpr static int SYMBOL_ALLNUM = 6;

class Hand;
class EnemyBoss;
class SliderEvent;
class SceneStageMap;
class StageSymbol;

class Scene_JankenBattle : public SceneBase
{
public:

	enum class GameState {

		START, // ゲーム開始
		PLAY,  // ゲームプレイ中
		LOSE,  // ゲームオーバーメニューを開く
		WIN    // マップへ戻る
	};

	// コンストラクタ------------------------------------------------------------

	Scene_JankenBattle();
	Scene_JankenBattle(const int) {}

	// ------------------------------------------------------------

	void Update(float deltaTime) override;
	void ReleaseMem() override;

	// ------------------------------------------------------------

	void ResetGame();
	static void InitPlayerHP();

private:

	void LoadBattleBGM(); // 1回だけ実行

	// ゲーム開始時に実行する処理をまとめた関数
	void GameStart_FirstTransaction();

	// ゲームロジック全体を管理する関数
	void ExecuteLogic_ByBattleState(float deltaTime);

	// ExecuteLogicByBattleState を複数のBool変数で制御。全てエンターキーで処理
	void ChangeGameStateByBools();

	// 1勝負ごとの結果を返す。続行、勝利、敗北のいずれかである
	Scene_JankenBattle::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);

	// 描画----------------------------------------------------------------------------------------------------

	void RenderPlayerHP();
	void RenderJankenResult_Player();
	void RenderIntroText_BattleStart();	// ゲーム開始直後１回だけ表示、次ターンからは表示しない

private:

	bool SeqCheckPlayBGMOrNot(float delta_time); // バトル開始時、バトル終了時を判定し、BGMを制御する
	tnl::Sequence<Scene_JankenBattle> _sequence = tnl::Sequence<Scene_JankenBattle>(this, &Scene_JankenBattle::SeqCheckPlayBGMOrNot);

private:

	EnemyBoss*   _bossRef_ptr = nullptr;
	SliderEvent* _sliderRef_ptr = nullptr;
	Hand*        _handRef_ptr = nullptr;

private:

	GameState    _CURRENT_STATE = GameState::START;

	// プレイヤーというクラスがないのでHPはここで管理
	static int   _playerHP;
};