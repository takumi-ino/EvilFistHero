#include "StageSymbol.h"




std::shared_ptr<StageSymbol[]> StageSymbol::InstantiateButton() {

	std::shared_ptr<StageSymbol[]> buttonArray(new StageSymbol[_SYMBOL_NUM]);

	for (int i = 0; i < _SYMBOL_NUM; i++) {

		int handle = LoadGraph(_buttonImgPath_symbol[i]);

		float x = _SYMBOL_POS_ALL[i].x;
		float y = _SYMBOL_POS_ALL[i].y;
		float width = _SYMBOL_POS_ALL[i].x + _width;
		float height = _SYMBOL_POS_ALL[i].y + _height;

		// ボタンの種類を決める
		Symbol type = (Symbol)i;

		// ボタンのインスタンスを作成して配列に格納
		buttonArray[i] = StageSymbol(handle, x, y, width, height, 0.09f, 0.12f, type);

	}
		return buttonArray;
}



void StageSymbol::FadeIOSymbolMark() {

	if (_fadeIn_symbol) {

		_symbol_alpha --;
		if (_symbol_alpha <= 0)
		{
			_symbol_alpha = 0;
			_fadeIn_symbol = false;
		}
	}
	else
	{
		_symbol_alpha ++;
		if (_symbol_alpha >= 255) {
			_symbol_alpha = 255;
			_fadeIn_symbol = true;
		}
	}
}



void StageSymbol::ZoomSymbolMark_OnMouse(StageSymbol& sym) {

	int mouseX, mouseY;
	float scale = sym._normalSize;

	// マウスが画像上にある場合に拡大表示
	GetMousePoint(&mouseX, &mouseY);

	if (mouseX >= sym._x &&
		mouseX <= sym._x + sym._width &&
		mouseY >= sym._y &&
		mouseY <= sym._y + sym._height) {

		sym._currentSize = sym._zoomSize;
	}
	else {
		sym._currentSize = sym._normalSize;
	}
}



int StageSymbol::_episodeID;

const char* StageSymbol::_EPISODE_TITLE;


void StageSymbol::ClickFunc_SymbolMark(const StageSymbol& sym) {

	int clickX = 0, clickY = 0;


	GetMousePoint(&clickX, &clickY);

	if (GetMouseInput() && MOUSE_INPUT_LEFT)
	{
		if (clickX >= sym._x && clickX <= sym._x + sym._width && clickY >= sym._y && clickY <= sym._y + sym._height) {


			switch (sym._type_symbol) {

			case FOREST - 1: // 森のシンボル
			{
				_episodeID = FOREST;
				_EPISODE_TITLE = "第１章：森の賢王";
				break;
			}
			case VILLAGE - 1: // 村のシンボル
			{
				_episodeID = VILLAGE;

				_EPISODE_TITLE = "第２章：飢饉";
				break;
			}
			case CITY - 1: // 都市のシンボル
			{
				_episodeID = CITY;

				_EPISODE_TITLE = "第３章：近未来";
				break;
			}
			case THEOCRACY - 1: // 神政国家のシンボル
			{
				_episodeID = THEOCRACY;

				_EPISODE_TITLE = "第４章：信仰";
				break;
			}
			case KINGDOM - 1: // 王国のシンボル
			{
				_episodeID = KINGDOM;

				_EPISODE_TITLE = "終章：帝国の支配者";
				break;
			}
			case CONTINENT - 1: // 大陸のシンボル
			{
				_episodeID = CONTINENT;

				_EPISODE_TITLE = "番外編：野球拳勇者";
				break;
			}
			default:
				break;
			}

			_onSelectedSymbol = true;
		}
	}
}



void StageSymbol::AddFuncsToSymbolButton() {

	static std::shared_ptr<StageSymbol[]> buttonArray;

	if(buttonArray == nullptr) 	buttonArray = InstantiateButton();

	// ボタンの描画と処理を行うループ
	for (int i = 0; i < _SYMBOL_NUM; i++) {

		// ボタンのインスタンスを取得する
		StageSymbol& btn = buttonArray[i];

		// ボタンの拡大縮小とクリック処理を行う
		ZoomSymbolMark_OnMouse(btn);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, _symbol_alpha);

		ClickFunc_SymbolMark(btn);

		FadeIOSymbolMark();


		// ボタンの画像を描画する
		DrawRotaGraph(btn._x, btn._y, btn._currentSize, 0.0f, btn._handle, true);
	}
}


void StageSymbol::RenderSymbolMark() {

	AddFuncsToSymbolButton();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}