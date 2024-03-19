#pragma once

class SliderEvent;

class EnemyBoss
{
public:

	EnemyBoss() {}
	EnemyBoss(const int stageId);

	// 初期化------------------------------------------------------------
	void LoadBossImage();
	void LoadBackGround(const int stageId);
	void InitBossHP(const int episodeID);

	// 描画------------------------------------------------------------
	void RenderBossEnemy(const int stageId);             // 敵画像
	void RenderBossHP();                                 // 敵 HP
	void RenderBossHandProb(const SliderEvent* slider);  // 敵 各手の確率文字列

	void RenderJankenResult();                           // 勝敗結果を画像で表示
	void RenderBackGround(const int stageId);            // 背景描画

	// ------------------------------------------------------------
	 
	// ボスの出す手(グー、チョキ、パー）の確率をシャッフル
	void ShuffleBossHandProbabilityTable();

private:

	/*	
	　　　スライダーイベントより

		   { 70,20,10 }    PERFECTの場合
	       { 50,30,20 }    GREATの場合
	       { 40,40,20 }    GOODの場合
	       { 34,33,33 }    BADの場合

		 数値が大きいほど、敵がその手を出してくる確率が高い。

		 なお、ShuffleBossHandProbabilityTable関数によって
		 グー、チョキ、パーには３つのうちのどれかが毎回ランダムで入る。
	*/


	// スライダーイベントのスコアによってボスの出す手の確率を毎回設定
	void SetBossHandProbability_BySliderGrade(const SliderEvent* slider);

	// 上記関数で行った結果をString 変数で表示
	void RenderBossHandProbability();

public:

	typedef struct {

		int x, y;
		double exRate;
		double angle;

	} // ボス画像
	BossImageInfo;

public:

	static int _bossHP;

	// 画像ハンドル。攻撃を喰らうごとに表情パターンが変化-----------------------------

	int        _bossImg_default_hdl{};
	int        _bossImg_oneHit_hdl{};
	int        _bossImg_twoHit_hdl{};
	int        _bossImg_threeHit_hdl{};
	int        _bossImg_fourHit_hdl{};

private:

	//　RenderBossHandProbability関数で使用
	std::string _bossHand_predictableStrings[3];
};