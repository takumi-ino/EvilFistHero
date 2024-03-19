#pragma once


static constexpr int SLIDER_IMG_NUM = 11;


/*/
�@�@�@         �@�@�@�@�@�@�@�@�@ScenePlay �̃o�g���Ŕ�������X���C�_�[�C�x���g

	     �P. �X���C�_�[�C�x���g�@���@�v���C���[�̎�̑I���@���@�I����̌��ʕ\��  �̗���Ńo�g���͐i��
		 �Q. ���̃X���C�_�[�ɂ���ēG���o����̊m���𐄑����邱�Ƃ��ł���
		 �R. �X���C�_�[�C�x���g�ɂ͂S�i�K�̃O���[�h�����݂���
		 �S. �ǂ��O���[�h�����ΓG���o�������萄�����₷���Ȃ�A�����O���[�h�����ΓG���o����𐄑����ɂ����Ȃ�
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

	// �X���C�_�[�摜���[�h
	void LoadSliderHandle();

	// �X���C�_�[�N���B�G�s�\�[�h�ƃ{�X��HP�ɂ���ăX���C�_�[�̑������ω�
	void SliderFuncUpdate_PerFrame(const float deltaTime, const int episodeID, const int bossHP);

	// �X���C�_�[���ю擾
	const int GetSliderGrade() const { return _slider_grade; }

	// �X���C�_�[���ѕ\��
	void ShowSliderGrade();

private:

	// �X���C�_�[���ѐݒ�
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