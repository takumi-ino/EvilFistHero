#pragma once
#include "../Manager/SceneManager/SceneBase.h"


// ƒQ[ƒ€ŠJn’n“_
class SceneTitle : public SceneBase
{
public:

	SceneTitle();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;
	void ReleaseMem() override;

private:

	int _backGroundImage_hdl{};   // ”wŒi‰æ‘œ
	int	_logoImage_hdl{};         // ƒƒS‘fŞ
};