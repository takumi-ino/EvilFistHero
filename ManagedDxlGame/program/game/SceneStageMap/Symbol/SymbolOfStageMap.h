#pragma once
#include "../../Button/DialogueButtons.h"


class SymbolOfStageMap
{
public:

	enum TYPE {

		FOREST = 1,
		VILLAGE,
		CITY,   
		THEOCRACY, 
		KINGDOM,  
		CONTINENT 
	};

	// コンストラクタ-------------------------------------------------------------------
	SymbolOfStageMap(){}
	SymbolOfStageMap(
		const int symbolButtonHandle,
		const int symbolButton_x,
		const int symbolButton_y,
		const int symbolButtonWidth,
		const int symbolButtonHeight,
		const float symbolButtonNormalSize,
		const float symbolButtonZoomSize,
		const TYPE symbolButtonType
	) :
		_symbolHandle(symbolButtonHandle),
		_symbol_x1(symbolButton_x),
		_symbol_y1(symbolButton_y),
		_NORMAL_SIZE(symbolButtonNormalSize),
		_ZOOM_SIZE(symbolButtonZoomSize),
		_type(symbolButtonType)
	{}

	// コピーコンストラクタ-------------------------------------------------------------
	SymbolOfStageMap& operator=(const SymbolOfStageMap& stSymbol) {

		_symbolHandle = stSymbol._symbolHandle;
		_symbol_x1 = stSymbol._symbol_x1;
		_symbol_y1 = stSymbol._symbol_y1;
		_symbolWidth = stSymbol._symbolWidth;
		_symbolHeight = stSymbol._symbolHeight;
		_type = stSymbol._type;

		return *this;
	}

	// マップ上に表示されているボタン (ステージシンボル画像)の初期化
	std::shared_ptr<SymbolOfStageMap[]> InstantiateButton();

	// ステージマップに表示する各ステージのシンボルを描画
	void RenderSymbolMark();

private:

	// フェードイン・フェードアウト処理
	void FadeIOSymbolMark();

	// マウスカーソルを合わせたときのズーム機能
	void ZoomSymbolMark_OnMouse(SymbolOfStageMap& buttonInfo);

	// マウスクリック
	void ClickSymbolMark_ByMouse(const SymbolOfStageMap& mark);

	//　上記３つの関数をこの中で一括処理
	void ApplyFuncsToSymbolButton();

private:

	std::vector<SymbolOfStageMap> _symbolButtonInfo;

public:

	static int         _episodeID;         // ステージ番号

	static const char* _EPISODE_TITLE;     // ステージタイトル

	bool               _onSelectedSymbol{};

private:

	TYPE        _type = TYPE::FOREST;

	int           _symbol_x1{};            // X座標
	int           _symbol_y1{};			   // Y座標
	int           _symbolWidth = 20;	   // 幅
	int           _symbolHeight = 20;	   // 高さ
	int           _symbolAlpha = 255;	   // アルファ値

	int           _symbolHandle{};		   // 画像ハンドル

	const float   _NORMAL_SIZE = 0.09f;	   // 通常サイズ
	const float   _ZOOM_SIZE = 0.12f;	   // 拡大サイズ
	float         _currentSize{};		   // 現在のサイズ

	bool          _isFadeIn = true;		   // フェードイン、フェードアウト制御
};