#pragma once
#include "../../../utility/DxLib_Engine.h"
#include "../../../utility/tnlSequence.h"
#include "../../Button/DialogueButtons.h"

class DialogueButtons;

class StageSymbol
{
public:

	static enum Symbol {

		FOREST = 1,
		VILLAGE,
		CITY,   
		THEOCRACY, 
		KINGDOM,  
		CONTINENT 
	};

	// コンストラクタ-------------------------------------------------------------------
	StageSymbol(){}
	StageSymbol(
		const int handle,
		const int x, 
		const int y,
		const int width,
		const int height,
		const float normalSize, 
		const float zoomSize, 
		const Symbol type
	) :
		_handle(handle),
		_x1(x), _y1(y),
		_normalSize(normalSize),
		_zoomSize(zoomSize),
		_type(type)
	{}

	// コピーコンストラクタ-------------------------------------------------------------
	StageSymbol& operator=(const StageSymbol& ss) {

		_handle = ss._handle;
		_x1 = ss._x1;
		_y1 = ss._y1;
		_width = ss._width;
		_height = ss._height;
		_type = ss._type;

		return *this;
	}

	// マップ上に表示されているボタン (ステージシンボル画像)の初期化
	std::shared_ptr<StageSymbol[]> InstantiateButton();

	// ステージマップに表示する各ステージのシンボルを描画
	void RenderSymbolMark();

private:

	// フェードイン・フェードアウト処理
	void FadeIOSymbolMark();

	// マウスカーソルを合わせたときのズーム機能
	void ZoomSymbolMark_OnMouse(StageSymbol& buttonInfo);

	// マウスクリック
	void ClickFunc_SymbolMark(const StageSymbol& buttonInfo);

	//　上記３つの関数をこの中で一括処理
	void AddFuncsToSymbolButton();

private:

	std::vector<StageSymbol> _buttonInfo_symbol;

public:

	Symbol _type = Symbol::FOREST;

	static const char* EPISODE_TITLE;
	static int         episodeID;

	bool  onSelectedSymbol{};

	const tnl::Vector3 FOREST_SYMBOL_POS =    { 357,  95, 0 };
	const tnl::Vector3 VILLAGE_SYMBOL_POS =   { 787, 265, 0 };
	const tnl::Vector3 CITY_SYMBOL_POS =      { 950, 580, 0 };
	const tnl::Vector3 THEOCRACY_SYMBOL_POS = { 455, 680, 0 };
	const tnl::Vector3 KINGDOM_SYMBOL_POS =   { 484, 285, 0 };
	const tnl::Vector3 CONTINENT_SYMBOL_POS = { 235, 400, 0 };

	const tnl::Vector3 _SYMBOL_POS_ALL[6] =
	{
		StageSymbol::FOREST_SYMBOL_POS,
		StageSymbol::VILLAGE_SYMBOL_POS,
		StageSymbol::CITY_SYMBOL_POS,
		StageSymbol::THEOCRACY_SYMBOL_POS,
		StageSymbol::KINGDOM_SYMBOL_POS,
		StageSymbol::CONTINENT_SYMBOL_POS
	};

private:

	int         _x1{};
	int         _y1{};
	int         _width = 20;
	int         _height = 20;

	int         _symbol_alpha = 255;
	int         _handle{};

	float       _normalSize = 0.09f;
	float       _zoomSize = 0.12f;
	float       _currentSize{};

	bool        _fadeIn_symbol = true;

	static int  _buttonHandle_symbol[6];
	const int   _SYMBOL_NUM = 6;
	
	const char* _buttonImgPath_symbol[6] =
	{
	"graphics/Symbols/Forest.png",
	"graphics/Symbols/Village.png",
	"graphics/Symbols/City.png",
	"graphics/Symbols/Theocracy.png",
	"graphics/Symbols/Kingdom.png",
	"graphics/Symbols/Continent.png"
	};
};