#pragma once

class SliderEvent;

class EnemyBoss
{
public:

	EnemyBoss(){}
	EnemyBoss(const int& stageId);

	// ������------------------------------------------------------------
	void LoadBossImage();
	void LoadBackGround(const int& stage_id);
	void InitBossHP(const int& _episodeID);

	// �`��------------------------------------------------------------
	void RenderBossEnemy(const int& stage_id);           // �G�摜
	void RenderBossHP();                                 // �G HP
	void RenderBossHandProb(const SliderEvent* slider);  // �G �e��̊m��������

	void RenderJankenResult();                           // ���s���ʂ��摜�ŕ\��
	void RenderBackGround(const int& stage_id);          // �w�i�`��

	// ------------------------------------------------------------
	// �G�̏o����(�O�[�A�`���L�A�p�[�j�̊m�����V���b�t�� 
	// �� ���l���̂͌Œ肳��Ă���A���̐��l���O�[�A�`���L�A�p�[�Ƀ����_���Ɋ��蓖�Ă�
	void Shuffle_BossHandProbTable();

private:

	// �X���C�_�[�C�x���g�̃X�R�A�ɂ���ă{�X�̏o����̊m���𖈉�ݒ�
	void SetBossHandProb_BySliderGrade(const SliderEvent* slider);

public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} BossImgInfo;

public:

	static int bossHP;

	// �摜�n���h��------------------------------------------------------------
	int        bossImg_default_hdl{};
	int        bossImg_oneHit_hdl{};
	int        bossImg_twoHit_hdl{};
	int        bossImg_threeHit_hdl{};
	int        bossImg_fourHit_hdl{};

private:

	// GCP(�O�[�A�`���L�A�p�[�j
	std::string boss_gcpHand_str[3];
};