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


void SliderEvent::SliderAnimation(float deltaTime, const float speed) {

	slider_timeCount += deltaTime * speed;

	if (slider_timeCount > SLIDER_INTERVAL) {

		slider_imageIndex++;
		slider_imageIndex %= SLIDER_IMG_NUM;

		slider_timeCount = 0;
	}
}



void SliderEvent::SliderFuncUpdate_PerFrame(const float deltaTime, const int episodeID, const int bossHP) {

	speed = 0.0f;

	switch (episodeID * 10 + bossHP) {

	case 11:  episodeID == 1 && bossHP == 1;
	case 22:  episodeID == 2 && bossHP == 2;
	case 33:  episodeID == 3 && bossHP == 3;
	case 44:  episodeID == 4 && bossHP == 4;
	case 55:  episodeID == 5 && bossHP == 5;
	case 66:  episodeID == 6 && bossHP == 6;
		speed = 1.0f;
		break;
	case 21:  episodeID == 2 && bossHP == 1;
	case 32:  episodeID == 3 && bossHP == 2;
	case 43:  episodeID == 4 && bossHP == 3;
	case 54:  episodeID == 5 && bossHP == 4;
	case 65:  episodeID == 6 && bossHP == 5;
		speed = 1.5f;
		break;
	case 31:  episodeID == 3 && bossHP == 1;
	case 42:  episodeID == 4 && bossHP == 2;
	case 53:  episodeID == 5 && bossHP == 3;
	case 64:  episodeID == 6 && bossHP == 4;
		speed = 2.0f;
		break;
	case 41:  episodeID == 4 && bossHP == 1;
	case 52:  episodeID == 5 && bossHP == 2;
	case 63:  episodeID == 6 && bossHP == 3;
		speed = 2.5f;
		break;
	case 51:  episodeID == 5 && bossHP == 1;
	case 62:  episodeID == 6 && bossHP == 2;
		speed = 3.0f;
		break;
	case 61:  episodeID == 6 && bossHP == 1;
		speed = 4.0f;
		break;
	}

	SliderAnimation(deltaTime, speed);
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