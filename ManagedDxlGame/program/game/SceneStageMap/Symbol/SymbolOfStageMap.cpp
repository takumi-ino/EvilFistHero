#include "../../../utility/DxLib_Engine.h"
#include "SymbolOfStageMap.h"


namespace {

	const int   _SYMBOL_NUM = 6;

	// 各ステージシンボルのマップ上で表示する座標
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


std::shared_ptr<SymbolOfStageMap[]> SymbolOfStageMap::InstantiateButton() {

	std::shared_ptr<SymbolOfStageMap[]> buttonArray(new SymbolOfStageMap[_SYMBOL_NUM]);

	for (int i = 0; i < _SYMBOL_NUM; i++) {

		int buttonHandle = LoadGraph(_buttonImgPath_symbol[i]);

		int x = static_cast<int>(_SYMBOL_POS_ALL[i].x);
		int y = static_cast<int>(_SYMBOL_POS_ALL[i].y);
		int buttonWidth = static_cast<int>(_SYMBOL_POS_ALL[i].x + _symbolWidth);
		int buttonHeight = static_cast<int>(_SYMBOL_POS_ALL[i].y + _symbolHeight);

		// ボタンの種類を決める
		TYPE type = static_cast<TYPE>(i);

		// ボタンのインスタンスを作成して配列に格納
		buttonArray[i] = SymbolOfStageMap(
			buttonHandle, 
			x,
			y,
			buttonWidth, 
			buttonHeight, 
			0.09f, 
			0.12f,
			type
		);
	}
		return buttonArray;
}


void SymbolOfStageMap::FadeIOSymbolMark() {

	if (_isFadeIn) {             // IN

		_symbolAlpha --;

		if (_symbolAlpha <= 0)
		{
			_symbolAlpha = 0;
			_isFadeIn = false;
		}
	}
	else                         // OUT
	{
		_symbolAlpha ++;

		if (_symbolAlpha >= 255) {

			_symbolAlpha = 255;
			_isFadeIn = true;
		}
	}
}


void SymbolOfStageMap::ZoomSymbolMark_OnMouse(SymbolOfStageMap& sym) {

	int mouseX = 0, mouseY = 0;
	float scale = sym._NORMAL_SIZE;

	// マウスが画像上にある場合に拡大表示
	GetMousePoint(&mouseX, &mouseY);

	if (mouseX >= sym._symbol_x1 &&
		mouseX <= sym._symbol_x1 + sym._symbolWidth &&
		mouseY >= sym._symbol_y1 &&
		mouseY <= sym._symbol_y1 + sym._symbolHeight) {

		sym._currentSize = sym._ZOOM_SIZE;
	}
	else {
		sym._currentSize = sym._NORMAL_SIZE;
	}
}


int SymbolOfStageMap::_episodeID;
const char* SymbolOfStageMap::_EPISODE_TITLE;


void SymbolOfStageMap::ClickSymbolMark_ByMouse(const SymbolOfStageMap& mark) {

	int clickX = 0, clickY = 0;

	GetMousePoint(&clickX, &clickY);

	//　マウス左入力を取得
	if (GetMouseInput() && MOUSE_INPUT_LEFT)
	{
		if (clickX >= mark._symbol_x1 && 
			clickX <= mark._symbol_x1 + mark._symbolWidth &&
			clickY >= mark._symbol_y1 &&
			clickY <= mark._symbol_y1 + mark._symbolHeight)
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

				_EPISODE_TITLE = "番外編：？？？？？";
				break;
			}
			}

			_onSelectedSymbol = true;
		}
	}
}


void SymbolOfStageMap::ApplyFuncsToSymbolButton() {

	static std::shared_ptr<SymbolOfStageMap[]> buttonArray = nullptr;

	if (buttonArray == nullptr) {

		buttonArray = InstantiateButton();
	}

	for (int i = 0; i < _SYMBOL_NUM; i++) {

		// インスタンス取得
		SymbolOfStageMap& btn = buttonArray[i];

		// 拡大縮小
		ZoomSymbolMark_OnMouse(btn);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, _symbolAlpha);

		// クリック
		ClickSymbolMark_ByMouse(btn);

		//　画像のアルファ値の制御により、フェードイン・アウトを実行
		FadeIOSymbolMark();

		// ボタン画像描画
		DrawRotaGraph(
			btn._symbol_x1,
			btn._symbol_y1,
			btn._currentSize, 
			0.0f, 
			btn._symbolHandle,
			true
		);
	}
}


void SymbolOfStageMap::RenderSymbolMark() {

	ApplyFuncsToSymbolButton();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}