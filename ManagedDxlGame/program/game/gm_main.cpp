#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "SceneTitle/SceneTitle.h"
#include "Manager/SceneManager/SceneManager.h"


/*
�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�Q�[���̗���

  �@�@�@SceneTitle�@���@SceneTitle_SelectMenu�@���@SceneConversation�@���@SceneStageMap�@���@ScenePlay

*/


//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart(){
	srand(time(0));
	SetFontSize(30);

	tnl::AddFontTTF("font/genkai-mincho.ttf");

	SceneManager::GetInstance(new SceneTitle());
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float deltaTime) {

	ChangeFont("���E����", DX_CHARSET_DEFAULT);

	SceneManager::GetInstance()->Update(deltaTime);
	SceneManager::GetInstance()->Render(deltaTime);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
}