#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/StageSymbol.h"
#include "../ScenePlay/Boss/EnemyBoss.h"
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"


class SceneStageMap : public SceneBase
{
public:

	SceneStageMap();

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

	// �I�������X�e�[�W�֔�Ԃ��߂ɕK�v�ȏ����Z�b�g
	void SetStageInfo_BeforeStartGame(const StageSymbol::Symbol symbol);

private:

	// �͂��߂�A���ǂ�̂Q���ōŏI�m�F
	void ShowFinalCheck_BeforeStartGame();

	// �G���^�[�L�[�ŃQ�[���X�^�[�g
	void GameStartByInput();

	
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	StageSymbol* _symbolRef_ptr = nullptr;
	EnemyBoss* _bossRef_ptr = nullptr;

private:

	// �w�i�摜
	int _bgImage_hdl;

	// �G�s�\�[�h�^�C�g���̍��W
	const int _EPISODE_TITLE_POS_X = 395;
	const int _EPISODE_TITLE_POS_Y = 175;

	// �w�i�摜�̍��W
	const int _BG_IMAGE_POS_X = 640;
	const int _BG_IMAGE_POS_Y = 360;
	const double _BG_EXRATE = 0.47;
};