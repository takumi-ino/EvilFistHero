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

	// 初期化------------------------------------------------------------
	void LoadBossImage(const int& stage_id);
	void LoadBackGround(const int& stage_id);
	void InitBossHP(const int& episodeID);

	// 描画------------------------------------------------------------
	void RenderBossEnemy(const int& stage_id);
	void RenderBossHP();
	void RenderBossHandProb(const SliderEvent* slider);

	void RenderJankenResult();
	void RenderBackGround(const int& stage_id);

	// ------------------------------------------------------------
	// 敵の出す手(グー、チョキ、パー）の確率をシャッフル 
	// ※ 数値自体は固定されており、その数値をグー、チョキ、パーにランダムに割り当てる
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

	// GCP(グー、チョキ、パー）
	std::string boss_gcpHand_str[3];
};