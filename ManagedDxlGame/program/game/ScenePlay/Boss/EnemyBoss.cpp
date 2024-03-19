#include <random>
#include "../../../utility/tnlSequence.h"
#include "../Hand/Hand.h"
#include "EnemyBoss.h"
#include "../Slider/SliderEvent.h"
#include "../../SceneStageMap/Symbol/SymbolOfStageMap.h"
#include "../../Manager/ImageManager/use/ImageManager.h"


int EnemyBoss::_bossHP;


EnemyBoss::EnemyBoss(const int stageId) {

	LoadBackGround(stageId);
	LoadBossImage();
}


struct EnemyBoss::BossImageInfo bossImageInfo[] = {

	// 左から　x, y, exRate, angle

	{600,240,0.95f,0.0f}, // FOREST
	{600,220,0.95f,0.0f}, // VILLAGE
	{600,240,0.95f,0.0f}, // CITY
	{600,230,0.95f,0.0f}, // THEOCRACY
	{600,240,0.95f,0.0f}, // KINGDOM
	{600,240,0.25f,0.0f}, // CONTINENT
};


void EnemyBoss::InitBossHP(const int episodeID) {

	switch (episodeID)
	{
	case SymbolOfStageMap::FOREST:
		EnemyBoss::_bossHP = 1;
		break;
	case SymbolOfStageMap::VILLAGE:
		EnemyBoss::_bossHP = 2;
		break;
	case SymbolOfStageMap::CITY:
		EnemyBoss::_bossHP = 3;
		break;
	case SymbolOfStageMap::THEOCRACY:
		EnemyBoss::_bossHP = 4;
		break;
	case SymbolOfStageMap::KINGDOM:
		EnemyBoss::_bossHP = 5;
		break;
	case SymbolOfStageMap::CONTINENT:
		EnemyBoss::_bossHP = 6;
		break;
	}
}


void EnemyBoss::LoadBossImage() {

	switch (SymbolOfStageMap::_episodeID)
	{
	case SymbolOfStageMap::FOREST:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Forest/デフォルト.png");
		break;

	case SymbolOfStageMap::VILLAGE:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Village/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Village/oneHit.png");

		break;

	case SymbolOfStageMap::CITY:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_City/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_City/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_City/twoHit.png");

		break;

	case SymbolOfStageMap::THEOCRACY:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/twoHit.png");
		_bossImg_threeHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Theocracy/threeHit.png");

		break;

	case SymbolOfStageMap::KINGDOM:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/デフォルト.png");
		_bossImg_oneHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/oneHit.png");
		_bossImg_twoHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/twoHit.png");
		_bossImg_threeHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/threeHit.png");
		_bossImg_fourHit_hdl = LoadGraph("graphics/CharacterImg/Boss_Kingdom/fourHit.png");

		break;

	case SymbolOfStageMap::CONTINENT:
		_bossImg_default_hdl = LoadGraph("graphics/CharacterImg/Boss_Continent/デフォルト.png");

		break;
	}
}



void EnemyBoss::LoadBackGround(const int stageId) {

	switch (stageId)
	{
	case SymbolOfStageMap::TYPE::FOREST:  // 森のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ステージ1");
		break;
	}
	case SymbolOfStageMap::TYPE::VILLAGE: // 村のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ステージ2");
		break;
	}
	case SymbolOfStageMap::TYPE::CITY:    // 都市のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ステージ3");
		break;
	}
	case SymbolOfStageMap::TYPE::THEOCRACY: // 神政国家のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ステージ4");
		break;
	}
	case SymbolOfStageMap::TYPE::KINGDOM:   // 王国のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ステージ5");
		break;
	}
	case SymbolOfStageMap::TYPE::CONTINENT: // 大陸のシンボル
	{
		ImageManager::GetInstance().LoadBackGroundImage("ラストステージ");
		break;
	}
	}
}



void EnemyBoss::RenderBackGround(const int stageId) {

	switch (stageId)
	{
	case SymbolOfStageMap::TYPE::FOREST: // 森のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(0, 0, 1.5f, 0);
		break;
	}
	case SymbolOfStageMap::TYPE::VILLAGE: // 村のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(15, 15, 1.0f, 0);
		break;
	}
	case SymbolOfStageMap::TYPE::CITY: // 都市のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(635, 0, 1.5f, 0);
		break;
	}
	case SymbolOfStageMap::TYPE::THEOCRACY: // 神政国家のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(600, 190, 1.0f, 0);
		break;
	}
	case SymbolOfStageMap::TYPE::KINGDOM: // 王国のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(635, 400, 1.5f, 0);
		break;
	}
	case SymbolOfStageMap::TYPE::CONTINENT: // 大陸のシンボル
	{
		ImageManager::GetInstance().RenderBackGroundImage(500, 400, 1.0f, 0);
		break;
	}
	}
}



