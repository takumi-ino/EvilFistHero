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


	StageSymbol(){}
	


	StageSymbol(
		const int handle,
		const float x, 
		const float y,
		const int width,
		const int height,
		const float normalSize, 
		const float zoomSize, 
		const Symbol type) :

		_handle(handle),
		_x(x), _y(y),
		_normalSize(normalSize),
		_zoomSize(zoomSize),
		_type_symbol(type)
	{}



	StageSymbol& operator=(const StageSymbol& ss) {

		_handle = ss._handle;
		_x = ss._x;
		_y = ss._y;
		_width = ss._width;
		_height = ss._height;
		_type_symbol = ss._type_symbol;

		return *this;
	}


	void RenderSymbolMark();
	std::shared_ptr<StageSymbol[]> InstantiateButton();

private:

	void FadeIOSymbolMark();
	void ZoomSymbolMark_OnMouse(StageSymbol& buttonInfo);
	void ClickFunc_SymbolMark(const StageSymbol& buttonInfo);


	void AddFuncsToSymbolButton();

private:


	std::vector<StageSymbol> _buttonInfo_symbol;

private:

	static int _buttonHandle_symbol[6];

	int _symbol_alpha = 255;
	int _handle;	// ‰æ‘œ‚Ìƒnƒ“ƒhƒ‹ 
	int _x, _y;

	float _currentSize;
	bool _fadeIn_symbol = true;

	const int _SYMBOL_NUM = 6;

	const char* _buttonImgPath_symbol[6] =
	{
	"graphics/Symbols/Forest.png",
	"graphics/Symbols/Village.png",
	"graphics/Symbols/City.png",
	"graphics/Symbols/Theocracy.png",
	"graphics/Symbols/Kingdom.png",
	"graphics/Symbols/Continent.png"
	};

public:

	static const char* _EPISODE_TITLE;
	static int _episodeID;

	Symbol _type_symbol;

	int _width = 20;
	int _height = 20;

	float _normalSize = 0.09f;
	float _zoomSize = 0.12f;

	bool _onSelectedSymbol;

	const tnl::Vector3 FOREST_SYMBOL_POS = { 357, 95, 0 };
	const tnl::Vector3 VILLAGE_SYMBOL_POS = { 787, 265, 0 };
	const tnl::Vector3 CITY_SYMBOL_POS = { 950, 580, 0 };
	const tnl::Vector3 THEOCRACY_SYMBOL_POS = { 455, 680, 0 };
	const tnl::Vector3 KINGDOM_SYMBOL_POS = { 484, 285, 0 };
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
};