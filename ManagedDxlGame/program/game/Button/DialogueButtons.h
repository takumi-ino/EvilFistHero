#pragma once
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include <mutex>


class DialogueButtons
{
public:

	enum class ButtonType_Dialogue {

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
		int handle,
		int x, 
		int y, 
		int width,
		int height,
		float normalSize,
		float zoomSize, 
		ButtonType_Dialogue type
	) 	:
		handle(handle),
		btnX1(x),
		btnY1(y),
		width(width),
		height(height),
		BUTTON_SIZE_NORMAL_DIALOGUE(normalSize),
		BUTTON_SIZE_ZOOM_DIALOGUE(zoomSize),
		type_dialogue(type)
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

		handle = b.handle;
		btnX1 = b.btnX1;
		btnY1 = b.btnY1;
		width = b.width;
		height = b.height;
		_currentSize = b._currentSize;
		type_dialogue = b.type_dialogue;

		return *this;
	}

private:

	ButtonType_Dialogue type_dialogue{}; // �{�^���̎��

	int   handle{}; // �摜�̃n���h��
	int   width{};  // ��
	int   height{}; // ����

	int   btnX1{};    // x���W
	int   btnY1{};    // y���W

	float _currentSize{};
	float autoTimer = 0.0f;

	// �{�^���̊g�嗦
	const float BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool isShowStartAndBackButton{};
	bool autoText{};

private:

	std::mutex mtx;
};