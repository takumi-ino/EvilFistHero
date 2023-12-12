#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "SceneTitle/SceneTitle.h"
#include "Manager/SceneManager/SceneManager.h"

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	SetFontSize(30);

	tnl::AddFontTTF("font/genkai-mincho.ttf");

	SceneManager::GetInstance(new SceneTitle());
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	ChangeFont("源界明朝", DX_CHARSET_DEFAULT);

	SceneManager::GetInstance()->Update(delta_time);
	SceneManager::GetInstance()->Render(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}

