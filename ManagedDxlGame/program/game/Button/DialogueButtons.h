#pragma once
#include <mutex>


// �v�����[�O(�^�C�g���Z���N�g���j���[��j�A�G�s���[�O�i�X�e�[�W�T���Ձj�ŕ\������{�^��
class DialogueButtons
{
public:

	//�@�e��{�^���B�@�\���܂܂�Ă��Ȃ����̂�����܂����A���o�Ƃ��Ďc���Ă��܂�
	enum class TYPE {

		TITLE,       // �^�C�g���֖߂�@�@�@�@o
		LOAD,		 //						  x
		SAVE,		 //						  x
		AUTO,		 // �e�L�X�g�I�[�g		  o
		SKIP,		 // �X�g�[���[�X�L�b�v	  o
		LOG,		 //						  x
		CONFIG		 //						  x
	};

	// �R���X�g���N�^------------------------------------------------------------
	DialogueButtons();
	DialogueButtons(const char*) {}

	// �R�s�[�R���X�g���N�^---------------------------------------------------
	DialogueButtons(
		int buttonHdl,
		int x,
		int y,
		int buttonWidth,
		int buttonHeight,
		float normalSize,
		float zoomSize,
		TYPE type
	) :
		_buttonHandle(buttonHdl),
		_buttonX1(x),
		_buttonY1(y),
		_buttonWidth(buttonWidth),
		_buttonHeight(buttonHeight),
		_BUTTON_SIZE_NORMAL_DIALOGUE(normalSize),
		_BUTTON_SIZE_ZOOM_DIALOGUE(zoomSize),
		_type(type)
	{}

	//�@������------------------------------------------------------------

    // ����
	std::shared_ptr<DialogueButtons[]> Instantiate_DialogueButton();

	//�@�@�\------------------------------------------------------------

	//�@�Y�[��
	void ZoomOnMouseCursor(DialogueButtons& buttonInfo);

	//�@�N���b�N
	void ClickByMouseCursor(const DialogueButtons& buttonInfo);

	//�@�e�L�X�g�I�[�g
	void AutoDialogue();

	// Zoom �� Click �@�\����
	void RenderDialogueButton();

public:

	// ���Z�q�I�[�o�[���[�h------------------------------------------------
	DialogueButtons& operator=(const DialogueButtons& b) {

		_buttonHandle = b._buttonHandle;
		_buttonX1 = b._buttonX1;
		_buttonY1 = b._buttonY1;
		_buttonWidth = b._buttonWidth;
		_buttonHeight = b._buttonHeight;
		_currentSize = b._currentSize;
		_type = b._type;

		return *this;
	}

private:

	TYPE        _type = DialogueButtons::TYPE::TITLE; // �{�^���̎��

	int         _buttonHandle{};    // �摜�̃n���h��
	int         _buttonWidth{};     // ��
	int         _buttonHeight{};    // ����

	int         _buttonX1{};        // x���W
	int         _buttonY1{};        // y���W

	float       _currentSize{};     // �{�^���T�C�Y
	float       _autoTimer = 0.0f;  // �e�L�X�g�I�[�g�@�\�̃^�C�}�[

	// �{�^���̊g�嗦
	const float _BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float _BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool        _isShowStartAndBackButton{};
	bool        _autoText{};

private:

	std::mutex  _mtx;
};