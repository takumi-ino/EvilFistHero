#pragma once

class SliderEvent;

class EnemyBoss
{
public:

	EnemyBoss(){}
	EnemyBoss(const int& stageId);

	// 初期化------------------------------------------------------------
	void LoadBossImage();
	void LoadBackGround(const int& stage_id);
	void InitBossHP(const int& _episodeID);

	// 描画------------------------------------------------------------
	void RenderBossEnemy(const int& stage_id);           // 敵画像
	void RenderBossHP();                                 // 敵 HP
	void RenderBossHandProb(const SliderEvent* slider);  // 敵 各手の確率文字列

	void RenderJankenResult();                           // 勝敗結果を画像で表示
	void RenderBackGround(const int& stage_id);          // 背景描画

	// ------------------------------------------------------------
	// 敵の出す手(グー、チョキ、パー）の確率をシャッフル 
	// ※ 数値自体は固定されており、その数値をグー、チョキ、パーにランダムに割り当てる
	void Shuffle_BossHandProbTable();

private:

	// スライダーイベントのスコアによってボスの出す手の確率を毎回設定
	void SetBossHandProb_BySliderGrade(const SliderEvent* slider);

public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} BossImgInfo;

public:

	static int bossHP;

	// 画像ハンドル------------------------------------------------------------
	int        bossImg_default_hdl{};
	int        bossImg_oneHit_hdl{};
	int        bossImg_twoHit_hdl{};
	int        bossImg_threeHit_hdl{};
	int        bossImg_fourHit_hdl{};

private:

	// GCP(グー、チョキ、パー）
	std::string boss_gcpHand_str[3];
};