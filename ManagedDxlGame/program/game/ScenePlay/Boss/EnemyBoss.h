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

	// 敵の出す手(グー、チョキ、パー）の確率をシャッフル 
	// ※ 数値自体は固定されており、その数値をグー、チョキ、パーにランダムに割り当てる
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

	// GCP(グー、チョキ、パー）
	std::string _boss_gcpHand_str[3];
};