#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "../Slider/SliderEvent.h"


class Hand
{
public:

	// ��̎��
	enum HandType
	{
		HAND_TYPE_STONE,
		HAND_TYPE_SCISSORS,
		HAND_TYPE_PAPER,
		HAND_TYPE_MAX
	};

	// ����
	enum JankenResult {

		RESULT_TYPE_WIN,
		RESULT_TYPE_LOSE,
		RESULT_TYPE_DRAW,
		RESULT_TYPE_MAX
	};

public:

	Hand() {

		LoadAllHandHandle();
	}

	// �摜�n���h��������
	void LoadAllHandHandle();

	// ���s���ʂ�ϐ��֑��
	void AssignJankenResult();

	// �v���C���[�����I�ԂƂ��ɂ��鍶�E�̓���
	void SelectMyHand_UpdateCursorPos();

	// �s�҂�HP��1���炷
	void SubtractLosersHP(int& playerHP, int& bossHP);

	// ���s���ʂ������摜��`��
	void RenderJankenResultImage();

	// ���s���ʂ������e�L�X�g��`��
	void RenderJankenResultText(int playerHP, int enemyHP);

private:

	// �O�[�A�`���L�A�p�[�̉摜�\��
	void RenderPlayerHandSelection();

public:

	Hand* _handRef = nullptr;

public:

	// �O�[�A�`���L�A�p�[�̉摜�̃n���h��
	static int _gpc_hand_hdl[HAND_TYPE_MAX];

	static std::vector<int> HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_MAXINDEX];

	//�v���C���[---------------------------------------------------------------------
	static int   _playerHandIndex;
	static const tnl::Vector3 RESULT_PLAYER_HAND_POS;

	//�{�X--------------------------------------------------------------------------
	static int  _bossSelectedHand;   // ���ۂɏo������
	static bool _canSelectBossHand;  // �{�X�����I���ł����Ԃ�

	// �{�X���o���O�[�A�`���L�A�p�[�̊m�������ꂼ��i�[
	static int _gu_prob, _choki_prob, _pa_prob;

	//���W�n----------------------------------------------------------------------
	static const tnl::Vector3 GUCHOKIPA_HANDPOS_TBL[HAND_TYPE_MAX];
	static const tnl::Vector3 RESULT_BOSS_HAND_POS;

private:

	//�@�J�[�\���̃n���h��
	int  _gpc_cursor_hdl;

	// �W�����P���̏��s��ԍ��Ŏ擾
	int  _jankenResult;

	bool _isBattleOver{};

	// �摜���W
	tnl::Vector3 _PLAYER_CURSOR_POS = GUCHOKIPA_HANDPOS_TBL[_playerHandIndex];
};