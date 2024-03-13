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

	// コンストラクタ------------------------------------------------------------
	DialogueButtons(){}
	DialogueButtons(const char*) {}

	// コピーコンストラクタ---------------------------------------------------
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

	TYPE _type_dialogue = DialogueButtons::TYPE::TITLE; // ボタンの種類

	int   _button_hdl{};      // 画像のハンドル
	int   _button_width{};    // 幅
	int   _button_height{};   // 高さ

	int   _button_x1{};       // x座標
	int   _button_y1{};       // y座標

	float _currentSize{};     // ボタンサイズ
	float _autoTimer = 0.0f;  // テキストオート機能のタイマー

	// ボタンの拡大率
	const float _BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float _BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool _isShowStartAndBackButton{};
	bool _autoText{};

private:

	std::mutex mtx;
};