#include "EnemyBoss.h"
#include "../Hand/Hand.h"
#include "../../SceneStageMap/Symbol/StageSymbol.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include <random>


int EnemyBoss::_bossHP;


EnemyBoss::EnemyBoss(const int& stageId) {

	LoadBackGround(stageId);
	LoadBossImage(stageId);
}


struct EnemyBoss::BossImgInfo biInfo[] = {

	// x, y, exRate, angle

	{600,240,0.95f,0.0f}, // FOREST
	{600,220,0.95f,0.0f}, // VILLAGE
	{600,240,0.95f,0.0f}, // CITY
	{600,230,0.95f,0.0f}, // THEOCRACY
	{600,240,0.95f,0.0f}, // KINGDOM
	{600,240,0.25f,0.0f}, // CONTINENT
};


void EnemyBoss::InitBossHP(const int& episodeID) {

	switch (episodeID)
	{
	case StageSymbol::FOREST:
		EnemyBoss::_bossHP = 1;
		break;
	case StageSymbol::VILLAGE:
		EnemyBoss::_bossHP = 2;
		break;
	case StageSymbol::CITY:
		EnemyBoss::_bossHP = 3;
		break;
	case StageSymbol::THEOCRACY:
		EnemyBoss::_bossHP = 4;
		break;
	case StageSymbol::KINGDOM:
		EnemyBoss::_bossHP = 5;
		break;
	case StageSymbol::CONTINENT:
		EnemyBoss::_bossHP = 6;
		break;
	}
}



void EnemyBoss::LoadBossImage(const int& stage_id) {

	switch (StageSymbol::_episodeID)
	{
	case StageSymbol::FOREST:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Forest/デフォルト.png");
		break;
	case StageSymbol::VILLAGE:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Village/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Village/oneHit.png");

		break;
	case StageSymbol::CITY:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_City/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_City/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_City/twoHit.png");

		break;
	case StageSymbol::THEOCRACY:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/twoHit.png");
		_bossImg_threeHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/threeHit.png");

		break;
	case StageSymbol::KINGDOM:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/twoHit.png");
		_bossImg_threeHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/threeHit.png");
		_bossImg_fourHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/fourHit.png");

		break;
	case StageSymbol::CONTINENT:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Continent/デフォルト.png");

		break;
	}
}



void EnemyBoss::LoadBackGround(const int& stage_id) {

	switch (stage_id)
	{
	case StageSymbol::Symbol::FOREST: // 森のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ステージ1");
		break;
	}
	case StageSymbol::Symbol::VILLAGE: // 村のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ステージ2");
		break;
	}
	case StageSymbol::Symbol::CITY: // 都市のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ステージ3");
		break;
	}
	case StageSymbol::Symbol::THEOCRACY: // 神政国家のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ステージ4");
		break;
	}
	case StageSymbol::Symbol::KINGDOM: // 王国のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ステージ5");
		break;
	}
	case StageSymbol::Symbol::CONTINENT: // 大陸のシンボル
	{
		ImageManager::GetInstance().Load_BackGroundImage("ラストステージ");
		break;
	}
	}
}



void EnemyBoss::RenderBackGround(const int& stage_id) {

	switch (stage_id)
	{
	case StageSymbol::Symbol::FOREST: // 森のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(0, 0, 1.5f, 0);
		break;
	}
	case StageSymbol::Symbol::VILLAGE: // 村のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(15, 15, 1.0f, 0);
		break;
	}
	case StageSymbol::Symbol::CITY: // 都市のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(635, 0, 1.5f, 0);
		break;
	}
	case StageSymbol::Symbol::THEOCRACY: // 神政国家のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(600, 190, 1.0f, 0);
		break;
	}
	case StageSymbol::Symbol::KINGDOM: // 王国のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(635, 400, 1.5f, 0);
		break;
	}
	case StageSymbol::Symbol::CONTINENT: // 大陸のシンボル
	{
		ImageManager::GetInstance().Render_BackGroundImage(500, 400, 1.0f, 0);
		break;
	}
	}
}



