#include "../../../utility/DxLib_Engine.h"
#include "StageSymbol.h"

namespace {

	const int   _SYMBOL_NUM = 6;

	const tnl::Vector3 FOREST_SYMBOL_POS = { 357,  95, 0 };
	const tnl::Vector3 VILLAGE_SYMBOL_POS = { 787, 265, 0 };
	const tnl::Vector3 CITY_SYMBOL_POS = { 950, 580, 0 };
	const tnl::Vector3 THEOCRACY_SYMBOL_POS = { 455, 680, 0 };
	const tnl::Vector3 KINGDOM_SYMBOL_POS = { 484, 285, 0 };
	const tnl::Vector3 CONTINENT_SYMBOL_POS = { 235, 400, 0 };

	const tnl::Vector3 _SYMBOL_POS_ALL[6] =
	{
		FOREST_SYMBOL_POS,
		VILLAGE_SYMBOL_POS,
		CITY_SYMBOL_POS,
		THEOCRACY_SYMBOL_POS,
		KINGDOM_SYMBOL_POS,
		CONTINENT_SYMBOL_POS
	};

	const char* _buttonImgPath_symbol[6] =
	{
	"graphics/Symbols/Forest.png",
	"graphics/Symbols/Village.png",
	"graphics/Symbols/City.png",
	"graphics/Symbols/Theocracy.png",
	"graphics/Symbols/Kingdom.png",
	"graphics/Symbols/Continent.png"
	};
}


std::shared_ptr<StageSymbol[]> StageSymbol::InstantiateButton() {

	std::shared_ptr<StageSymbol[]> buttonArray(new StageSymbol[_SYMBOL_NUM]);

	for (int i = 0; i < _SYMBOL_NUM; i++) {

		int _button_hdl = LoadGraph(_buttonImgPath_symbol[i]);

		int x = static_cast<int>(_SYMBOL_POS_ALL[i].x);
		int y = static_cast<int>(_SYMBOL_POS_ALL[i].y);
		int _button_width = static_cast<int>(_SYMBOL_POS_ALL[i].x + _symbol_width);
		int _button_height = static_cast<int>(_SYMBOL_POS_ALL[i].y + _symbol_height);

		// ボタンの種類を決める
		Symbol type = (Symbol)i;

		// ボタンのインスタンスを作成して配列に格納
		buttonArray[i] = StageSymbol(_button_hdl, x, y, _button_width, _button_height, 0.09f, 0.12f, type);

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

	if (mouseX >= sym._symbol_x1 &&
		mouseX <= sym._symbol_x1 + sym._symbol_width &&
		mouseY >= sym._symbol_y1 &&
		mouseY <= sym._symbol_y1 + sym._symbol_height) {

		sym._currentSize = sym._zoomSize;
	}
	else {
		sym._currentSize = sym._normalSize;
	}
}


int StageSymbol::_episodeID;
const char* StageSymbol::_EPISODE_TITLE;


void StageSymbol::ClickSymbolMark(const StageSymbol& mark) {

	int clickX = 0, clickY = 0;

	GetMousePoint(&clickX, &clickY);

	if (GetMouseInput() && MOUSE_INPUT_LEFT)
	{
		if (clickX >= mark._symbol_x1 && 
			clickX <= mark._symbol_x1 + mark._symbol_width &&
			clickY >= mark._symbol_y1 &&
			clickY <= mark._symbol_y1 + mark._symbol_height)
		{

			switch (mark._type)
			{
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
			}

			_onSelectedSymbol = true;
		}
	}
}


void StageSymbol::AddFuncsToSymbolButton() {

	static std::shared_ptr<StageSymbol[]> buttonArray;

	if(buttonArray == nullptr) 
		buttonArray = InstantiateButton();

	for (int i = 0; i < _SYMBOL_NUM; i++) {

		// インスタンス取得
		StageSymbol& btn = buttonArray[i];

		// 拡大縮小
		ZoomSymbolMark_OnMouse(btn);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, _symbol_alpha);

		// クリック
		ClickSymbolMark(btn);

		FadeIOSymbolMark();

		// ボタン画像描画
		DrawRotaGraph(btn._symbol_x1, btn._symbol_y1, btn._currentSize, 0.0f, btn._symbol_hdl, true);
	}
}


void StageSymbol::RenderSymbolMark() {

	AddFuncsToSymbolButton();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}