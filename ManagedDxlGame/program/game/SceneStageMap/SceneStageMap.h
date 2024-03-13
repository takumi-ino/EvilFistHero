#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/StageSymbol.h"

class EnemyBoss;

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

	// �Q�[���J�n�O�̍ŏI�m�F
	void ShowFinalCheck_BeforeStartGame();

	// �G���^�[�L�[�ŃQ�[���X�^�[�g
	void GameStartByInput();
	
	// �u�t�z�z�̃��C�u�����B�������̃��[�h�Ȃ�1�x�������s������������ Sequence �N���X���g�p
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	StageSymbol* _symbolRef_ptr = nullptr;
	EnemyBoss*   _bossRef_ptr = nullptr;

private:

	// �w�i�摜�n���h��
	int          _bgImage_hdl{};
};