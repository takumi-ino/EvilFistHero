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

	// �R���X�g���N�^-------------------------------------------------------------------
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

	// �R�s�[�R���X�g���N�^-------------------------------------------------------------
	SymbolOfStageMap& operator=(const SymbolOfStageMap& stSymbol) {

		_symbolHandle = stSymbol._symbolHandle;
		_symbol_x1 = stSymbol._symbol_x1;
		_symbol_y1 = stSymbol._symbol_y1;
		_symbolWidth = stSymbol._symbolWidth;
		_symbolHeight = stSymbol._symbolHeight;
		_type = stSymbol._type;

		return *this;
	}

	// �}�b�v��ɕ\������Ă���{�^�� (�X�e�[�W�V���{���摜)�̏�����
	std::shared_ptr<SymbolOfStageMap[]> InstantiateButton();

	// �X�e�[�W�}�b�v�ɕ\������e�X�e�[�W�̃V���{����`��
	void RenderSymbolMark();

private:

	// �t�F�[�h�C���E�t�F�[�h�A�E�g����
	void FadeIOSymbolMark();

	// �}�E�X�J�[�\�������킹���Ƃ��̃Y�[���@�\
	void ZoomSymbolMark_OnMouse(SymbolOfStageMap& buttonInfo);

	// �}�E�X�N���b�N
	void ClickSymbolMark_ByMouse(const SymbolOfStageMap& mark);

	//�@��L�R�̊֐������̒��ňꊇ����
	void ApplyFuncsToSymbolButton();

private:

	std::vector<SymbolOfStageMap> _symbolButtonInfo;

public:

	static int         _episodeID;         // �X�e�[�W�ԍ�

	static const char* _EPISODE_TITLE;     // �X�e�[�W�^�C�g��

	bool               _onSelectedSymbol{};

private:

	TYPE        _type = TYPE::FOREST;

	int           _symbol_x1{};            // X���W
	int           _symbol_y1{};			   // Y���W
	int           _symbolWidth = 20;	   // ��
	int           _symbolHeight = 20;	   // ����
	int           _symbolAlpha = 255;	   // �A���t�@�l

	int           _symbolHandle{};		   // �摜�n���h��

	const float   _NORMAL_SIZE = 0.09f;	   // �ʏ�T�C�Y
	const float   _ZOOM_SIZE = 0.12f;	   // �g��T�C�Y
	float         _currentSize{};		   // ���݂̃T�C�Y

	bool          _isFadeIn = true;		   // �t�F�[�h�C���A�t�F�[�h�A�E�g����
};