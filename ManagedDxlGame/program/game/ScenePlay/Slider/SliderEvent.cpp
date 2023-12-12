#include "SliderEvent.h"


SliderEvent::SliderEvent() {

	LoadSliderHandle();
}


void SliderEvent::LoadSliderHandle() {

	for (int i = 0; i < SLIDER_IMG_NUM; ++i) {

		char fileName[40];
		sprintf_s(fileName, "graphics/SliderBar/Bar%d.png", i + 1);
		slider_images[i] = LoadGraph(fileName);
	}
}



void SliderEvent::ReleaseSliderHandle() {

	for (int i = 0; i < SLIDER_IMG_NUM; ++i) {

		DeleteGraph(slider_images[i]);
	}
}



void SliderEvent::SliderAnimationFunc(float deltaTime, const float speed) {

	slider_timeCount += deltaTime * speed;

	if (slider_timeCount > SLIDER_INTERVAL) {

		slider_imageIndex++;
		slider_imageIndex %= SLIDER_IMG_NUM;

		slider_timeCount = 0;
	}
}



void SliderEvent::SliderFuncUpdate_PerFrame(const float deltaTime, const int _episodeID, const int bossHP) {

	_speed = 0.0f;


	switch (_episodeID * 10 + bossHP) {

	case 11:  _episodeID == 1 && bossHP == 1;
	case 22:  _episodeID == 2 && bossHP == 2;
	case 33:  _episodeID == 3 && bossHP == 3;
	case 44:  _episodeID == 4 && bossHP == 4;
	case 55:  _episodeID == 5 && bossHP == 5;
	case 66:  _episodeID == 6 && bossHP == 6;
		_speed = 1.0f;
		break;
	case 21:  _episodeID == 2 && bossHP == 1;
	case 32:  _episodeID == 3 && bossHP == 2;
	case 43:  _episodeID == 4 && bossHP == 3;
	case 54:  _episodeID == 5 && bossHP == 4;
	case 65:  _episodeID == 6 && bossHP == 5;
		_speed = 1.5f;
		break;
	case 31:  _episodeID == 3 && bossHP == 1;
	case 42:  _episodeID == 4 && bossHP == 2;
	case 53:  _episodeID == 5 && bossHP == 3;
	case 64:  _episodeID == 6 && bossHP == 4;
		_speed = 2.0f;
		break;
	case 41:  _episodeID == 4 && bossHP == 1;
	case 52:  _episodeID == 5 && bossHP == 2;
	case 63:  _episodeID == 6 && bossHP == 3;
		_speed = 2.5f;
		break;
	case 51:  _episodeID == 5 && bossHP == 1;
	case 62:  _episodeID == 6 && bossHP == 2;
		_speed = 3.0f;
		break;
	case 61:  _episodeID == 6 && bossHP == 1;
		_speed = 4.0f;
		break;
	}

	SliderAnimationFunc(deltaTime, _speed);
	GetSliderGrade();
	DrawRotaGraph(620, 380, 0.75f, 0, slider_images[slider_imageIndex], true);
}


int SliderEvent::slider_grade;


void SliderEvent::GetSliderGrade() {

	switch (slider_imageIndex) {

	case 0:
		slider_grade = SliderGrade::SLIDER_GRADE_PERFECT;
		slider_color = GetColor(255, 165, 0);
		slider_x = 500;
		break;
	case 1:
	case 2:
	case 3:
		slider_grade = SliderGrade::SLIDER_GRADE_GREAT;
		slider_color = GetColor(0, 240, 0);
		slider_x = 530;
		break;
	case 4:
	case 5:
	case 6:
		slider_grade = SliderGrade::SLIDER_GRADE_GOOD;
		slider_color = GetColor(245, 245, 245);
		slider_x = 540;
		break;
	default:
		slider_grade = SliderGrade::SLIDER_GRADE_BAD;
		slider_color = GetColor(100, 100, 100);
		slider_x = 570;
		break;
	}
}



void SliderEvent::ShowSliderGrade() {


	SetFontSize(45);

	switch (slider_grade) {

	case SliderGrade::SLIDER_GRADE_PERFECT:

		DrawString(slider_x, slider_y, "PERFECT!", slider_color);
		break;
	case SliderGrade::SLIDER_GRADE_GREAT:

		DrawString(slider_x, slider_y, "GREAT!", slider_color);
		break;
	case SliderGrade::SLIDER_GRADE_GOOD:

		DrawString(slider_x, slider_y, "GOOD", slider_color);
		break;
	case SliderGrade::SLIDER_GRADE_BAD:

		DrawString(slider_x, slider_y, "BAD", slider_color);
		break;
	}

	// スライダーの画像を表示する
	DrawRotaGraph(620, 380, 0.75f, 0, slider_images[slider_imageIndex], true);
}