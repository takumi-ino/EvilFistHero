#pragma once
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "../Manager/SceneManager/SceneBase.h"


class SceneTitle :public SceneBase
{
public:

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

private:

	tnl::Sequence<SceneTitle> _sequence = tnl::Sequence<SceneTitle>(this, &SceneTitle::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	int _bgImage_hdl{};   // ”wŒi‰æ‘œ
	int	_logoImage_hdl{}; // ƒƒS‘fŞ
};