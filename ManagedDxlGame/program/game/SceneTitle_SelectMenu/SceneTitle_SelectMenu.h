#pragma once
#include "../Manager/SoundManager/SoundManager.h"
#include "../Manager/SceneManager/SceneManager.h"


class SceneTitle_SelectMenu : public SceneBase
{
public:

	SceneTitle_SelectMenu(){
	
	}

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

		int menu_x, menu_y;  // •¶š—ñÀ•W
		char menu_name[128]; // •¶š—ñ–¼
	}SelectMenu;

private:

	int _bgImage_hdl;
	int _menu_index;

	const int _MENU_ALLITEM_NUM = 3;

	const int _BG_X = 30;
	const int _BG_Y = 30;
};