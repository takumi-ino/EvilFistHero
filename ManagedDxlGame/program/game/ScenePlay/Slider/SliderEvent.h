#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"


#define SLIDER_IMG_NUM 11


class SliderEvent
{
public:

	SliderEvent();
	~SliderEvent(){}

	void LoadSliderHandle();
	void ReleaseSliderHandle();


	// スライダー起動関数。エピソードとボスのHPによってスライダーの速さが変化する
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int _episodeID, const int bossHP);

	void GetSliderGrade();

	void ShowSliderGrade();

private:

	void SliderAnimationFunc(float deltaTime, const float speed);

public:

	enum SliderGrade {

		SLIDER_GRADE_PERFECT,
		SLIDER_GRADE_GREAT,
		SLIDER_GRADE_GOOD,
		SLIDER_GRADE_BAD,
		SLIDER_GRADE_MAXINDEX
	};


	float slider_timeCount = 0.0f;
	int slider_imageIndex = 0;
	int slider_x, slider_y = 280;

	int slider_images[SLIDER_IMG_NUM];

	int slider_color = GetColor(255,255,255);
	const float SLIDER_INTERVAL = 0.1f;

	static int slider_grade;

private:

	float _speed;
};