#pragma once


class SceneTitle_SelectMenu : public SceneBase
{
public:

	SceneTitle_SelectMenu();

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

private:

	void ShowMenu();

	void SelectMenuByInput();

public:

	typedef struct {

		int  menu_x;          // •¶š—ñÀ•W X
		int  menu_y;          // •¶š—ñÀ•W Y
		char menu_name[128];  // •¶š—ñ–¼
	}SelectMenu;

private:

	int       _bgImage_hdl{};
	int       _menu_index{};
};