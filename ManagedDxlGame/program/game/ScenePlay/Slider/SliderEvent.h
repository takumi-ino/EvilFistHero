#pragma once


static constexpr int SLIDER_IMG_NUM = 11;


/*/
　　　         　　　　　　　　　ScenePlay のバトルで発生するスライダーイベント

	     １. スライダーイベント　→　プレイヤーの手の選択　→　選択後の結果表示  の流れでバトルは進む
		 ２. このスライダーによって敵が出す手の確率を推測することができる
		 ３. スライダーイベントには４段階のグレードが存在する
		 ４. 良いグレードを取れば敵が出す手をより推測しやすくなり、悪いグレードを取れば敵が出す手を推測しにくくなる
*/


class SliderEvent
{
public:

	enum GRADE {

		PERFECT,
		GREAT,
		GOOD,
		BAD,
		MAXINDEX
	};

public:

	SliderEvent();

	~SliderEvent() {

		for (int i = 0; i < SLIDER_IMG_NUM; ++i) {
			DeleteGraph(_slider_images[i]);
		}
	}

	// スライダー画像ロード
	void LoadSliderHandle();

	// スライダー起動。エピソードとボスのHPによってスライダーの速さが変化
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int episodeID, const int bossHP);

	// スライダー成績取得
	const int GetSliderGrade() const { return _slider_grade; }

	// スライダー成績表示
	void ShowSliderGrade();

private:

	// スライダー成績設定
	void SetSliderGrade();

	void SliderAnimation(const float deltaTime, const float speed);

private:

	int     _slider_grade;
	int     _slider_x1{};
	int     _slider_images[SLIDER_IMG_NUM];
	int     _slider_imageIndex = 0;
	int     _slider_color = GetColor(255, 255, 255);

	float   _speed{};
	float   _slider_timeCount = 0.0f;
};