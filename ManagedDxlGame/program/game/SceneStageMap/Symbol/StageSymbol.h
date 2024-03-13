#pragma once
#include "../../Button/DialogueButtons.h"


class StageSymbol
{
public:

	enum Symbol {

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
		const int _button_hdl,
		const int x, 
		const int y,
		const int _button_width,
		const int _button_height,
		const float normalSize, 
		const float zoomSize, 
		const Symbol type
	) :
		_symbol_hdl(_button_hdl),
		_symbol_x1(x), _symbol_y1(y),
		_normalSize(normalSize),
		_zoomSize(zoomSize),
		_type(type)
	{}

	// �R�s�[�R���X�g���N�^-------------------------------------------------------------
	StageSymbol& operator=(const StageSymbol& ss) {

		_symbol_hdl = ss._symbol_hdl;
		_symbol_x1 = ss._symbol_x1;
		_symbol_y1 = ss._symbol_y1;
		_symbol_width = ss._symbol_width;
		_symbol_height = ss._symbol_height;
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
	void ClickSymbolMark(const StageSymbol& mark);

	//�@��L�R�̊֐������̒��ňꊇ����
	void AddFuncsToSymbolButton();

private:

	std::vector<StageSymbol> _buttonInfo_symbol;

public:

	static int         _episodeID;
	static const char* _EPISODE_TITLE;

	bool               _onSelectedSymbol{};

private:

	Symbol _type = Symbol::FOREST;

	int           _symbol_x1{};
	int           _symbol_y1{};
	int           _symbol_width = 20;
	int           _symbol_height = 20;
	int           _symbol_alpha = 255;
			    
	int           _symbol_hdl{};

	const float   _normalSize = 0.09f;
	const float   _zoomSize = 0.12f;
	float         _currentSize{};

	bool          _fadeIn_symbol = true;
};