#pragma once

class SliderEvent;

class EnemyBoss
{
public:

	EnemyBoss() {}
	EnemyBoss(const int stageId);

	// ������------------------------------------------------------------
	void LoadBossImage();
	void LoadBackGround(const int stageId);
	void InitBossHP(const int episodeID);

	// �`��------------------------------------------------------------
	void RenderBossEnemy(const int stageId);             // �G�摜
	void RenderBossHP();                                 // �G HP
	void RenderBossHandProb(const SliderEvent* slider);  // �G �e��̊m��������

	void RenderJankenResult();                           // ���s���ʂ��摜�ŕ\��
	void RenderBackGround(const int stageId);            // �w�i�`��

	// ------------------------------------------------------------
	 
	// �{�X�̏o����(�O�[�A�`���L�A�p�[�j�̊m�����V���b�t��
	void ShuffleBossHandProbabilityTable();

private:

	/*	
	�@�@�@�X���C�_�[�C�x���g���

		   { 70,20,10 }    PERFECT�̏ꍇ
	       { 50,30,20 }    GREAT�̏ꍇ
	       { 40,40,20 }    GOOD�̏ꍇ
	       { 34,33,33 }    BAD�̏ꍇ

		 ���l���傫���قǁA�G�����̎���o���Ă���m���������B

		 �Ȃ��AShuffleBossHandProbabilityTable�֐��ɂ����
		 �O�[�A�`���L�A�p�[�ɂ͂R�̂����̂ǂꂩ�����񃉃��_���œ���B
	*/


	// �X���C�_�[�C�x���g�̃X�R�A�ɂ���ă{�X�̏o����̊m���𖈉�ݒ�
	void SetBossHandProbability_BySliderGrade(const SliderEvent* slider);

	// ��L�֐��ōs�������ʂ�String �ϐ��ŕ\��
	void RenderBossHandProbability();

public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} // �{�X�摜
	BossImageInfo;

public:

	static int _bossHP;

	// �摜�n���h���B�U������炤���Ƃɕ\��p�^�[�����ω�-----------------------------

	int        _bossImg_default_hdl{};
	int        _bossImg_oneHit_hdl{};
	int        _bossImg_twoHit_hdl{};
	int        _bossImg_threeHit_hdl{};
	int        _bossImg_fourHit_hdl{};

private:

	//�@RenderBossHandProbability�֐��Ŏg�p
	std::string _bossHand_predictableStrings[3];
};