#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/SymbolOfStageMap.h"

class EnemyBoss;


//�@���[���h�}�b�v����X�e�[�W��I�ԁi�@SceneConversation �̎��@�j
class SceneStageMap : public SceneBase
{
public:

	SceneStageMap();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;
	void ReleaseMem() override;

	// �v���C���[����у{�X��HP��������
	void ResetHP_BeforeStartGame(const SymbolOfStageMap::TYPE symbol);

private:

	// �Q�[���J�n�O�̍ŏI�m�F
	void ShowFinalCheck_BeforeStartGame();

	// �G���^�[�L�[�ŃQ�[���X�^�[�g
	void GameStartByInput();

	void MoveToScenePlay();
	
	// �u�t�z�z�̃��C�u�����@�\�B�������̃��[�h�Ȃ�1�x�������s������������ Sequence �N���X���g�p
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	SymbolOfStageMap* _symbolOfStageMap = nullptr;  // �X�e�[�W�}�b�v��ɕ\������V���{��

private:

	// �w�i�摜�n���h��
	int              _backGroundImage_hdl{};
};