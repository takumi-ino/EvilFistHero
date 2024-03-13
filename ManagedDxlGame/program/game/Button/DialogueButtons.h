#pragma once
#include <mutex>


class DialogueButtons
{
public:

	enum class TYPE {

		TITLE,
		LOAD,
		SAVE,
		AUTO,
		SKIP,
		LOG,
		CONFIG
	};

	// �R���X�g���N�^------------------------------------------------------------
	DialogueButtons(){}
	DialogueButtons(const char*) {}

	// �R�s�[�R���X�g���N�^---------------------------------------------------
	DialogueButtons(
		int _button_hdl,
		int x, 
		int y, 
		int _button_width,
		int _button_height,
		float normalSize,
		float zoomSize, 
		TYPE type
	) 	:
		_button_hdl(_button_hdl),
		_button_x1(x),
		_button_y1(y),
		_button_width(_button_width),
		_button_height(_button_height),
		_BUTTON_SIZE_NORMAL_DIALOGUE(normalSize),
		_BUTTON_SIZE_ZOOM_DIALOGUE(zoomSize),
		_type_dialogue(type)
	{}

	//�@������------------------------------------------------------------
	std::shared_ptr<DialogueButtons[]> Instantiate_DialogueButton();

	//�@�@�\------------------------------------------------------------
	void ZoomOnMouse_Dialogue(DialogueButtons& buttonInfo);
	void ClickOnButton_Dialogue(const DialogueButtons& buttonInfo);
	void AutoDialogue();

	void ManageDialogueButton();	// Zoom �� Click �@�\���Ǘ�

	//�@�`��------------------------------------------------------------
	void RenderDialogueButtons();

public:

	// ���Z�q�I�[�o�[���[�h------------------------------------------------
	DialogueButtons& operator=(const DialogueButtons& b) {

		_button_hdl = b._button_hdl;
		_button_x1 = b._button_x1;
		_button_y1 = b._button_y1;
		_button_width = b._button_width;
		_button_height = b._button_height;
		_currentSize = b._currentSize;
		_type_dialogue = b._type_dialogue;

		return *this;
	}

private:

	TYPE _type_dialogue = DialogueButtons::TYPE::TITLE; // �{�^���̎��

	int   _button_hdl{};      // �摜�̃n���h��
	int   _button_width{};    // ��
	int   _button_height{};   // ����

	int   _button_x1{};       // x���W
	int   _button_y1{};       // y���W

	float _currentSize{};     // �{�^���T�C�Y
	float _autoTimer = 0.0f;  // �e�L�X�g�I�[�g�@�\�̃^�C�}�[

	// �{�^���̊g�嗦
	const float _BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float _BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool _isShowStartAndBackButton{};
	bool _autoText{};

private:

	std::mutex mtx;
};