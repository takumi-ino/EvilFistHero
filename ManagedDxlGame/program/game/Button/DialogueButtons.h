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

	// コンストラクタ------------------------------------------------------------
	DialogueButtons(){}
	DialogueButtons(const char*) {}

	// コピーコンストラクタ---------------------------------------------------
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

	//　初期化------------------------------------------------------------
	std::shared_ptr<DialogueButtons[]> Instantiate_DialogueButton();

	//　機能------------------------------------------------------------
	void ZoomOnMouse_Dialogue(DialogueButtons& buttonInfo);
	void ClickOnButton_Dialogue(const DialogueButtons& buttonInfo);
	void AutoDialogue();

	void ManageDialogueButton();	// Zoom と Click 機能を管理

	//　描画------------------------------------------------------------
	void RenderDialogueButtons();

public:

	// 演算子オーバーロード------------------------------------------------
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

	ButtonType_Dialogue type_dialogue{}; // ボタンの種類

	int   handle{}; // 画像のハンドル
	int   width{};  // 幅
	int   height{}; // 高さ

	int   btnX1{};    // x座標
	int   btnY1{};    // y座標

	float _currentSize{};
	float autoTimer = 0.0f;

	// ボタンの拡大率
	const float BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool isShowStartAndBackButton{};
	bool autoText{};

private:

	std::mutex mtx;
};