#pragma once
#include "../Slider/SliderEvent.h"
#include "../../../utility/tnlSequence.h"


class EnemyBoss
{
public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} BossImgInfo;

public:

	EnemyBoss(){}
	EnemyBoss(const int& stageId);

	// ������------------------------------------------------------------
	void LoadBossImage(const int& stage_id);
	void LoadBackGround(const int& stage_id);
	void InitBossHP(const int& episodeID);

	// �`��------------------------------------------------------------
	void RenderBossEnemy(const int& stage_id);
	void RenderBossHP();
	void RenderBossHandProb(const SliderEvent* slider);

	void RenderJankenResult();
	void RenderBackGround(const int& stage_id);

	// ------------------------------------------------------------
	// �G�̏o����(�O�[�A�`���L�A�p�[�j�̊m�����V���b�t�� 
	// �� ���l���̂͌Œ肳��Ă���A���̐��l���O�[�A�`���L�A�p�[�Ƀ����_���Ɋ��蓖�Ă�
	void Shuffle_BossHandProbTable();

private:

	void SetBossHandProb_BySliderGrade(const SliderEvent* slider);

public:

	static int bossHP;

	int        bossImg_default_hdl{};
	int        bossImg_oneHit_hdl{};
	int        bossImg_twoHit_hdl{};
	int        bossImg_threeHit_hdl{};
	int        bossImg_fourHit_hdl{};

private:

	// GCP(�O�[�A�`���L�A�p�[�j
	std::string boss_gcpHand_str[3];
};