void EnemyBoss::RenderBossEnemy(const int& stage_id) {

	switch (stage_id)
	{
	case StageSymbol::FOREST:
		DrawRotaGraph(biInfo[0].x, biInfo[0].y, biInfo[0].exRate, biInfo[0].angle, _bossImg_default_hdl, true);
		break;

	case StageSymbol::VILLAGE:
		switch (EnemyBoss::_bossHP) {
		case 2:
			DrawRotaGraph(biInfo[1].x, biInfo[1].y, biInfo[1].exRate, biInfo[1].angle, _bossImg_default_hdl, true);
			break;
		case 1:
			DrawRotaGraph(biInfo[1].x, biInfo[1].y, biInfo[1].exRate, biInfo[1].angle, _bossImg_oneHit_hdl, true);
			break;
		}
		break;

	case StageSymbol::CITY:
		switch (EnemyBoss::_bossHP) {
		case 3:
			DrawRotaGraph(biInfo[2].x, biInfo[2].y, biInfo[2].exRate, biInfo[2].angle, _bossImg_default_hdl, true);
			break;
		case 2:
			DrawRotaGraph(biInfo[2].x, biInfo[2].y, biInfo[2].exRate, biInfo[2].angle, _bossImg_oneHit_hdl, true);
			break;
		case 1:
			DrawRotaGraph(biInfo[2].x, biInfo[2].y, biInfo[2].exRate, biInfo[2].angle, _bossImg_twoHit_hdl, true);
			break;
		}
		break;

	case StageSymbol::THEOCRACY:

		switch (EnemyBoss::_bossHP) {
		case 4:
			DrawRotaGraph(biInfo[3].x, biInfo[3].y, biInfo[3].exRate, biInfo[3].angle, _bossImg_default_hdl, true);
			break;
		case 3:
			DrawRotaGraph(biInfo[3].x, biInfo[3].y, biInfo[3].exRate, biInfo[3].angle, _bossImg_oneHit_hdl, true);
			break;
		case 2:
			DrawRotaGraph(biInfo[3].x, biInfo[3].y, biInfo[3].exRate, biInfo[3].angle, _bossImg_twoHit_hdl, true);
			break;
		case 1:
			DrawRotaGraph(biInfo[3].x, biInfo[3].y, biInfo[3].exRate, biInfo[3].angle, _bossImg_threeHit_hdl, true);
			break;
		}
		break;

	case StageSymbol::KINGDOM:
		switch (EnemyBoss::_bossHP) {
		case 5:
			DrawRotaGraph(biInfo[4].x, biInfo[4].y, biInfo[4].exRate, biInfo[4].angle, _bossImg_default_hdl, true);
			break;
		case 4:
			DrawRotaGraph(biInfo[4].x, biInfo[4].y, biInfo[4].exRate, biInfo[4].angle, _bossImg_oneHit_hdl, true);
			break;
		case 3:
			DrawRotaGraph(biInfo[4].x, biInfo[4].y, biInfo[4].exRate, biInfo[4].angle, _bossImg_twoHit_hdl, true);
			break;
		case 2:
			DrawRotaGraph(biInfo[4].x, biInfo[4].y, biInfo[4].exRate, biInfo[4].angle, _bossImg_threeHit_hdl, true);
			break;
		case 1:
			DrawRotaGraph(biInfo[4].x, biInfo[4].y, biInfo[4].exRate, biInfo[4].angle, _bossImg_fourHit_hdl, true);
			break;
		}
		break;

	case StageSymbol::CONTINENT:
		DrawRotaGraph(biInfo[5].x, biInfo[5].y, biInfo[5].exRate, biInfo[5].angle, _bossImg_default_hdl, true);
		break;
	}
}


void EnemyBoss::RenderBossHP() {

	SetFontSize(30);
	DrawFormatString(1050, 20, 0xFFFF0000, "EnemyHP:%d", EnemyBoss::_bossHP);
}


