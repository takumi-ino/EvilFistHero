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

	// �R���X�g���N�^-------------------------------------------------------------------
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

	// �R�s�[�R���X�g���N�^-------------------------------------------------------------
	StageSymbol& operator=(const StageSymbol& ss) {

		_handle = ss._handle;
		_x1 = ss._x1;
		_y1 = ss._y1;
		_width = ss._width;
		_height = ss._height;
		_type = ss._type;

		return *this;
	}

	// �}�b�v��ɕ\������Ă���{�^�� (�X�e�[�W�V���{���摜)�̏�����
	std::shared_ptr<StageSymbol[]> InstantiateButton();

	// �X�e�[�W�}�b�v�ɕ\������e�X�e�[�W�̃V���{����`��
	void RenderSymbolMark();

private:

	// �t�F�[�h�C���E�t�F�[�h�A�E�g����
	void FadeIOSymbolMark();

	// �}�E�X�J�[�\�������킹���Ƃ��̃Y�[���@�\
	void ZoomSymbolMark_OnMouse(StageSymbol& buttonInfo);

	// �}�E�X�N���b�N
	void ClickFunc_SymbolMark(const StageSymbol& buttonInfo);

	//�@��L�R�̊֐������̒��ňꊇ����
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