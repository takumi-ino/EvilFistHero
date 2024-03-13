#pragma once


static constexpr int SLIDER_IMG_NUM = 11;


class SliderEvent
{
public:

	enum SliderGrade {

		SLIDER_GRADE_PERFECT,
		SLIDER_GRADE_GREAT,
		SLIDER_GRADE_GOOD,
		SLIDER_GRADE_BAD,
		SLIDER_GRADE_MAXINDEX
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
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int _episodeID, const int bossHP);

	// スライダー成績取得
	const int GetSliderGrade() const { return _slider_grade; }

	// スライダー成績表示
	void ShowSliderGrade();

private:

	// スライダー成績設定
	void SetSliderGrade();

	void SliderAnimation(float deltaTime, const float _speed);

private:

	int     _slider_grade;
	int     _slider_x1{};
	int     _slider_images[SLIDER_IMG_NUM];
	int     _slider_imageIndex = 0;
	int     _slider_color = GetColor(255, 255, 255);

	float   _speed{};
	float   _slider_timeCount = 0.0f;
};