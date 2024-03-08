#include "DialogueButtons.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneStageMap/SceneStageMap.h"
#include "../Manager/ImageManager/use/ImageManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../ScenePlay/Battle/Scene_JankenBattle.h"
#include "../SceneStageMap/Symbol/StageSymbol.h"


namespace {

	// ボタンの数
	const int BUTTON_ALL_NUM_DIALOGUE = 7;

	// ボタンの初期位置
	const int BUTTON_POS_X_DIALOGUE = 125;
	const int BUTTON_POS_Y_DIALOGUE = 700;

	// ボタンの間隔
	const int BUTTON_INTERVAL_DIALOGUE = 170;

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
}


std::shared_ptr<DialogueButtons[]> DialogueButtons::Instantiate_DialogueButton() {

	std::shared_ptr<DialogueButtons[]> buttonArray(new DialogueButtons[BUTTON_ALL_NUM_DIALOGUE]);

	for (int i = 0; i < BUTTON_ALL_NUM_DIALOGUE; i++) {

		int handle = LoadGraph(_buttonImgPath_dialogue[i]);

		int x = BUTTON_POS_X_DIALOGUE + i * BUTTON_INTERVAL_DIALOGUE;
		int y = BUTTON_POS_Y_DIALOGUE;

		width = 30, height = 15;

		ButtonType_Dialogue type = (ButtonType_Dialogue)i;

		buttonArray[i] = DialogueButtons(handle, x, y, width, height, BUTTON_SIZE_NORMAL_DIALOGUE, BUTTON_SIZE_ZOOM_DIALOGUE, type);
	}

	return buttonArray;
}



void DialogueButtons::ManageDialogueButton() {

	static std::shared_ptr<DialogueButtons[]> buttonArray;

	if (buttonArray == nullptr)
		buttonArray = Instantiate_DialogueButton();

	// ボタンの描画と処理
	for (int i = 0; i < BUTTON_ALL_NUM_DIALOGUE; i++) {

		// 排他制御
		std::lock_guard<std::mutex> lock(mtx);

		DialogueButtons& btn = buttonArray[i];

		ZoomOnMouse_Dialogue(btn);
		ClickOnButton_Dialogue(btn);

		DrawRotaGraph(btn.btnX1, btn.btnY1, btn._currentSize, 0.0f, btn.handle, true);
	}
}



void DialogueButtons::RenderDialogueButtons() {

	ManageDialogueButton();
}



void DialogueButtons::ZoomOnMouse_Dialogue(DialogueButtons& btnInfo) {

	int hoveredX = 0, hoveredY = 0;

	GetMousePoint(&hoveredX, &hoveredY);

	if (hoveredX >= btnInfo.btnX1 &&
		hoveredX <= btnInfo.btnX1 + btnInfo.width && 
		hoveredY >= btnInfo.btnY1 &&
		hoveredY <= btnInfo.btnY1 + btnInfo.height)
	{
		btnInfo._currentSize = btnInfo.BUTTON_SIZE_ZOOM_DIALOGUE;
	}
	else {
		btnInfo._currentSize = btnInfo.BUTTON_SIZE_NORMAL_DIALOGUE;
	}
}



void DialogueButtons::ClickOnButton_Dialogue(const DialogueButtons& btnInfos) {

	int clickX_axis = 0, clickY_axis = 0;

	GetMousePoint(&clickX_axis, &clickY_axis);

	if (GetMouseInput() && MOUSE_INPUT_LEFT) {

		if (clickX_axis >= btnInfos.btnX1 && 
			clickX_axis <= btnInfos.btnX1 + btnInfos.width &&
			clickY_axis >= btnInfos.btnY1 && 
			clickY_axis <= btnInfos.btnY1 + btnInfos.height)
		{
			// ボタンの種類に応じて処理を分岐する
			switch (btnInfos.type_dialogue) {

			case ButtonType_Dialogue::TITLE: // TITLEボタン
			{
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneTitle());

				break;
			}
			case ButtonType_Dialogue::LOAD: // LOADボタン
			{
				break;
			}
			case ButtonType_Dialogue::SAVE: // SAVEボタン
			{
				break;
			}
			case ButtonType_Dialogue::AUTO: // AUTOボタン
			{
				autoText = !autoText;
				break;
			}
			case ButtonType_Dialogue::SKIP: // SKIPボタン
			{
				if (SceneConversation::Prologue_Epilogue == 1) {

					SceneStageMap ss;
					ss.SetStageInfo_BeforeStartGame(StageSymbol::Symbol::KINGDOM);

					return;
				}

				SceneConversation::_CURRENT_TEXTROW = 0;

				// ステージマップへ
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneStageMap());

				break;
			}
			case ButtonType_Dialogue::LOG: // LOGボタン
			{
				break;
			}
			case ButtonType_Dialogue::CONFIG: // CONFIGボタン
			{
				break;
			}
			}
		}
	}
}



void DialogueButtons::AutoDialogue() {

	if (!autoText) 	return;

	autoTimer += 0.02f;

	if (autoTimer >= 1.5f) {

		SceneConversation::_CURRENT_TEXTROW++;
		autoTimer = 0.0f;
	}
}