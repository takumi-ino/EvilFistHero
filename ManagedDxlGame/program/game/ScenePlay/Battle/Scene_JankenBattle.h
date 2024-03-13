#pragma once
#include "../../Manager/SceneManager/SceneBase.h"


constexpr static int SYMBOL_ALLNUM = 6;

class Hand;
class EnemyBoss;
class SliderEvent;
class SceneStageMap;
class StageSymbol;

class Scene_JankenBattle : public SceneBase
{
public:

	enum class GameState {

		START, // �Q�[���J�n
		PLAY,  // �Q�[���v���C��
		LOSE,  // �Q�[���I�[�o�[���j���[���J��
		WIN    // �}�b�v�֖߂�
	};

	// �R���X�g���N�^------------------------------------------------------------

	Scene_JankenBattle();
	Scene_JankenBattle(const int) {}

	// ------------------------------------------------------------

	void Update(float deltaTime) override;
	void ReleaseMem() override;

	// ------------------------------------------------------------

	void ResetGame();
	static void InitPlayerHP();

private:

	void LoadBattleBGM(); // 1�񂾂����s

	// �Q�[���J�n���Ɏ��s���鏈�����܂Ƃ߂��֐�
	void GameStart_FirstTransaction();

	// �Q�[�����W�b�N�S�̂��Ǘ�����֐�
	void ExecuteLogic_ByBattleState(float deltaTime);

	// ExecuteLogicByBattleState �𕡐���Bool�ϐ��Ő���B�S�ăG���^�[�L�[�ŏ���
	void ChangeGameStateByBools();

	// 1�������Ƃ̌��ʂ�Ԃ��B���s�A�����A�s�k�̂����ꂩ�ł���
	Scene_JankenBattle::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);

	// �`��----------------------------------------------------------------------------------------------------

	void RenderPlayerHP();
	void RenderJankenResult_Player();
	void RenderIntroText_BattleStart();	// �Q�[���J�n����P�񂾂��\���A���^�[������͕\�����Ȃ�

private:

	bool SeqCheckPlayBGMOrNot(float delta_time); // �o�g���J�n���A�o�g���I�����𔻒肵�ABGM�𐧌䂷��
	tnl::Sequence<Scene_JankenBattle> _sequence = tnl::Sequence<Scene_JankenBattle>(this, &Scene_JankenBattle::SeqCheckPlayBGMOrNot);

private:

	EnemyBoss*   _bossRef_ptr = nullptr;
	SliderEvent* _sliderRef_ptr = nullptr;
	Hand*        _handRef_ptr = nullptr;

private:

	GameState    _CURRENT_STATE = GameState::START;

	// �v���C���[�Ƃ����N���X���Ȃ��̂�HP�͂����ŊǗ�
	static int   _playerHP;
};