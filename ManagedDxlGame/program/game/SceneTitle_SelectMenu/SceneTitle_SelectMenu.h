#pragma once
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/SceneManager/SceneManager.h"


class SceneTitle_SelectMenu : public SceneBase
{
public:

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

private:

	void ShowMenu();

	void SelectMenuByInput();

	tnl::Sequence<SceneTitle_SelectMenu> _sequence = tnl::Sequence<SceneTitle_SelectMenu>(this, &SceneTitle_SelectMenu::SeqIdle);
	bool SeqIdle(float deltaTime);

public:

	typedef struct {

		int menu_x;          // 文字列座標 X
		int menu_y;          // 文字列座標 Y
		char menu_name[128]; // 文字列名
	}SelectMenu;

private:

	int       _bgImage_hdl{};
	int       _menu_index{};
};