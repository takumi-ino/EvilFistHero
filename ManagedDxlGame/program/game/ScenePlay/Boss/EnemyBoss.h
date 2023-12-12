#pragma once
#include "../Slider/SliderEvent.h"
#include "../../../utility/tnlSequence.h"

class EnemyBoss
{
public:

	EnemyBoss(){}
	EnemyBoss(const int& stageId);

	void LoadBossImage(const int& stage_id);

	void LoadBackGround(const int& stage_id);

	void RenderBossEnemy(const int& stage_id);

	void RenderBackGround(const int& stage_id);

	void InitBossHP(const int& episodeID);

	// �G�̏o����(�O�[�A�`���L�A�p�[�j�̊m�����V���b�t�� 
	// �� ���l���̂͌Œ肳��Ă���A���̐��l���O�[�A�`���L�A�p�[�Ƀ����_���Ɋ��蓖�Ă�
	void Shuffle_BossHandProbTable();

	void RenderBossHP();

	void RenderBossHandProb(const SliderEvent* slider);

	void RenderJankenResult();

private:

	void SetBossHandProb_BySliderGrade(const SliderEvent* slider);

public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} BossImgInfo;

public:

	static int _bossHP;
	int _bossImg_default_hdl;
	int _bossImg_oneHit_hdl;
	int _bossImg_twoHit_hdl;
	int _bossImg_threeHit_hdl;
	int _bossImg_fourHit_hdl;


private:

	// GCP(�O�[�A�`���L�A�p�[�j
	std::string _boss_gcpHand_str[3];
};