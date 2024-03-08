#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include "../../Manager/SoundManager/SoundManager.h"
#include "../../Manager/SceneManager/SceneManager.h"
#include "SceneConversation.h"


int SceneConversation::_CURRENT_TEXTROW = 0;
int SceneConversation::Prologue_Epilogue = 0;


SceneConversation::SceneConversation() {

	_buttons_ptr = new DialogueButtons();

	ImageManager::GetInstance().SetBackGroundMapKey();
	ImageManager::GetInstance().SetCharacterMapKey();
}


void SceneConversation::Render(float deltaTime) {


	SetDrawBright(255, 255, 255);

	SetFontSize(20);
	DrawBox(0, 500, 1280, 800, GetColor(20, 20, 20), true);

	// テキスト描画
	PrintDialogueText();
	PrintNextByInput();

	// ボタン描画
	_buttons_ptr->RenderDialogueButtons();
	_buttons_ptr->AutoDialogue();

	SetFontSize(22);
	DrawStringEx(90, 550, -1, "%s", receiveText[_CURRENT_TEXTROW].c_str());

	SetFontSize(35);
	DrawString(1070, 620, "Enter", -1);
}



void SceneConversation::Update(float deltaTime) {

	_sequence.update(deltaTime);
}



void SceneConversation::PrintDialogueText() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		for (int i = 0; i < 140; ++i) {

			receiveText[i] = prologueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			receiveText[_CURRENT_TEXTROW] = prologueTextLog[_CURRENT_TEXTROW].substr(0, _strCount);
		}
	}
	else {

		for (int i = 0; i < 140; ++i) {

			receiveText[i] = epilogueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			receiveText[_CURRENT_TEXTROW] = epilogueTextLog[_CURRENT_TEXTROW].substr(0, _strCount);
		}
	}
}


void SceneConversation::PrintNextByInput() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// エンターで文字送り
		if (prologueTextLog[_CURRENT_TEXTROW].length() > _strCount) {
			 
			_strCount += _printSpeedAdj;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (prologueTextLog[_CURRENT_TEXTROW].length() <= _strCount)) {

			_CURRENT_TEXTROW++;
			_strCount = 0;
		}
	}
	else {

		// エンターで文字送り
		if (epilogueTextLog[_CURRENT_TEXTROW].length() > _strCount) {

			_strCount += _printSpeedAdj;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (epilogueTextLog[_CURRENT_TEXTROW].length() <= _strCount)) {

			_CURRENT_TEXTROW++;
			_strCount = 0;
		}
	}
}


void SceneConversation::Control_StoryLineStream() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// 背景画像---------------------------------------------------------------------

		if (_CURRENT_TEXTROW == 9)
			ImageManager::GetInstance().LoadBackGroundImage("プロローグ");

		if (_CURRENT_TEXTROW >= 9 && _CURRENT_TEXTROW < 68)
			ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		if (_CURRENT_TEXTROW == 71)
			ImageManager::GetInstance().LoadBackGroundImage("夜");

		if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW < 127)
			ImageManager::GetInstance().RenderBackGroundImage(500, 50, 1.0f, 1);


		// キャラクター画像-------------------------------------------------------------
		ShowPlayerImage_Prologue();
		ShowGoddessImage();
		ShowGirlImage();
		// ハイライト
		SetPlayersHighlight_Prologue();
		SetGoddessHighlight();
		SetGirlHighlight();
		// 名前入力
		//SetPlayersName();
	}
	else {

		if (_CURRENT_TEXTROW == 0)
			ImageManager::GetInstance().LoadBackGroundImage("エピローグ");

		ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		//　エピローグ
		ShowPlayerImage_Epilogue();
		SetPlayersHighlight_Epilogue();
		ShowFinalBossImage();
		SetFinalBossHighlight();
	}
}



bool SceneConversation::SeqIdle(float deltaTime) {

	if (prologueTextLog[_CURRENT_TEXTROW] == "次のシーンへ") {

		// ポインタ初期化
		_buttons_ptr = _INIT_BUTTON_PTR;

		_CURRENT_TEXTROW = 0;

		// ステージマップで表示するシンボルを初期化
		[](StageSymbol* ss) {

			ss = new StageSymbol();
			ss->InstantiateButton();
			delete ss;
			ss = nullptr;
			};

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneStageMap());
	}

	if (epilogueTextLog[_CURRENT_TEXTROW] == "バトル開始") {

		SceneStageMap ss;

		ss.SetStageInfo_BeforeStartGame(StageSymbol::Symbol::KINGDOM);

	}

	Control_StoryLineStream();

	return true;
}