void EnemyBoss::RenderBossEnemy(const int stageId) {

	// 現在HPが減るごとに表情が変わる。


	switch (stageId)
	{
		// ステージ１
	case SymbolOfStageMap::FOREST:
		DrawRotaGraph(
			bossImageInfo[0].x, 
			bossImageInfo[0].y, 
			bossImageInfo[0].exRate,
			bossImageInfo[0].angle,
			_bossImg_default_hdl,
			true
		);
		break;

		// ステージ２
	case SymbolOfStageMap::VILLAGE:
		switch (EnemyBoss::_bossHP) {
		case 2:
			DrawRotaGraph(
				bossImageInfo[1].x,
				bossImageInfo[1].y, 
				bossImageInfo[1].exRate,
				bossImageInfo[1].angle,
				_bossImg_default_hdl,
				true
			);
			break;
		case 1:
			DrawRotaGraph(
				bossImageInfo[1].x,
				bossImageInfo[1].y,
				bossImageInfo[1].exRate, 
				bossImageInfo[1].angle,
				_bossImg_oneHit_hdl,
				true
			);
			break;
		}
		break;

		// ステージ３
	case SymbolOfStageMap::CITY:
		switch (EnemyBoss::_bossHP) {
		case 3:
			DrawRotaGraph(
				bossImageInfo[2].x,
				bossImageInfo[2].y,
				bossImageInfo[2].exRate,
				bossImageInfo[2].angle, 
				_bossImg_default_hdl, 
				true
			);
			break;
		case 2:
			DrawRotaGraph(
				bossImageInfo[2].x,
				bossImageInfo[2].y, 
				bossImageInfo[2].exRate, 
				bossImageInfo[2].angle,
				_bossImg_oneHit_hdl,
				true
			);
			break;
		case 1:
			DrawRotaGraph(
				bossImageInfo[2].x,
				bossImageInfo[2].y, 
				bossImageInfo[2].exRate, 
				bossImageInfo[2].angle,
				_bossImg_twoHit_hdl, 
				true
			);
			break;
		}
		break;

		// ステージ４
	case SymbolOfStageMap::THEOCRACY:

		switch (EnemyBoss::_bossHP) {
		case 4:
			DrawRotaGraph(
				bossImageInfo[3].x,
				bossImageInfo[3].y, 
				bossImageInfo[3].exRate,
				bossImageInfo[3].angle,
				_bossImg_default_hdl,
				true
			);
			break;
		case 3:
			DrawRotaGraph(
				bossImageInfo[3].x,
				bossImageInfo[3].y, 
				bossImageInfo[3].exRate, 
				bossImageInfo[3].angle,
				_bossImg_oneHit_hdl,
				true
			);
			break;
		case 2:
			DrawRotaGraph(
				bossImageInfo[3].x,
				bossImageInfo[3].y,
				bossImageInfo[3].exRate,
				bossImageInfo[3].angle,
				_bossImg_twoHit_hdl, 
				true
			);
			break;
		case 1:
			DrawRotaGraph(
				bossImageInfo[3].x,
				bossImageInfo[3].y,
				bossImageInfo[3].exRate,
				bossImageInfo[3].angle,
				_bossImg_threeHit_hdl,
				true
			);
			break;
		}
		break;

		// ステージ５
	case SymbolOfStageMap::KINGDOM:
		switch (EnemyBoss::_bossHP) {
		case 5:
			DrawRotaGraph(
				bossImageInfo[4].x,
				bossImageInfo[4].y,
				bossImageInfo[4].exRate,
				bossImageInfo[4].angle, 
				_bossImg_default_hdl,
				true
			);
			break;
		case 4:
			DrawRotaGraph(
				bossImageInfo[4].x,
				bossImageInfo[4].y, 
				bossImageInfo[4].exRate,
				bossImageInfo[4].angle,
				_bossImg_oneHit_hdl,
				true
			);
			break;
		case 3:
			DrawRotaGraph(
				bossImageInfo[4].x, 
				bossImageInfo[4].y,
				bossImageInfo[4].exRate,
				bossImageInfo[4].angle,
				_bossImg_twoHit_hdl, 
				true
			);
			break;
		case 2:
			DrawRotaGraph(
				bossImageInfo[4].x, 
				bossImageInfo[4].y, 
				bossImageInfo[4].exRate,
				bossImageInfo[4].angle,
				_bossImg_threeHit_hdl,
				true
			);
			break;
		case 1:
			DrawRotaGraph(
				bossImageInfo[4].x,
				bossImageInfo[4].y, 
				bossImageInfo[4].exRate,
				bossImageInfo[4].angle,
				_bossImg_fourHit_hdl,
				true
			);
			break;
		}
		break;

		// ステージ６
	case SymbolOfStageMap::CONTINENT:
		DrawRotaGraph(
			bossImageInfo[5].x,
			bossImageInfo[5].y,
			bossImageInfo[5].exRate,
			bossImageInfo[5].angle, 
			_bossImg_default_hdl, 
			true
		);
		break;
	}
}



