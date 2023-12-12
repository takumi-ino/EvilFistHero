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

	static enum JankenResult {

		RESULT_TYPE_WIN,
		RESULT_TYPE_LOSE,
		RESULT_TYPE_DRAW,
		RESULT_TYPE_MAX
	};


private:

	void RenderPlayerHandSelection();

public:

	Hand();

	void LoadAllHandHandle();

	void AssignJankenResult();

	void SelectMyHand_UpdateCursorPos();

	void SubtractEitherHP(int& playerHP, int& bossHP);

	void RenderJankenResultImage();

	void RenderJankenResultText(int playerHP, int enemyHP);


public:

	Hand* _handRef;

public:

	// グー、チョキ、パーの画像のハンドル
	static int _gpc_hand_hdl[HAND_TYPE_MAX];
	//　カーソルのハンドル
	static int _gpc_cursor_hdl;

	tnl::Vector3 PLAYER_CURSOR_POS = GUCHOKIPA_HANDPOS_TBL[_playerHandIndex];

	static int _gu_prob, _choki_prob, _pa_prob;

	static std::vector<int> HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_MAXINDEX];

	static const tnl::Vector3 GUCHOKIPA_HANDPOS_TBL[HAND_TYPE_MAX];

	static int _jankenResult;

	// プレイヤー---------------------------------------------------------------------

	static int _playerHandIndex;
	static const tnl::Vector3 RESULT_PLAYER_HAND_POS;

	//　ボス---------------------------------------------------------------------

	static int _bossSelectedHand;
	static bool canSelectBossHand;

	static const tnl::Vector3 RESULT_BOSS_HAND_POS;

	const std::string RESULT_NOTICE_STR[3] = { "You Win", "You Lose", "  Draw  " };

	const std::string START_NEXTTURN_STR = "Enter to Next";

	const tnl::Vector3 START_NEXTTURN_STRPOS = { 500, 500, 0 };

private:

	bool isBattleOver;
};