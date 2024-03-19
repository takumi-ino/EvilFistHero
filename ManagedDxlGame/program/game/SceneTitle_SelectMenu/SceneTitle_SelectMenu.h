#pragma once

/*
         　メニュー選択クラス（　SceneTitleの次　）

	  ・ゲーム開始
	  ・ゲーム終了
	  ・戻る	  　　の３つのみ
*/


class SceneTitle_SelectMenu : public SceneBase
{
public:

	SceneTitle_SelectMenu();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;
	void ReleaseMem() override;

private:

	void ShowMenu();

	void SelectMenuByInput();

public:

	typedef struct {

		int  posX;       // 文字列座標 X
		int  posY;       // 文字列座標 Y
		char name[128];  // 文字列名
	}
	SelectMenu;

private:

	int       _backGroundImage_hdl{};
	int       _menuIndex{};
};