void SceneConversation::ShowPlayerImage_Prologue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW < 68) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW > 72) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
}


void SceneConversation::SetPlayersHighlight_Prologue() {

	if (_CURRENT_TEXTROW == 9 || _CURRENT_TEXTROW == 12 || _CURRENT_TEXTROW == 16 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 ||
		_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 ||
		_CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 54 ||
		_CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 ||
		_CURRENT_TEXTROW == 71 || _CURRENT_TEXTROW == 76 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 88 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 107 || _CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 125) {

		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}



void SceneConversation::ShowPlayerImage_Epilogue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else 
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW < 77) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
}



void SceneConversation::SetPlayersHighlight_Epilogue() {

	if (_CURRENT_TEXTROW == 5 || _CURRENT_TEXTROW == 11 || _CURRENT_TEXTROW == 17 || _CURRENT_TEXTROW == 23 ||
		_CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 56 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 70)
	{
		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}



void SceneConversation::ShowGoddessImage() {

	if (_isSetGoddessBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) 	   
		ImageManager::GetInstance().LoadCharacterImage("シルエット＿女神");

	if (_CURRENT_TEXTROW < 20) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "シルエット＿女神");
	}
	else if (_CURRENT_TEXTROW >= 20) {

		if (_CURRENT_TEXTROW == 20) 
			ImageManager::GetInstance().LoadCharacterImage("ノーマル＿女神");

		if (_CURRENT_TEXTROW == 20 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 || _CURRENT_TEXTROW == 23 ||
			_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 25 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 32 ||
			_CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 58 ||
			_CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 66 || _CURRENT_TEXTROW == 67) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "ノーマル＿女神");
		}

		if (_CURRENT_TEXTROW == 28) 
			ImageManager::GetInstance().LoadCharacterImage("真剣＿女神");

		if (_CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 29 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 35 ||
			_CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47 || _CURRENT_TEXTROW == 48 ||
			_CURRENT_TEXTROW == 49 || _CURRENT_TEXTROW == 50 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 52 || _CURRENT_TEXTROW == 53 ||
			_CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 56 || _CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 61 ||
			_CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 63 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 65) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "真剣＿女神");
		}

		if (_CURRENT_TEXTROW == 33) 
			ImageManager::GetInstance().LoadCharacterImage("笑顔＿女神");

		if (_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 37 ||
			_CURRENT_TEXTROW == 40 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "笑顔＿女神");
		}
	}
}

void SceneConversation::SetGoddessHighlight() {

	if (_CURRENT_TEXTROW == 10 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 32 ||
		_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 37 || _CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 40 ||
		_CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45 || _CURRENT_TEXTROW == 46 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 66)
	{
		_isSetGoddessBright = true;
	}
	else {
		_isSetGoddessBright = false;
	}
}


void SceneConversation::ShowGirlImage() {


	if (_isSetGirlBright) 	
		SetDrawBright(255, 255, 255);
	else 		           
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 71)	
		ImageManager::GetInstance().LoadCharacterImage("シルエット＿少女");

	if (_CURRENT_TEXTROW > 71 && _CURRENT_TEXTROW <= 80)
		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "シルエット＿少女");

	if (_CURRENT_TEXTROW == 81)
		ImageManager::GetInstance().LoadCharacterImage("ノーマル＿少女");

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 83 ||
		_CURRENT_TEXTROW == 84 || _CURRENT_TEXTROW == 87 || _CURRENT_TEXTROW == 88 || _CURRENT_TEXTROW == 97 ||
		_CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 115) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "ノーマル＿少女");
	}

	if (_CURRENT_TEXTROW == 85) 
		ImageManager::GetInstance().LoadCharacterImage("真剣＿少女");

	if (_CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 113) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "真剣＿少女");
	}

	if (_CURRENT_TEXTROW == 93)	
		ImageManager::GetInstance().LoadCharacterImage("笑顔＿少女");

	if (_CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 94 || _CURRENT_TEXTROW == 98 || _CURRENT_TEXTROW == 99 ||
		_CURRENT_TEXTROW == 100 || _CURRENT_TEXTROW == 101 || _CURRENT_TEXTROW == 102 ||
		_CURRENT_TEXTROW == 103 || _CURRENT_TEXTROW == 104 || _CURRENT_TEXTROW == 105 ||
		_CURRENT_TEXTROW == 105 || _CURRENT_TEXTROW == 106 || _CURRENT_TEXTROW == 107 ||
		_CURRENT_TEXTROW == 108 || _CURRENT_TEXTROW == 109 || _CURRENT_TEXTROW == 110 ||
		_CURRENT_TEXTROW == 111 || _CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 ||
		_CURRENT_TEXTROW == 123 || _CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 125 || _CURRENT_TEXTROW == 126) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "笑顔＿少女");
	}

	if (_CURRENT_TEXTROW == 89)
		ImageManager::GetInstance().LoadCharacterImage("怒り2＿少女");

	if (_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 90 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 92) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "怒り2＿少女");
	}

	if (_CURRENT_TEXTROW == 116) 
		ImageManager::GetInstance().LoadCharacterImage("怒り1＿少女");

	if (_CURRENT_TEXTROW == 116 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 118 ||
		_CURRENT_TEXTROW == 119 || _CURRENT_TEXTROW == 120) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "怒り1＿少女");
	}
}


