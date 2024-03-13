#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "DialogueButtons.h"
#include "../SceneStageMap/SceneStageMap.h"
#include "../Manager/ImageManager/use/ImageManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
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

		int _button_hdl = LoadGraph(_buttonImgPath_dialogue[i]);

		int x = BUTTON_POS_X_DIALOGUE + i * BUTTON_INTERVAL_DIALOGUE;
		int y = BUTTON_POS_Y_DIALOGUE;

		_button_width = 30, _button_height = 15;

		TYPE type = (TYPE)i;

		buttonArray[i] = DialogueButtons(_button_hdl, x, y, _button_width, _button_height, _BUTTON_SIZE_NORMAL_DIALOGUE, _BUTTON_SIZE_ZOOM_DIALOGUE, type);
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

		DrawRotaGraph(btn._button_x1, btn._button_y1, btn._currentSize, 0.0f, btn._button_hdl, true);
	}
}



void DialogueButtons::RenderDialogueButtons() {

	ManageDialogueButton();
}



void DialogueButtons::ZoomOnMouse_Dialogue(DialogueButtons& btnInfo) {

	int hoveredX = 0, hoveredY = 0;

	GetMousePoint(&hoveredX, &hoveredY);

	if (hoveredX >= btnInfo._button_x1 &&
		hoveredX <= btnInfo._button_x1 + btnInfo._button_width && 
		hoveredY >= btnInfo._button_y1 &&
		hoveredY <= btnInfo._button_y1 + btnInfo._button_height)
	{
		btnInfo._currentSize = btnInfo._BUTTON_SIZE_ZOOM_DIALOGUE;
	}
	else {
		btnInfo._currentSize = btnInfo._BUTTON_SIZE_NORMAL_DIALOGUE;
	}
}



void DialogueButtons::ClickOnButton_Dialogue(const DialogueButtons& btnInfos) {

	int clickX_axis = 0, clickY_axis = 0;

	GetMousePoint(&clickX_axis, &clickY_axis);

	if (GetMouseInput() && MOUSE_INPUT_LEFT) {

		if (clickX_axis >= btnInfos._button_x1 && 
			clickX_axis <= btnInfos._button_x1 + btnInfos._button_width &&
			clickY_axis >= btnInfos._button_y1 && 
			clickY_axis <= btnInfos._button_y1 + btnInfos._button_height)
		{
			// ボタンの種類に応じて処理を分岐する
			switch (btnInfos._type_dialogue) {

			case TYPE::TITLE: // TITLEボタン
			{
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneTitle());

				break;
			}
			case TYPE::LOAD: // LOADボタン
			{
				break;
			}
			case TYPE::SAVE: // SAVEボタン
			{
				break;
			}
			case TYPE::AUTO: // AUTOボタン
			{
				_autoText = !_autoText;
				break;
			}
			case TYPE::SKIP: // SKIPボタン
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
			case TYPE::LOG: // LOGボタン
			{
				break;
			}
			case TYPE::CONFIG: // CONFIGボタン
			{
				break;
			}
			}
		}
	}
}



void DialogueButtons::AutoDialogue() {

	if (!_autoText) 	return;

	_autoTimer += 0.02f;

	if (_autoTimer >= 1.5f) {

		SceneConversation::_CURRENT_TEXTROW++;
		_autoTimer = 0.0f;
	}
}