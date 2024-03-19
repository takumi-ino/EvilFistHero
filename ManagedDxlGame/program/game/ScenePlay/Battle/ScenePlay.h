#pragma once
#include "../../Manager/SceneManager/SceneBase.h"


constexpr static int SYMBOL_ALLNUM = 6;

class Hand;
class EnemyBoss;
class SliderEvent;
class SceneStageMap;
class SymbolOfStageMap;


// �C���Q�[���B�i�@SceneStageMap�̎��@�j
class ScenePlay : public SceneBase
{
public:

	enum class GameState {

		START, // �Q�[���J�n
		PLAY,  // �Q�[���v���C��
		LOSE,  // �Q�[���I�[�o�[���j���[���J��
		WIN    // �}�b�v�֖߂�
	};

	// �R���X�g���N�^------------------------------------------------------------

	ScenePlay();
	ScenePlay(const int) {}

	// ------------------------------------------------------------

	void Update(const float deltaTime) override;
	void ReleaseMem() override;

	// ------------------------------------------------------------

	void ResetGame();
	static void InitPlayerHP();

private:

	void LoadBattleBGM(); // BGM�������@1�񂾂����s

	// �Q�[���J�n���Ɏ��s���鏉����
	void ResetAllWhenGameStart();


	// enum class GameState ���g�p��������-----------------------------------------------------------

	// GameState�́@START�`WIN�@�܂ł̑S�Ă̗�����Ǘ�
	void ExecuteBattleStateLogic(const float deltaTime);

	// GameState::Play ���̊e�����𐧌䂷��Bool�ϐ����ꊇ�Ǘ�
	void ManageGamePlayStateBools(); // ���@GameState::Play �͏��������Ȃ蕡�G�Ȃ���Bool�ϐ��𕡐��g�p

	// ManageGamePlayStateBools �֐����̔��茋�ʂ����s����
	void UpdateGamePlayState(const float deltaTime);

	// 1�������Ƃ̌��ʂ�Ԃ��B���s�A�����A�s�k�̂����ꂩ�ł���
	ScenePlay::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);


	// �`��----------------------------------------------------------------------------------------------------

	void RenderPlayerHP();              // HP�\��
	void RenderPlayersJankenResult();   // �v���C���[�̃W�����P�����U���g�\��
	void RenderBattleStartIntroText();	// �Q�[���J�n����P�񂾂��\���A���^�[������͕\�����Ȃ�

private:

	// �u�t�z�z�̃��C�u�����@�\�B�������̃��[�h�Ȃ�1�x�������s������������ Sequence �N���X���g�p
	tnl::Sequence<ScenePlay> _sequence = 
		tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqCheckPlayBGM);

	bool SeqCheckPlayBGM(float deltaTime); // �o�g���J�n���A�o�g���I�����𔻒肵�ABGM�𐧌�

private:

	EnemyBoss*   _boss = nullptr;       // �G
	SliderEvent* _sliderRef = nullptr;  // �C�x���g�A�C�e��
	Hand*        _handRef = nullptr;    // ��

private:

	GameState    _CURRENT_STATE = GameState::START;

	// �v���C���[�Ƃ����N���X���Ȃ��̂�HP�͂����ŊǗ�
	static int   _playerHP;
};