void EnemyBoss::RenderBossHP() {

	SetFontSize(30);
	DrawFormatString(1050, 20, 0xFFFF0000, "EnemyHP:%d", EnemyBoss::_bossHP);
}



void EnemyBoss::ShuffleBossHandProbabilityTable() {

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> rateDistribution(1, 10);
	int randomValue = rateDistribution(gen);

	std::shuffle(
		Hand::_bossHandProbabilitiesByGrade[0].begin(),
		Hand::_bossHandProbabilitiesByGrade[0].end(), 
		gen
	);
	std::shuffle(
		Hand::_bossHandProbabilitiesByGrade[1].begin(),
		Hand::_bossHandProbabilitiesByGrade[1].end(),
		gen
	);
	std::shuffle(
		Hand::_bossHandProbabilitiesByGrade[2].begin(),
		Hand::_bossHandProbabilitiesByGrade[2].end(), 
		gen
	);
	std::shuffle(
		Hand::_bossHandProbabilitiesByGrade[3].begin(),
		Hand::_bossHandProbabilitiesByGrade[3].end(), 
		gen
	);
}


void EnemyBoss::SetBossHandProbability_BySliderGrade(const SliderEvent* slider) {

	// スライダーイベントの成績によって、以下の対応表から数値が格納される

	//{ 70, 20, 10 }  　// PERFECT
	//{ 50,30,20 }　　　// GREAT
	//{ 40,40,20 }　 　 // GOOD
	//{ 34,33,33 } 　　 // BAD

	SetFontSize(45);

	switch (slider->GetSliderGrade()) 
	{
	//　パーフェクト
	case SliderEvent::PERFECT:

		Hand::_guHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::PERFECT][0];

		Hand::_chokiHandProbability = 
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::PERFECT][1];

		Hand::_paHandProbability =    
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::PERFECT][2];
		break;
	//　グレート
	case SliderEvent::GREAT:

		Hand::_guHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GREAT][0];

		Hand::_chokiHandProbability = 
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GREAT][1];

		Hand::_paHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GREAT][2];
		break;
	//　グッド
	case SliderEvent::GOOD:

		Hand::_guHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GOOD][0];

		Hand::_chokiHandProbability =
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GOOD][1];

		Hand::_paHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::GOOD][2];
		break;
	//　バッド
	case SliderEvent::BAD:

		Hand::_guHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::BAD][0];

		Hand::_chokiHandProbability =
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::BAD][1];

		Hand::_paHandProbability =   
			Hand::_bossHandProbabilitiesByGrade[SliderEvent::BAD][2];
		break;
	}

	//　各文字列へ代入
	_bossHand_predictableStrings[0] = std::to_string(Hand::_guHandProbability);
	_bossHand_predictableStrings[1] = std::to_string(Hand::_chokiHandProbability);
	_bossHand_predictableStrings[2] = std::to_string(Hand::_paHandProbability);
}



void EnemyBoss::RenderBossHandProb(const SliderEvent* slider) {

	SetBossHandProbability_BySliderGrade(slider);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 60);
	DrawBox(0, 480, 1300, 685, 0, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetFontSize(50);

	RenderBossHandProbability();
}



void EnemyBoss::RenderBossHandProbability()
{
	//　最終的に決定したボスの手の確率文字列をそれぞれ表示

	//　グー
	DrawStringEx(
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[0].x - 10,
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[0].y - 65,
		0xFFFACD,
		_bossHand_predictableStrings[0].c_str()
	);

	//　チョキ
	DrawStringEx(
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[1].x - 10,
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[1].y - 65,
		0xFFFACD,
		_bossHand_predictableStrings[1].c_str()
	);

	//　パー
	DrawStringEx(
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[2].x - 10,
		Hand::GU_CHOKI_PA_IMAGE_POSITIONS[2].y - 65,
		0xFFFACD,
		_bossHand_predictableStrings[2].c_str()
	);
}


void EnemyBoss::RenderJankenResult() {

	//　ボスが選択した手を表示

	DrawRotaGraphF(
		Hand::RESULT_BOSS_HAND_POS.x + 55,
		Hand::RESULT_BOSS_HAND_POS.y - 15,
		0.5f, 
		0, 
		Hand::_gpc_handImageHandle[Hand::_bossSelectedHand],
		true
	);

	DrawStringEx(
		Hand::RESULT_BOSS_HAND_POS.x + 45,
		Hand::RESULT_BOSS_HAND_POS.y + 50, 
		-1, 
		"ENEMY"
	);
}