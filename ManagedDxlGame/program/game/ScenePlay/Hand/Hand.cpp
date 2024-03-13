#include "Hand.h"


const tnl::Vector3 Hand::RESULT_PLAYER_HAND_POS = { 300, 400, 0 };
const tnl::Vector3 Hand::RESULT_BOSS_HAND_POS = { 900, 400, 0 };

int Hand::_playerHandIndex = HAND_TYPE_STONE;

int Hand::_bossSelectedHand = HAND_TYPE_STONE;

int Hand::_gpc_hand_hdl[Hand::HAND_TYPE_MAX];

int Hand::_gu_prob, Hand::_choki_prob, Hand::_pa_prob;


namespace {

	const std::string RESULT_NOTICE_STR[3] = { "You Win", "You Lose", "  Draw  " };
	const std::string START_NEXTTURN_STR = "Enter to Next";
	const tnl::Vector3 START_NEXTTURN_STRPOS = { 500, 500, 0 };
}

const tnl::Vector3 Hand::GUCHOKIPA_HANDPOS_TBL[HAND_TYPE_MAX] = {

   {445, 550, 0},
   {610, 550, 0},
   {775, 550, 0}
};


std::vector<int> Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_MAXINDEX] = {

	{ 70,20,10 }, // PERFECT
	{ 50,30,20 }, // GREAT
	{ 40,40,20 }, // GOOD
	{ 34,33,33 }  // BAD
};


void Hand::LoadAllHandHandle() {

	_gpc_cursor_hdl = LoadGraph("graphics/Hand/cursor.png");
	_gpc_hand_hdl[HAND_TYPE_STONE] = LoadGraph("graphics/Hand/stone.png");
	_gpc_hand_hdl[HAND_TYPE_SCISSORS] = LoadGraph("graphics/Hand/scissors.png");
	_gpc_hand_hdl[HAND_TYPE_PAPER] = LoadGraph("graphics/Hand/paper.png");
}


void Hand::RenderPlayerHandSelection() {

	for (int i = 0; i < HAND_TYPE_MAX; ++i) {
		DrawRotaGraphF(GUCHOKIPA_HANDPOS_TBL[i].x, GUCHOKIPA_HANDPOS_TBL[i].y + 55, 0.5f, 0, _gpc_hand_hdl[i], true);
	}
}


void Hand::SelectMyHand_UpdateCursorPos() {

	RenderPlayerHandSelection();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) {

		_playerHandIndex--;
		if (_playerHandIndex < 0) _playerHandIndex = HAND_TYPE_PAPER;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) {

		_playerHandIndex++;
		if (_playerHandIndex >= HAND_TYPE_MAX) _playerHandIndex = HAND_TYPE_STONE;
	}

	_PLAYER_CURSOR_POS = GUCHOKIPA_HANDPOS_TBL[_playerHandIndex];


	// カーソル表示
	DrawRotaGraphF(_PLAYER_CURSOR_POS.x + 25, _PLAYER_CURSOR_POS.y + 165, 0.25f, 0, _gpc_cursor_hdl, true);
}


bool Hand::_canSelectBossHand = true;


void Hand::SubtractLosersHP(int& playerHP, int& bossHP) {

	// じゃんけんの勝敗判定
	if (_playerHandIndex == HAND_TYPE_STONE) {

		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_WIN;
			bossHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_LOSE;
			playerHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}

	if (_playerHandIndex == HAND_TYPE_SCISSORS) {

		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_WIN;
			bossHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_LOSE;
			playerHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}
	if (_playerHandIndex == HAND_TYPE_PAPER) {

		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_WIN;
			bossHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_LOSE;
			playerHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}
}



void Hand::AssignJankenResult() {

	// じゃんけんの勝敗判定
	if (_playerHandIndex == HAND_TYPE_STONE) {

		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_WIN;
		}
		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_LOSE;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}

	if (_playerHandIndex == HAND_TYPE_SCISSORS) {

		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_WIN;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_LOSE;
		}
		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}
	if (_playerHandIndex == HAND_TYPE_PAPER) {

		if (_bossSelectedHand == HAND_TYPE_STONE) {
			_jankenResult = RESULT_TYPE_WIN;
		}
		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {
			_jankenResult = RESULT_TYPE_LOSE;
		}
		if (_bossSelectedHand == HAND_TYPE_PAPER) {
			_jankenResult = RESULT_TYPE_DRAW;
		}
	}
}



void Hand::RenderJankenResultImage() {

	AssignJankenResult();

	SetFontSize(70);
	// プレイヤーがジャンケンに勝ったか負けたか、あいこかを毎ターン表示
	DrawStringEx(490, 400, -1, RESULT_NOTICE_STR[_jankenResult].c_str());

	DrawRotaGraphF(
		RESULT_BOSS_HAND_POS.x + 55, RESULT_BOSS_HAND_POS.y - 15, 0.5f, 0, _gpc_hand_hdl[_bossSelectedHand], true);

	DrawRotaGraphF(
		RESULT_PLAYER_HAND_POS.x - 30, RESULT_PLAYER_HAND_POS.y - 15, 0.5f, 0, _gpc_hand_hdl[_playerHandIndex], true);

	SetFontSize(30);
	DrawStringEx(RESULT_BOSS_HAND_POS.x + 45, RESULT_BOSS_HAND_POS.y + 50, -1, "ENEMY");
	DrawStringEx(RESULT_PLAYER_HAND_POS.x - 50, RESULT_PLAYER_HAND_POS.y + 50, -1, "PLAYER");
}



void Hand::RenderJankenResultText(int playerHP, int bossHP) {

	SetFontSize(DEFAULT_FONT_SIZE);

	if (playerHP != 0 && bossHP == 0) {

		SetFontSize(70);
		DrawString(460, 400, "Game Clear", -1, true);
		SetFontSize(55);
		DrawString(530, 490, "Enter to StageMap", -1, true);
		return;
	}
	if (playerHP == 0 && bossHP != 0) {

		SetFontSize(70);
		DrawString(480, 400, "Game Over", -1, true);
		DrawString(530, 490, "Enter", -1, true);
		return;
	}

	SetFontSize(55);
	DrawString(450, 490, "Enter to Next", -1, true);
}