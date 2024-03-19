#pragma once
#include <mutex>


// プロローグ(タイトルセレクトメニュー後）、エピローグ（ステージ５序盤）で表示するボタン
class DialogueButtons
{
public:

	//　各種ボタン。機能が含まれていないものもありますが、演出として残しています
	enum class TYPE {

		TITLE,       // タイトルへ戻る　　　　o
		LOAD,		 //						  x
		SAVE,		 //						  x
		AUTO,		 // テキストオート		  o
		SKIP,		 // ストーリースキップ	  o
		LOG,		 //						  x
		CONFIG		 //						  x
	};

	// コンストラクタ------------------------------------------------------------
	DialogueButtons();
	DialogueButtons(const char*) {}

	// コピーコンストラクタ---------------------------------------------------
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

	//　初期化------------------------------------------------------------

    // 生成
	std::shared_ptr<DialogueButtons[]> Instantiate_DialogueButton();

	//　機能------------------------------------------------------------

	//　ズーム
	void ZoomOnMouseCursor(DialogueButtons& buttonInfo);

	//　クリック
	void ClickByMouseCursor(const DialogueButtons& buttonInfo);

	//　テキストオート
	void AutoDialogue();

	// Zoom と Click 機能搭載
	void RenderDialogueButton();

public:

	// 演算子オーバーロード------------------------------------------------
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

	TYPE        _type = DialogueButtons::TYPE::TITLE; // ボタンの種類

	int         _buttonHandle{};    // 画像のハンドル
	int         _buttonWidth{};     // 幅
	int         _buttonHeight{};    // 高さ

	int         _buttonX1{};        // x座標
	int         _buttonY1{};        // y座標

	float       _currentSize{};     // ボタンサイズ
	float       _autoTimer = 0.0f;  // テキストオート機能のタイマー

	// ボタンの拡大率
	const float _BUTTON_SIZE_NORMAL_DIALOGUE = 0.12f;
	const float _BUTTON_SIZE_ZOOM_DIALOGUE = 0.15f;

	bool        _isShowStartAndBackButton{};
	bool        _autoText{};

private:

	std::mutex  _mtx;
};