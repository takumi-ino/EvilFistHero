#pragma once
#include "../Manager/SceneManager/SceneBase.h"


// �Q�[���J�n�n�_
class SceneTitle : public SceneBase
{
public:

	SceneTitle();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;
	void ReleaseMem() override;

private:

	int _backGroundImage_hdl{};   // �w�i�摜
	int	_logoImage_hdl{};         // ���S�f��
};