void SceneConversation::SetGirlHighlight() {

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 87 ||
		_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 97 || _CURRENT_TEXTROW == 98 ||
		_CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 116 ||
		_CURRENT_TEXTROW == 118 || _CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 ||
		_CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 126)
	{
		_isSetGirlBright = true;
	}
	else {
		_isSetGirlBright = false;
	}
}


void SceneConversation::ShowFinalBossImage() {

	if (_isSetFinalBossBright) 	
		SetDrawBright(255, 255, 255);
	else 		               
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 19)	   
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿シルエット");

	if (_CURRENT_TEXTROW >= 19 && _CURRENT_TEXTROW <= 34)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿シルエット");

	if (_CURRENT_TEXTROW == 35)		
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW >= 35 && _CURRENT_TEXTROW <= 39)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW == 40) 
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿デフォルト");

	if (_CURRENT_TEXTROW >= 40 && _CURRENT_TEXTROW <= 43)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿デフォルト");

	if (_CURRENT_TEXTROW == 44)	   
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW >= 44 && _CURRENT_TEXTROW <= 54)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW == 55)	   
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿笑顔");

	if (_CURRENT_TEXTROW >= 55 && _CURRENT_TEXTROW <= 56)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿笑顔");

	if (_CURRENT_TEXTROW == 57)	
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿デフォルト");

	if (_CURRENT_TEXTROW >= 57 && _CURRENT_TEXTROW <= 58)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿デフォルト");

	if (_CURRENT_TEXTROW == 59)		
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW >= 59 && _CURRENT_TEXTROW <= 70)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW == 71)		
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_2");

	if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW <= 72)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_2");

	if (_CURRENT_TEXTROW == 73)		
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW >= 73 && _CURRENT_TEXTROW <= 74)
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");

	if (_CURRENT_TEXTROW == 75) 	
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_4");

	if (_CURRENT_TEXTROW >= 75)	
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_4");
}


void SceneConversation::SetFinalBossHighlight() {

	if (_CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 40
		|| _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47
		|| _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 57
		|| _CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 63
		|| _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 71
		|| _CURRENT_TEXTROW == 73 || _CURRENT_TEXTROW == 75) 
	{
		_isSetFinalBossBright = true;
	}
	else {
		_isSetFinalBossBright = false;
	}
}


void SceneConversation::SetPlayersName() {

	GetInputName_AtLast();

	SetDrawBright(200, 200, 200);

	SetActiveKeyInput(_inputName_hdl);

	// 入力モードを描画
	DrawKeyInputModeString(640, 480);

	// 入力途中の文字列を描画
	DrawKeyInputString(0, 0, _inputName_hdl);

	char buff[256];
	GetKeyInputString(buff, _inputName_hdl);
	PLAYER_NAME = buff;

	DrawStringEx(100, 300, -1, "%s", PLAYER_NAME.c_str());
}



void SceneConversation::GetInputName_AtLast() {

	if (prologueTextLog[_CURRENT_TEXTROW] == "名前入力") {
		prologueTextLog[_CURRENT_TEXTROW] = "名前を入力してください";
	}
}



void SceneConversation::ReleaseMem() {

	DeleteGraph(_bg_hdl);
}