void EnemyBoss::Shuffle_BossHandProbTable() {

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> rateDistribution(1, 10);
	int randomValue = rateDistribution(gen);


	std::shuffle(Hand::HAND_PROB_ARY_EACH_GRADE[0].begin(), Hand::HAND_PROB_ARY_EACH_GRADE[0].end(), gen);
	std::shuffle(Hand::HAND_PROB_ARY_EACH_GRADE[1].begin(), Hand::HAND_PROB_ARY_EACH_GRADE[1].end(), gen);
	std::shuffle(Hand::HAND_PROB_ARY_EACH_GRADE[2].begin(), Hand::HAND_PROB_ARY_EACH_GRADE[2].end(), gen);
	std::shuffle(Hand::HAND_PROB_ARY_EACH_GRADE[3].begin(), Hand::HAND_PROB_ARY_EACH_GRADE[3].end(), gen);
}


void EnemyBoss::SetBossHandProb_BySliderGrade(const SliderEvent* slider) {


	SetFontSize(45);
	switch (slider->slider_grade) {

	case SliderEvent::SLIDER_GRADE_PERFECT:

		Hand::_gu_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_PERFECT][0];
		Hand::_choki_prob = Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_PERFECT][1];
		Hand::_pa_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_PERFECT][2];

		break;
	case SliderEvent::SLIDER_GRADE_GREAT:

		Hand::_gu_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GREAT][0];
		Hand::_choki_prob = Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GREAT][1];
		Hand::_pa_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GREAT][2];

		break;
	case SliderEvent::SLIDER_GRADE_GOOD:

		Hand::_gu_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GOOD][0];
		Hand::_choki_prob = Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GOOD][1];
		Hand::_pa_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_GOOD][2];

		break;
	case SliderEvent::SLIDER_GRADE_BAD:

		Hand::_gu_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_BAD][0];
		Hand::_choki_prob = Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_BAD][1];
		Hand::_pa_prob =    Hand::HAND_PROB_ARY_EACH_GRADE[SliderEvent::SLIDER_GRADE_BAD][2];

		break;
	}

	_boss_gcpHand_str[0] = std::to_string(Hand::_gu_prob);
	_boss_gcpHand_str[1] = std::to_string(Hand::_choki_prob);
	_boss_gcpHand_str[2] = std::to_string(Hand::_pa_prob);
}



void EnemyBoss::RenderBossHandProb(const SliderEvent* slider) {

	// 敵の出す手
	SetBossHandProb_BySliderGrade(slider);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 60);
	DrawBox(0, 480, 1300, 685, 0, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 手札の確率String
	SetFontSize(50);
	DrawFormatString(Hand::GUCHOKIPA_HANDPOS_TBL[0].x - 10, Hand::GUCHOKIPA_HANDPOS_TBL[0].y - 65, 0xFFFACD, _boss_gcpHand_str[0].c_str());
	DrawFormatString(Hand::GUCHOKIPA_HANDPOS_TBL[1].x - 10, Hand::GUCHOKIPA_HANDPOS_TBL[1].y - 65, 0xFFFACD, _boss_gcpHand_str[1].c_str());
	DrawFormatString(Hand::GUCHOKIPA_HANDPOS_TBL[2].x - 10, Hand::GUCHOKIPA_HANDPOS_TBL[2].y - 65, 0xFFFACD, _boss_gcpHand_str[2].c_str());
}



void EnemyBoss::RenderJankenResult() {

	DrawRotaGraphF(Hand::RESULT_BOSS_HAND_POS.x + 55, Hand::RESULT_BOSS_HAND_POS.y - 15, 0.5f, 0, Hand::_gpc_hand_hdl[Hand::_bossSelectedHand], true);
	DrawStringEx(Hand::RESULT_BOSS_HAND_POS.x + 45, Hand::RESULT_BOSS_HAND_POS.y + 50, -1, "ENEMY");
}