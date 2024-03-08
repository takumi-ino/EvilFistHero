#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"


constexpr static int SLIDER_IMG_NUM = 11;


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

			DeleteGraph(slider_images[i]);
		}
	}

	// �X���C�_�[�摜���[�h
	void LoadSliderHandle();

	// �X���C�_�[�N���֐��B�G�s�\�[�h�ƃ{�X��HP�ɂ���ăX���C�_�[�̑������ω�����
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int episodeID, const int bossHP);

	void GetSliderGrade();

	void ShowSliderGrade();

private:

	void SliderAnimation(float deltaTime, const float speed);

public:

	static int slider_grade;

private:

	int     slider_imageIndex = 0;
	int     slider_x{};
	int     slider_y = 280;

	int     slider_images[SLIDER_IMG_NUM];

	int     slider_color = GetColor(255, 255, 255);

	float   speed{};
	float   slider_timeCount = 0.0f;

	const float SLIDER_INTERVAL = 0.1f;
};