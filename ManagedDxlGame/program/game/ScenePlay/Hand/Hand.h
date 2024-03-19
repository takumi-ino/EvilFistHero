#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "../Slider/SliderEvent.h"

/*
�@�@�@�@�@ ScenePlay �Ńv���C���[�ƃ{�X���g�p���������ꂼ��Ǘ�

	  ��Ɏ�̕`�揈���A�s�҂�HP�����炷�����A���I�ԂƂ��̓��͏����Ȃǂ�����
*/

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

	// ������----------------------------------------------------------------------------------
	Hand() {

		LoadAllHandHandle();
	}

	//�@�摜�n���h��
	void LoadAllHandHandle(); 

	//�@----------------------------------------------------------------------------------
	// �W�����P�����s���ʂ����U���g�ێ��ϐ��֑��
	void AssignJankenResult();	

	// �v���C���[�����I�ԂƂ��ɂ��鍶�E�̓���
	void UpdateSelectHandCursorPos();	

	// �s�҂�HP��1���炷
	void SubtractLosersHP(int& playerHP, int& _bossHP);	

	// �`��----------------------------------------------------------------------------------
	 
	// ���s���ʂ������摜
	void RenderJankenResultImage();

	// ���s���ʂ������e�L�X�g
	void RenderJankenResultText(const int playerHP, const int enemyHP);

private:

	// �O�[�A�`���L�A�p�[�̉摜�\��
	void RenderPlayerHandSelection();

public:

	// �O�[�A�`���L�A�p�[�̉摜�̃n���h��
	static int _gpc_handImageHandle[HAND_TYPE_MAX];

	// �O�[�A�`���L�A�p�[�̉摜�̕\���ʒu�B�v���C���[�A�{�X�Ƃ��ɂ��̒l�̍������g�p���A���\��
	static const tnl::Vector3 GU_CHOKI_PA_IMAGE_POSITIONS[HAND_TYPE_MAX];

	//�v���C���[---------------------------------------------------------------------
	static int   _playerHandIndex;                      // �v���C���[�̎�
	static const tnl::Vector3 RESULT_PLAYER_HAND_POS;   // �v���C���[�̎�̈ʒu

	//�{�X---------------------------------------------------------------------------
	static int  _bossSelectedHand;                      // �{�X�����ۂɏo������
	static bool _canSelectBossHand;                     // �{�X�����I���ł����Ԃ�

	// �{�X�̏o����̊m���̑g�ݍ��킹�B�X���C�_�[�C�x���g�̐��тɂ���ĂS�i�K�ɕ������
	static std::vector<int> _bossHandProbabilitiesByGrade[SliderEvent::MAXINDEX];

	// �{�X���o���O�[�A�`���L�A�p�[�̊m�������ꂼ��i�[
	static int _guHandProbability, _chokiHandProbability, _paHandProbability;

	static const tnl::Vector3 RESULT_BOSS_HAND_POS;

private:

	//�@�J�[�\���̃n���h��
	int  _gpc_cursor_hdl;

	// �W�����P���̏��s��ԍ��Ŏ擾
	int  _jankenResult;

	//�@���s��������
	bool _isBattleOver{};

	// �v���C���[�����I������Ƃ��Ɏg�p����J�[�\���̍��W
	tnl::Vector3 _PLAYER_CURSOR_POS = GU_CHOKI_PA_IMAGE_POSITIONS[_playerHandIndex];
};