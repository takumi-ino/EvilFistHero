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

	// �X���C�_�[�摜���[�h
	void LoadSliderHandle();

	// �X���C�_�[�N���B�G�s�\�[�h�ƃ{�X��HP�ɂ���ăX���C�_�[�̑������ω�
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int _episodeID, const int bossHP);

	// �X���C�_�[���ю擾
	const int GetSliderGrade() const { return _slider_grade; }

	// �X���C�_�[���ѕ\��
	void ShowSliderGrade();

private:

	// �X���C�_�[���ѐݒ�
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