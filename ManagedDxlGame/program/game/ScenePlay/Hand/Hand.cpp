#include "Hand.h"


const tnl::Vector3 Hand::RESULT_PLAYER_HAND_POS = { 300, 400, 0 };
const tnl::Vector3 Hand::RESULT_BOSS_HAND_POS = { 900, 400, 0 };

int Hand::_playerHandIndex = HAND_TYPE_STONE;

int Hand::_bossSelectedHand = HAND_TYPE_STONE;

int Hand::_gpc_handImageHandle[Hand::HAND_TYPE_MAX];

int Hand::_guHandProbability, Hand::_chokiHandProbability, Hand::_paHandProbability;


// �萔---------------------------------------------------------------------------------------------------------------------------
namespace {

	const std::string RESULT_NOTICE_STR[3] = { "You Win", "You Lose", "  Draw  " };
	const std::string START_NEXTTURN_STR = "Enter to Next";
	const tnl::Vector3 START_NEXTTURN_STRPOS = { 500, 500, 0 };
}


const tnl::Vector3 Hand::GU_CHOKI_PA_IMAGE_POSITIONS[HAND_TYPE_MAX] = {

   {445, 550, 0},
   {610, 550, 0},
   {775, 550, 0}
};


std::vector<int> Hand::_bossHandProbabilitiesByGrade[SliderEvent::MAXINDEX] = {

	{ 70,20,10 }, // PERFECT
	{ 50,30,20 }, // GREAT
	{ 40,40,20 }, // GOOD
	{ 34,33,33 }  // BAD
};
// ---------------------------------------------------------------------------------------------------------------------------


void Hand::LoadAllHandHandle() {

	_gpc_cursor_hdl = LoadGraph("graphics/Hand/cursor.png");
	_gpc_handImageHandle[HAND_TYPE_STONE] = LoadGraph("graphics/Hand/stone.png");
	_gpc_handImageHandle[HAND_TYPE_SCISSORS] = LoadGraph("graphics/Hand/scissors.png");
	_gpc_handImageHandle[HAND_TYPE_PAPER] = LoadGraph("graphics/Hand/paper.png");
}


void Hand::RenderPlayerHandSelection() {

	for (int i = 0; i < HAND_TYPE_MAX; ++i) {

		DrawRotaGraphF(
			GU_CHOKI_PA_IMAGE_POSITIONS[i].x,
			GU_CHOKI_PA_IMAGE_POSITIONS[i].y + 55,
			0.5f, 
			0,
			_gpc_handImageHandle[i],
			true
		);
	}
}


void Hand::UpdateSelectHandCursorPos() {

	RenderPlayerHandSelection();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) {

		_playerHandIndex--;

		if (_playerHandIndex < 0) 
			_playerHandIndex = HAND_TYPE_PAPER;
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) {

		_playerHandIndex++;

		if (_playerHandIndex >= HAND_TYPE_MAX)
			_playerHandIndex = HAND_TYPE_STONE;
	}

	_PLAYER_CURSOR_POS = GU_CHOKI_PA_IMAGE_POSITIONS[_playerHandIndex];


	// �J�[�\���\��
	DrawRotaGraphF(
		_PLAYER_CURSOR_POS.x + 25, 
		_PLAYER_CURSOR_POS.y + 165,
		0.25f,
		0,
		_gpc_cursor_hdl,
		true
	);
}


bool Hand::_canSelectBossHand = true;


void Hand::SubtractLosersHP(int& playerHP, int& _bossHP) {

	//�@�v���C���[���O�[
	if (_playerHandIndex == HAND_TYPE_STONE) {

		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {

			_jankenResult = RESULT_TYPE_WIN;
			_bossHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_PAPER) {

			_jankenResult = RESULT_TYPE_LOSE;
			playerHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {

			_jankenResult = RESULT_TYPE_DRAW;
		}
	}

	//�@�v���C���[���`���L
	if (_playerHandIndex == HAND_TYPE_SCISSORS) {

		if (_bossSelectedHand == HAND_TYPE_PAPER) {

			_jankenResult = RESULT_TYPE_WIN;
			_bossHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_STONE) {

			_jankenResult = RESULT_TYPE_LOSE;
			playerHP--;
		}
		if (_bossSelectedHand == HAND_TYPE_SCISSORS) {

			_jankenResult = RESULT_TYPE_DRAW;
		}
	}

	//�@�v���C���[���p�[
	if (_playerHandIndex == HAND_TYPE_PAPER) {

		if (_bossSelectedHand == HAND_TYPE_STONE) {

			_jankenResult = RESULT_TYPE_WIN;
			_bossHP--;
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

	//�@�v���C���[���O�[
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

	//�@�v���C���[���`���L
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

	//�@�v���C���[���p�[
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
	// �v���C���[���W�����P���ɏ����������������A���������𖈃^�[���\��
	DrawStringEx(490, 400, -1, RESULT_NOTICE_STR[_jankenResult].c_str());

	// �{�X���I��������
	DrawRotaGraphF(
		RESULT_BOSS_HAND_POS.x + 55,
		RESULT_BOSS_HAND_POS.y - 15,
		0.5f, 0, 
		_gpc_handImageHandle[_bossSelectedHand],
		true
	);

	SetFontSize(30);
	DrawStringEx(RESULT_BOSS_HAND_POS.x + 45,
		RESULT_BOSS_HAND_POS.y + 50,
		-1,
		"ENEMY"
	);

	// �v���C���[���I��������
	DrawRotaGraphF(
		RESULT_PLAYER_HAND_POS.x - 30, 
		RESULT_PLAYER_HAND_POS.y - 15,
		0.5f, 0, 
		_gpc_handImageHandle[_playerHandIndex],
		true
	);

	DrawStringEx(RESULT_PLAYER_HAND_POS.x - 50,
		RESULT_PLAYER_HAND_POS.y + 50,
		-1,
		"PLAYER"
	);
}



void Hand::RenderJankenResultText(const int playerHP, const int _bossHP) {

	SetFontSize(DEFAULT_FONT_SIZE);

	//�@�v���C���[�̏���
	if (playerHP != 0 && _bossHP == 0) {

		SetFontSize(70);
		DrawString(460, 400, "Game Clear", -1, true);
		SetFontSize(55);
		DrawString(530, 490, "Enter to StageMap", -1, true);
		return;
	}
	//�@�v���C���[�̕���
	if (playerHP == 0 && _bossHP != 0) {

		SetFontSize(70);
		DrawString(480, 400, "Game Over", -1, true);
		DrawString(530, 490, "Enter", -1, true);
		return;
	}

	SetFontSize(55);
	DrawString(450, 490, "Enter to Next", -1, true);
}