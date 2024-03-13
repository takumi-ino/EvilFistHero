#pragma once
#include "../Manager/SceneManager/SceneBase.h"


class SceneTitle : public SceneBase
{
public:

	SceneTitle();

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

private:

	int _bgImage_hdl{};   // ”wŒi‰æ‘œ
	int	_logoImage_hdl{}; // ƒƒS‘fŞ
};