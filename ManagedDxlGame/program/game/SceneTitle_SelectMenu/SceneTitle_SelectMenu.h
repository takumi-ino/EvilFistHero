#pragma once

/*
         �@���j���[�I���N���X�i�@SceneTitle�̎��@�j

	  �E�Q�[���J�n
	  �E�Q�[���I��
	  �E�߂�	  �@�@�̂R�̂�
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

		int  posX;       // ��������W X
		int  posY;       // ��������W Y
		char name[128];  // ������
	}
	SelectMenu;

private:

	int       _backGroundImage_hdl{};
	int       _menuIndex{};
};