#pragma once

class DialogueButtons;


// プロローグとエピローグを管理（　SceneTitle_SelectMenuの次　と ステージ５開始時　）
class SceneConversation : public SceneBase
{
public:

	SceneConversation();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;

private:

	void ReleaseMem() override;

	//　キャラクター画像描画------------------------------------------------------------

	// プレイヤー
	void ShowPlayerImage_Prologue();
	void ShowPlayerImage_Epilogue();
	// 女神
	void ShowGoddessImage();
	// 少女
	void ShowGirlImage();
	// 最終ボス
	void ShowFinalBossImage();

	//　キャラクターのハイライト--------------------------------------------------------

	// プレイヤー
	void SetPlayersHighlight_Prologue();
	void SetPlayersHighlight_Epilogue();
	// 女神
	void SetGoddessHighlight();
	// 少女
	void SetGirlHighlight();
	// 最終ボス
	void SetFinalBossHighlight();

	//　テキスト--------------------------------------------------------------------------------

	void GetInputName_AtLast();     // 名前入力
	void SetPlayersName();          // 名前設定

	void PrintDialogueText();       // テキスト描画
	void PrintNextByInput();        // テキスト送り
	void Control_StoryLineStream();	// 上２つの関数を制御(エンターキー）

	//　--------------------------------------------------------------------------------
	void StartFinalBossBattle();    // 最終戦開始
	void MoveToStageMap();          // バトル終了後にマップに戻る

private:

	DialogueButtons* _buttons_ptr = nullptr;

public:

	// プロローグ（0）とエピローグ（1）の切り替え用
	static int Prologue_Epilogue;

	// テキストのインデックス
	static int _CURRENT_TEXTROW;

private:

	bool      _isSetPlayerBright = false;
	bool      _isSetGoddessBright = false;
	bool      _isSetGirlBright = false;
	bool      _isSetFinalBossBright = false;
		      
	bool      _showPlayer = false;
	bool      _showGoddess = false;
	bool      _showGirl = false;

	// ----------------------------------------
	int       _bg_hdl{};        // 背景ハンドル
	int       _inputName_hdl{}; // 名前ハンドル

	// テキスト----------------------------------------
	int       _printTextSpeed = 0;
	const int _printTextSpeed_adjustRate = 3;

private:

	std::string _PLAYER_NAME{};

	std::string _receiveText[140];
};