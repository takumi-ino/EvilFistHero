#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "../Slider/SliderEvent.h"
#include "../../ScenePlay/Battle/Scene_JankenBattle.h"


class Scene_JankenBattle;

class Hand
{
public:

	// 手の種類
	static enum HandType
	{
		HAND_TYPE_STONE,
		HAND_TYPE_SCISSORS,
		HAND_TYPE_PAPER,
		HAND_TYPE_MAX
	};

	// 結果
	static enum JankenResult {

		RESULT_TYPE_WIN,
		RESULT_TYPE_LOSE,
		RESULT_TYPE_DRAW,
		RESULT_TYPE_MAX
	};

public:

	Hand() {

		LoadAllHandHandle();
	}

	// 画像ハンドル初期化
	void LoadAllHandHandle();

	// 勝敗結果を変数へ代入
	void AssignJankenResult();

	// プレイヤーが手を選ぶときにする左右の入力
	void SelectMyHand_UpdateCursorPos();

	// 敗者のHPを1減らす
	void SubtractLosersHP(int& playerHP, int& bossHP);

	// 勝敗結果を示す画像を描画
	void RenderJankenResultImage();

	// 勝敗結果を示すテキストを描画
	void RenderJankenResultText(int playerHP, int enemyHP);

private:

	// グー、チョキ、パーの画像表示
	void RenderPlayerHandSelection();

public:

	Hand* _handRef;

public:

	// グー、チョキ、パーの画像のハンドル
	static int _gpc_hand_hdl[HAND_TYPE_MAX];
	//　カーソルのハンドル
	static int _gpc_cursor_hdl;
	// ジャンケンの勝敗を番号で取得
	static int _jankenResult;

	static std::vector<int> HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_MAXINDEX];

	//プレイヤー---------------------------------------------------------------------
	static int _playerHandIndex;
	static const tnl::Vector3 RESULT_PLAYER_HAND_POS;

	//ボス--------------------------------------------------------------------------
	static int _bossSelectedHand;   // 実際に出した手
	static bool canSelectBossHand;  // ボスが手を選択できる状態か

	// ボスが出すグー、チョキ、パーの確率をそれぞれ格納
	static int _gu_prob, _choki_prob, _pa_prob;

	//座標系----------------------------------------------------------------------
	static const tnl::Vector3 GUCHOKIPA_HANDPOS_TBL[HAND_TYPE_MAX];

	// 画像座標
	tnl::Vector3 PLAYER_CURSOR_POS = GUCHOKIPA_HANDPOS_TBL[_playerHandIndex];

	static const tnl::Vector3 RESULT_BOSS_HAND_POS;

	const std::string RESULT_NOTICE_STR[3] = { "You Win", "You Lose", "  Draw  " };
	const std::string START_NEXTTURN_STR = "Enter to Next";
	const tnl::Vector3 START_NEXTTURN_STRPOS = { 500, 500, 0 };

private:

	bool isBattleOver{};
};