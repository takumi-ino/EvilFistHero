#pragma once
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"


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


	DialogueButtons(){}
	DialogueButtons(const char* ch) {}

	DialogueButtons(
		int handle,
		float x, 
		float y, 
		int width,
		int height,
		float normalSize,
		float zoomSize, 
		ButtonType_Dialogue type) 
		:
		handle(handle),
		x(x), y(y),
		width(width), height(height),
		BUTTON_SIZE_NORMAL_DIALOGUE(normalSize),
		BUTTON_SIZE_ZOOM_DIALOGUE(zoomSize),
		_type_dialogue(type)
	{}


	void Render_FuncButtons_Dialogue();

	std::shared_ptr<DialogueButtons[]> Instantiate_DialogueButton();


	void ZoomFunc_OnMouse_Dialogue(DialogueButtons& buttonInfo);

	void ClickFunc_OnButton_Dialogue(const DialogueButtons& buttonInfo);

	void Auto_Dialogue();

	// Zoom と Click 機能を追加しボタンの処理を管理
	void ManageFuncs_DialogueButton();


public:


	DialogueButtons& operator=(const DialogueButtons& b) {

		handle = b.handle;
		x = b.x;
		y = b.y;
		width = b.width;
		height = b.height;
		_currentSize = b._currentSize;
		_type_dialogue = b._type_dialogue;

		return *this;
	}


	int handle; // 画像のハンドル
	int width;  // 幅
	int height; // 高さ

	float x;    // x座標
	float y;    // y座標
	float _currentSize;

	bool _autoText;

	std::vector<DialogueButtons> _buttonInfo_dialogue;

	const char* _buttonImgPath_dialogue[7] =
	{
	"graphics/Buttons/TitleFuncBtn.png",
	"graphics/Buttons/LoadFuncBtn.png",
	"graphics/Buttons/SaveFuncBtn.png",
	"graphics/Buttons/AutoFuncBtn.png",
	"graphics/Buttons/SkipFuncBtn.png",
	"graphics/Buttons/LogFuncBtn.png",
	"graphics/Buttons/ConfigFuncBtn.png",
	};

	// ボタンの数
	const int BUTTON_ALL_NUM_DIALOGUE = 7;

	// ボタンの初期位置
	const int BUTTON_POS_X_DIALOGUE = 125;
	const int BUTTON_POS_Y_DIALOGUE = 700;

	// ボタンの間隔
	const int BUTTON_INTERVAL_DIALOGUE = 170;

	// ボタンの拡大率
	const float BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool isShowStartAndBackButton;

	float _autoTimer = 0.0f;

	ButtonType_Dialogue _type_dialogue; // ボタンの種類
};