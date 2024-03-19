#include "../../../utility/DxLib_Engine.h"
#include "SliderEvent.h"


namespace {

	const int   slider_y = 280;
	const float SLIDER_INTERVAL = 0.1f;
}


SliderEvent::SliderEvent() {

	LoadSliderHandle();
}


void SliderEvent::LoadSliderHandle() {

	for (int i = 0; i < SLIDER_IMG_NUM; ++i) {

		char fileName[40];
		sprintf_s(fileName, "graphics/SliderBar/Bar%d.png", i + 1);
		_slider_images[i] = LoadGraph(fileName);
	}
}


void SliderEvent::SliderAnimation(const float deltaTime, const float speed) {

	_slider_timeCount += deltaTime * speed;

	if (_slider_timeCount > SLIDER_INTERVAL) {

		_slider_imageIndex++;
		_slider_imageIndex %= SLIDER_IMG_NUM;

		_slider_timeCount = 0;
	}
}


void SliderEvent::SliderFuncUpdate_PerFrame(const float deltaTime, const int episodeID, const int bossHP) {

	_speed = 0.0f;

	switch (episodeID * 10 + bossHP) {

	case 11:  _speed = 1.0f; break; /* episodeID == 1 && bossHP == 1;*/
	case 22:  _speed = 1.0f; break; /* episodeID == 2 && bossHP == 2;*/
	case 33:  _speed = 1.0f; break; /* episodeID == 3 && bossHP == 3;*/
	case 44:  _speed = 1.0f; break; /* episodeID == 4 && bossHP == 4;*/
	case 55:  _speed = 1.0f; break; /* episodeID == 5 && bossHP == 5;*/
	case 66:  _speed = 1.0f; break; /* episodeID == 6 && bossHP == 6;*/

	case 21: _speed = 1.5f;	break; /* episodeID == 2 && bossHP == 1;*/
	case 32: _speed = 1.5f;	break; /* episodeID == 3 && bossHP == 2;*/
	case 43: _speed = 1.5f;	break; /* episodeID == 4 && bossHP == 3;*/
	case 54: _speed = 1.5f;	break; /* episodeID == 5 && bossHP == 4;*/
	case 65: _speed = 1.5f;	break; /* episodeID == 6 && bossHP == 5;*/

	case 31: _speed = 2.0f; break; /* episodeID == 3 && bossHP == 1;*/
	case 42: _speed = 2.0f; break; /* episodeID == 4 && bossHP == 2;*/
	case 53: _speed = 2.0f; break; /* episodeID == 5 && bossHP == 3;*/
	case 64: _speed = 2.0f; break; /* episodeID == 6 && bossHP == 4;*/

	case 41: _speed = 2.5f; break; /*episodeID == 4 && bossHP == 1;*/
	case 52: _speed = 2.5f; break; /*episodeID == 5 && bossHP == 2;*/
	case 63: _speed = 2.5f; break; /*episodeID == 6 && bossHP == 3;*/

	case 51: _speed = 3.0f; break; /*episodeID == 5 && bossHP == 1;*/
	case 62: _speed = 3.0f; break; /*episodeID == 6 && bossHP == 2;*/

	case 61: _speed = 4.0f; break; /*episodeID == 6 && bossHP == 1;*/
	}

	SliderAnimation(deltaTime, _speed);
	SetSliderGrade();
	DrawRotaGraph(620, 380, 0.75f, 0, _slider_images[_slider_imageIndex], true);
}


void SliderEvent::SetSliderGrade() {

	switch (_slider_imageIndex) {

	case 0:
		_slider_grade = GRADE::PERFECT;
		_slider_color = GetColor(255, 165, 0);
		_slider_x1 = 500;
		break;
	case 1:
	case 2:
	case 3:
		_slider_grade = GRADE::GREAT;
		_slider_color = GetColor(0, 240, 0);
		_slider_x1 = 530;
		break;
	case 4:
	case 5:
	case 6:
		_slider_grade = GRADE::GOOD;
		_slider_color = GetColor(245, 245, 245);
		_slider_x1 = 540;
		break;
	default:
		_slider_grade = GRADE::BAD;
		_slider_color = GetColor(100, 100, 100);
		_slider_x1 = 570;
		break;
	}
}



void SliderEvent::ShowSliderGrade() {

	SetFontSize(45);

	switch (_slider_grade) {

	case GRADE::PERFECT:

		DrawString(_slider_x1, slider_y, "PERFECT!", _slider_color);
		break;
	case GRADE::GREAT:

		DrawString(_slider_x1, slider_y, "GREAT!", _slider_color);
		break;
	case GRADE::GOOD:

		DrawString(_slider_x1, slider_y, "GOOD", _slider_color);
		break;
	case GRADE::BAD:

		DrawString(_slider_x1, slider_y, "BAD", _slider_color);
		break;
	}

	// スライダーの画像を表示する
	DrawRotaGraph(620, 380, 0.75f, 0, _slider_images[_slider_imageIndex], true);
}