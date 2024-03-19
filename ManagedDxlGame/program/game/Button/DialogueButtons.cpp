#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "DialogueButtons.h"
#include "../SceneStageMap/SceneStageMap.h"
#include "../Manager/ImageManager/use/ImageManager.h"
#include "../Manager/SceneManager/SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../ScenePrologueEpilogue/Dialogue/SceneConversation.h"
#include "../SceneStageMap/Symbol/SymbolOfStageMap.h"


namespace {

	// �{�^���̐�
	const int BUTTON_ALL_NUM_DIALOGUE = 7;

	// �{�^���̏����ʒu
	const int BUTTON_POS_X_DIALOGUE = 125;
	const int BUTTON_POS_Y_DIALOGUE = 700;

	// �{�^���̊Ԋu
	const int BUTTON_INTERVAL_DIALOGUE = 170;

	const char* BUTTON_IMAGE_PATH[7] =
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



DialogueButtons::DialogueButtons() {


}


std::shared_ptr<DialogueButtons[]> DialogueButtons::Instantiate_DialogueButton() {

	std::shared_ptr<DialogueButtons[]> buttonArray(new DialogueButtons[BUTTON_ALL_NUM_DIALOGUE]);

	for (int i = 0; i < BUTTON_ALL_NUM_DIALOGUE; i++) {

		int buttonHandle = LoadGraph(BUTTON_IMAGE_PATH[i]);      // �z�񂩂畡���̉摜�����[�h

		int x = BUTTON_POS_X_DIALOGUE + (i * BUTTON_INTERVAL_DIALOGUE);  // 7�̃{�^���𓙊Ԋu�Ŕz�u
		int y = BUTTON_POS_Y_DIALOGUE;

		_buttonWidth = 30;   // ��
		_buttonHeight = 15;  // ����

		TYPE type = static_cast<TYPE>(i);

		buttonArray[i] = DialogueButtons(   
			buttonHandle,
			x, y, 
			_buttonWidth,
			_buttonHeight,
			_BUTTON_SIZE_NORMAL_DIALOGUE,
			_BUTTON_SIZE_ZOOM_DIALOGUE,
			type
		);
	}

	return buttonArray;
}



void DialogueButtons::RenderDialogueButton() {

	static std::shared_ptr<DialogueButtons[]> buttonArray = nullptr;

	if (buttonArray == nullptr) {

		buttonArray = Instantiate_DialogueButton(); // 1�x�������������A�{�^���𐶐�	
	}

	// �{�^���̕`��Ə���
	for (int i = 0; i < BUTTON_ALL_NUM_DIALOGUE; i++) {

		// �r������
		std::lock_guard<std::mutex> lock(_mtx);

		DialogueButtons& ary = buttonArray[i];

		ZoomOnMouseCursor(ary);      // �Y�[���@�\
		ClickByMouseCursor(ary);     // �N���b�N�@�\

		DrawRotaGraph(               // �`��
			ary._buttonX1,
			ary._buttonY1,
			ary._currentSize, 
			0.0f,
			ary._buttonHandle,
			true
		);
	}
}



void DialogueButtons::ZoomOnMouseCursor(DialogueButtons& btnInfo) {

	int hoveredPoint_x = 0, hoveredPoint_y = 0;

	GetMousePoint(&hoveredPoint_x, &hoveredPoint_y);

	if (hoveredPoint_x >= btnInfo._buttonX1 &&
		hoveredPoint_x <= btnInfo._buttonX1 + btnInfo._buttonWidth && 
		hoveredPoint_y >= btnInfo._buttonY1 &&
		hoveredPoint_y <= btnInfo._buttonY1 + btnInfo._buttonHeight)
	{
		btnInfo._currentSize = btnInfo._BUTTON_SIZE_ZOOM_DIALOGUE;
	}
	else {
		btnInfo._currentSize = btnInfo._BUTTON_SIZE_NORMAL_DIALOGUE;
	}
}



void DialogueButtons::ClickByMouseCursor(const DialogueButtons& btnInfos) {

	int clickPoint_x = 0, clickPoint_y = 0;

	GetMousePoint(&clickPoint_x, &clickPoint_y);

	if (GetMouseInput() && MOUSE_INPUT_LEFT) {

		if (clickPoint_x >= btnInfos._buttonX1 && 
			clickPoint_x <= btnInfos._buttonX1 + btnInfos._buttonWidth &&
			clickPoint_y >= btnInfos._buttonY1 && 
			clickPoint_y <= btnInfos._buttonY1 + btnInfos._buttonHeight)
		{
			// �{�^���̎�ނɉ����ď����𕪊򂷂�
			switch (btnInfos._type) {

			case TYPE::TITLE: // TITLE�{�^��
			{
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneTitle());

				break;
			}
			case TYPE::LOAD: // LOAD�{�^��
			{
				break;
			}
			case TYPE::SAVE: // SAVE�{�^��
			{
				break;
			}
			case TYPE::AUTO: // AUTO�{�^��
			{
				_autoText = !_autoText;
				break;
			}
			case TYPE::SKIP: // SKIP�{�^��
			{
				if (SceneConversation::Prologue_Epilogue == 1) {

					SceneStageMap ss;
					ss.ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::KINGDOM);

					return;
				}

				SceneConversation::_CURRENT_TEXTROW = 0;

				// �X�e�[�W�}�b�v��
				auto scene = SceneManager::GetInstance();
				scene->ChangeScene(new SceneStageMap());

				break;
			}
			case TYPE::LOG:    // LOG�{�^��
			{
				break;
			}
			case TYPE::CONFIG: // CONFIG�{�^��
			{
				break;
			}
			}
		}
	}
}



void DialogueButtons::AutoDialogue() {

	if (!_autoText)	return;

	_autoTimer += 0.02f;

	if (_autoTimer >= 1.5f) {

		SceneConversation::_CURRENT_TEXTROW++;
		_autoTimer = 0.0f;
	}
}