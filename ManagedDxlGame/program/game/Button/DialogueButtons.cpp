#include "DialogueButtons.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneStageMap/SceneStageMap.h"
#include "../Manager/ImageManager/use/ImageManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../Manager/SoundManager/SoundManager.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../ScenePlay/Battle/Scene_JankenBattle.h"
#include "../SceneStageMap/Symbol/StageSymbol.h"

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



void DialogueButtons::ManageFuncs_DialogueButton() {


	static std::shared_ptr<DialogueButtons[]> buttonArray;

	if (buttonArray == nullptr) buttonArray = Instantiate_DialogueButton();

	// �{�^���̕`��Ə���
	for (int i = 0; i < BUTTON_ALL_NUM_DIALOGUE; i++) {

		// �r������
		std::lock_guard<std::mutex> lock(mtx);

		DialogueButtons& btn = buttonArray[i];

		ZoomFunc_OnMouse_Dialogue(btn);
		ClickFunc_OnButton_Dialogue(btn);

		DrawRotaGraph(btn.x, btn.y, btn._currentSize, 0.0f, btn.handle, true);
	}

}



void DialogueButtons::Render_FuncButtons_Dialogue() {

	ManageFuncs_DialogueButton();
}



void DialogueButtons::ZoomFunc_OnMouse_Dialogue(DialogueButtons& btnInfo) {

	int hoveredX = 0, hoveredY = 0;

	GetMousePoint(&hoveredX, &hoveredY);

	if (hoveredX >= btnInfo.x && hoveredX <= btnInfo.x + btnInfo.width && hoveredY >= btnInfo.y && hoveredY <= btnInfo.y + btnInfo.height) {
		btnInfo._currentSize = btnInfo.BUTTON_SIZE_ZOOM_DIALOGUE;
	}
	else {
		btnInfo._currentSize = btnInfo.BUTTON_SIZE_NORMAL_DIALOGUE;
	}
}



void DialogueButtons::ClickFunc_OnButton_Dialogue(const DialogueButtons& btnInfos) {

	int clickX_axis = 0, clickY_axis = 0;

	GetMousePoint(&clickX_axis, &clickY_axis);

	if (GetMouseInput() && MOUSE_INPUT_LEFT) {

		if (clickX_axis >= btnInfos.x && clickX_axis <= btnInfos.x + btnInfos.width &&
			clickY_axis >= btnInfos.y && clickY_axis <= btnInfos.y + btnInfos.height) {
			// �{�^���̎�ނɉ����ď����𕪊򂷂�
			switch (btnInfos._type_dialogue) {

			case ButtonType_Dialogue::TITLE: // TITLE�{�^��
			{
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneTitle());

				break;
			}
			case ButtonType_Dialogue::LOAD: // LOAD�{�^��
			{
				break;
			}
			case ButtonType_Dialogue::SAVE: // SAVE�{�^��
			{
				break;
			}
			case ButtonType_Dialogue::AUTO: // AUTO�{�^��
			{
				_autoText = !_autoText;
				break;
			}
			case ButtonType_Dialogue::SKIP: // SKIP�{�^��
			{
				if (SceneConversation::Prologue_Epilogue == 1) {

					SceneStageMap ss;
					ss.SetStageInfo_BeforeStartGame(StageSymbol::Symbol::KINGDOM);

					return;
				}

				SceneConversation::_CURRENT_TEXTROW = 0;

				// �X�e�[�W�}�b�v��
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneStageMap());

				break;
			}
			case ButtonType_Dialogue::LOG: // LOG�{�^��
			{
				break;
			}
			case ButtonType_Dialogue::CONFIG: // CONFIG�{�^��
			{
				break;
			}

			default:
				break;
			}
		}
	}
}



void DialogueButtons::Auto_Dialogue() {

	if (!_autoText) 	return;

	_autoTimer += 0.02f;

	if (_autoTimer >= 1.5f) {

		SceneConversation::_CURRENT_TEXTROW++;
		_autoTimer = 0.0f;
	}
}