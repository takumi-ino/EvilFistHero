#pragma once
#include "../../Manager/SceneManager/SceneBase.h"


constexpr static int SYMBOL_ALLNUM = 6;

class Hand;
class EnemyBoss;
class SliderEvent;
class SceneStageMap;
class SymbolOfStageMap;


// インゲーム。（　SceneStageMapの次　）
class ScenePlay : public SceneBase
{
public:

	enum class GameState {

		START, // ゲーム開始
		PLAY,  // ゲームプレイ中
		LOSE,  // ゲームオーバーメニューを開く
		WIN    // マップへ戻る
	};

	// コンストラクタ------------------------------------------------------------

	ScenePlay();
	ScenePlay(const int) {}

	// ------------------------------------------------------------

	void Update(const float deltaTime) override;
	void ReleaseMem() override;

	// ------------------------------------------------------------

	void ResetGame();
	static void InitPlayerHP();

private:

	void LoadBattleBGM(); // BGM初期化　1回だけ実行

	// ゲーム開始時に実行する初期化
	void ResetAllWhenGameStart();


	// enum class GameState を使用した処理-----------------------------------------------------------

	// GameStateの　START～WIN　までの全ての流れを管理
	void ExecuteBattleStateLogic(const float deltaTime);

	// GameState::Play 時の各処理を制御するBool変数を一括管理
	void ManageGamePlayStateBools(); // ※　GameState::Play は処理がかなり複雑なためBool変数を複数使用

	// ManageGamePlayStateBools 関数内の判定結果を実行する
	void UpdateGamePlayState(const float deltaTime);

	// 1勝負ごとの結果を返す。続行、勝利、敗北のいずれかである
	ScenePlay::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);


	// 描画----------------------------------------------------------------------------------------------------

	void RenderPlayerHP();              // HP表示
	void RenderPlayersJankenResult();   // プレイヤーのジャンケンリザルト表示
	void RenderBattleStartIntroText();	// ゲーム開始直後１回だけ表示、次ターンからは表示しない

private:

	// 講師配布のライブラリ機能。メモリのロードなど1度だけ実行したい処理で Sequence クラスを使用
	tnl::Sequence<ScenePlay> _sequence = 
		tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqCheckPlayBGM);

	bool SeqCheckPlayBGM(float deltaTime); // バトル開始時、バトル終了時を判定し、BGMを制御

private:

	EnemyBoss*   _boss = nullptr;       // 敵
	SliderEvent* _sliderRef = nullptr;  // イベントアイテム
	Hand*        _handRef = nullptr;    // 手

private:

	GameState    _CURRENT_STATE = GameState::START;

	// プレイヤーというクラスがないのでHPはここで管理
	static int   _playerHP;
};