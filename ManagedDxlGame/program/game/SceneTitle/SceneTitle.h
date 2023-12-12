#pragma once
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"
#include "../Manager/SceneManager/SceneBase.h"

class SceneTitle :public SceneBase
{
public:

	SceneTitle(){}

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

private:

	tnl::Sequence<SceneTitle> _sequence = tnl::Sequence<SceneTitle>(this, &SceneTitle::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	int _bgImage_hdl; // îwåiâÊëú
	int	_logoImage_hdl; // ÉçÉSëfçﬁ

	const int _LOGO_X = 630;
	const int _LOGO_Y = 170;
	const int _BG_X = 30;
	const int _BG_Y = 30;
};