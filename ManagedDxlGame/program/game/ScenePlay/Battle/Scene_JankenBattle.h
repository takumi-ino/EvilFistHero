#pragma once
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "../../SceneStageMap/Symbol/StageSymbol.h"
#include "../Hand/Hand.h"
#include "../Boss/EnemyBoss.h"
#include "../Slider/SliderEvent.h"
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"

constexpr static int SYMBOL_ALLNUM = 6;

class Hand;

class Scene_JankenBattle : public SceneBase
{
public:

	enum class GameState {

		START, // �Q�[���J�n
		PLAY,  // �Q�[���v���C��
		LOSE,  // �Q�[���I�[�o�[���j���[���J��
		WIN    // �}�b�v�֖߂�
	};

	Scene_JankenBattle();
	Scene_JankenBattle(const int) {}

	void Update(float deltaTime) override;
	void ReleaseMem() override;
	void ResetGame();

	static void InitPlayerHP();

private:

	// �Q�[���J�n����P�񂾂��\���A���^�[������͕\�����Ȃ�
	void RenderIntroText_BattleStart();

	// �Q�[���J�n���ɂ��鏈�����܂Ƃ߂��֐�
	void GameState_StartLogic();

	// �Q�[�����W�b�N�S�̂��Ǘ�����֐�
	void ExecuteLogic_ByBattleState(float deltaTime);

	// ExecuteLogicByBattleState �֐��𕡐���Bool�ϐ��Ő���B�S�ăG���^�[�L�[�ŏ���
	void ChangeGameStateByBools();

	void RenderPlayerHP();

	void RenderJankenResult_Player();

	// 1�������Ƃ̌��ʂ�Ԃ��B���s�A�����A�s�k�̂����ꂩ�ł���
	Scene_JankenBattle::GameState CheckIsOverJankenBattle(const int playerHP, const int bossHP);

private:

	GameState    CURRENT_STATE = GameState::START;

	EnemyBoss*   _bossRef_ptr = nullptr;
	SliderEvent* _sliderRef_ptr = nullptr;
	Hand*        _handRef_ptr = nullptr;

	tnl::Sequence<Scene_JankenBattle> _sequence = tnl::Sequence<Scene_JankenBattle>(this, &Scene_JankenBattle::SeqLoadMem);
	bool SeqLoadMem(float delta_time);

public:

	static int   _playerHP;

private:

	// �Q�[�����Z�b�g���Ɏg�p���� const �ϐ��Q
	const bool IS_BATTLE_START = true;
	const bool IS_SLIDER_CHALLENGE = false;
	const bool IS_MOVING_SLIDER = false;
	const bool IS_SELECT_MYHAND = false;
	const bool CAN_SUBTRACT_HP = false;
	const bool IS_SHOW_RESULT = false;

	bool isBattleStart = IS_BATTLE_START;
	bool isSliderChallenge = IS_SLIDER_CHALLENGE;
	bool isMovingSlider = IS_MOVING_SLIDER;
	bool isSelectMyHand = IS_SELECT_MYHAND;
	bool canSubtractHP = CAN_SUBTRACT_HP;
	bool isShowResult = IS_SHOW_RESULT;


	const char* _stageBGM_path[SYMBOL_ALLNUM] =
	{
	"sound/BGM/EP1_BattleBGM.mp3",
	"sound/BGM/EP2_BattleBGM.mp3",
	"sound/BGM/EP3_BattleBGM.mp3",
	"sound/BGM/EP4_BattleBGM.mp3",
	"sound/BGM/EP5_BattleBGM.mp3",
	"sound/BGM/EP6_BattleBGM.mp3",
	};
};