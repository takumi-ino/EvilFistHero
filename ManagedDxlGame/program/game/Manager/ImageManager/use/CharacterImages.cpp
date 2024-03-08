#include "CharacterImages.h"



void CharacterImages::SetImgMapKey_Player() {

	imageMap_player.insert({ "立ち絵2＿プレイヤー","graphics/CharacterImg/Protagonist/StandingPose2.png" });
	imageMap_player.insert({ "ドン引き＿プレイヤー", "graphics/CharacterImg/Protagonist/表情差分/ドン引き.png" });
	imageMap_player.insert({ "ノーマル＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/ノーマル.png" });
	imageMap_player.insert({ "ノーマル2","graphics/CharacterImg/Protagonist/表情差分/ノーマル2.png" });
	imageMap_player.insert({ "驚き＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/驚き.png" });
	imageMap_player.insert({ "笑顔1＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/笑顔1.png" });
	imageMap_player.insert({ "笑顔2＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/笑顔2.png" });
	imageMap_player.insert({ "笑顔3＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/笑顔3.png" });
	imageMap_player.insert({ "怒り1＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/怒り1.png" });
	imageMap_player.insert({ "怒り2＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/怒り2.png" });
	imageMap_player.insert({ "呆れ＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/呆れ.png" });
	imageMap_player.insert({ "呆れ2＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/呆れ2.png" });
	imageMap_player.insert({ "呆れ3＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/呆れ3.png" });
	imageMap_player.insert({ "疑問＿プレイヤー","graphics/CharacterImg/Protagonist/表情差分/疑問.png" });
}

void CharacterImages::SetImgMapKey_Goddess() {

	imageMap_goddess.insert({ "ノーマル＿女神", "graphics/CharacterImg/Goddess/normal.png" });
	imageMap_goddess.insert({ "笑顔＿女神","graphics/CharacterImg/Goddess/smile.png" });
	imageMap_goddess.insert({ "真剣＿女神","graphics/CharacterImg/Goddess/serious.png" });
	imageMap_goddess.insert({ "シルエット＿女神","graphics/CharacterImg/Goddess/secret.png" });
}

void CharacterImages::SetImgMapKey_Girl() {

	imageMap_girl.insert({ "ノーマル＿少女","graphics/CharacterImg/Girl/girl_normal.png" });
	imageMap_girl.insert({ "真剣＿少女","graphics/CharacterImg/Girl/girl_serious.png" });
	imageMap_girl.insert({ "笑顔＿少女","graphics/CharacterImg/Girl/girl_smile.png" });
	imageMap_girl.insert({ "怒り1＿少女","graphics/CharacterImg/Girl/girl_mad1.png" });
	imageMap_girl.insert({ "怒り2＿少女","graphics/CharacterImg/Girl/girl_mad2.png" });
	imageMap_girl.insert({ "シルエット＿少女","graphics/CharacterImg/Girl/girl_secret.png" });
}

void CharacterImages::SetImgMapKey_Bosses() {

	// Episode1
	imageMap_bosses.insert({ "ステージ1＿ボス＿デフォルト","graphics/CharacterImg/Boss_Forest/デフォルト.png" });

	// Episode2
	imageMap_bosses.insert({ "ステージ2＿ボス＿デフォルト","graphics/CharacterImg/Boss_Village/デフォルト.png" });
	imageMap_bosses.insert({ "ステージ2＿ボス＿ダメージ_1","graphics/CharacterImg/Boss_Village/oneHit.png" });

	// Episode3
	imageMap_bosses.insert({ "ステージ3＿ボス＿デフォルト","graphics/CharacterImg/Boss_City/デフォルト.png" });
	imageMap_bosses.insert({ "ステージ3＿ボス＿ダメージ_1","graphics/CharacterImg/Boss_City/oneHit.png" });
	imageMap_bosses.insert({ "ステージ3＿ボス＿ダメージ_2","graphics/CharacterImg/Boss_City/twoHit.png" });

	// Episode4
	imageMap_bosses.insert({ "ステージ4＿ボス＿デフォルト","graphics/CharacterImg/Boss_Theocracy/デフォルト.png" });
	imageMap_bosses.insert({ "ステージ4＿ボス＿ダメージ_1","graphics/CharacterImg/Boss_Theocracy/oneHit.png" });
	imageMap_bosses.insert({ "ステージ4＿ボス＿ダメージ_2","graphics/CharacterImg/Boss_Theocracy/twoHit.png" });
	imageMap_bosses.insert({ "ステージ4＿ボス＿ダメージ_3","graphics/CharacterImg/Boss_Theocracy/threeHit.png" });

	// Episode5
	imageMap_bosses.insert({ "ステージ5＿ボス＿デフォルト","graphics/CharacterImg/Boss_Kingdom/デフォルト.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿ダメージ_1","graphics/CharacterImg/Boss_Kingdom/oneHit.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿ダメージ_2","graphics/CharacterImg/Boss_Kingdom/twoHit.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿ダメージ_3","graphics/CharacterImg/Boss_Kingdom/threeHit.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿ダメージ_4","graphics/CharacterImg/Boss_Kingdom/fourHit.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿笑顔","graphics/CharacterImg/Boss_Kingdom/smile.png" });
	imageMap_bosses.insert({ "ステージ5＿ボス＿シルエット","graphics/CharacterImg/Boss_Kingdom/secret.png" });

	// LastEpisode
	imageMap_bosses.insert({ "ラストステージ_ボス","graphics/CharacterImg/Boss_Continent/デフォルト.png" });
}


void CharacterImages::SetImgMapKey_AllCharacter() {

	SetImgMapKey_Player();
	SetImgMapKey_Goddess();
	SetImgMapKey_Girl();
	SetImgMapKey_Bosses();
}



std::string CharacterImages::GetImgMapKey_InCharacters(const std::string& key) {

	if (imageMap_player.count(key) > 0) {
		// プレイヤー
		return imageMap_player[key];
	}
	else if (imageMap_goddess.count(key) > 0) {
		//　女神
		return imageMap_goddess[key];
	}
	else if (imageMap_girl.count(key) > 0) {
		//　少女
		return imageMap_girl[key];
	}
	else if (imageMap_bosses.count(key) > 0) {
		//　ボス
		return imageMap_bosses[key];
	}

	return "Not Found";
}



void CharacterImages::LoadCharacterImg(const std::string& key) {

	std::string path = GetImgMapKey_InCharacters(key);

	if (imageMap_player.count(key) > 0) {

		if (_player_hdl != -1)	
			DeleteGraph(_player_hdl);
		
		_player_hdl = LoadGraph(path.c_str());
	}

	if (imageMap_goddess.count(key) > 0) {

		if (_goddess_hdl != -1) 
			DeleteGraph(_goddess_hdl);

		_goddess_hdl = LoadGraph(path.c_str());
	}

	if (imageMap_girl.count(key) > 0) {

		if (_girl_hdl != -1)	
			DeleteGraph(_girl_hdl);

		_girl_hdl = LoadGraph(path.c_str());
	}

	if (imageMap_bosses.count(key) > 0) {

		if (_boss_hdl != -1)   
			DeleteGraph(_boss_hdl);

		_boss_hdl = LoadGraph(path.c_str());
	}
}


void CharacterImages::RenderCharacterImage(
	const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path) {

	if (imageMap_player.count(path) > 0) {
		// プレイヤー
		DrawRotaGraph(x, y, size, 0, _player_hdl, isTranslucent);
	}
	else if (imageMap_goddess.count(path) > 0) {
		// 女神
		DrawRotaGraph(x, y, size, 0, _goddess_hdl, isTranslucent);
	}
	else if (imageMap_girl.count(path) > 0) {
		// 少女
		DrawRotaGraph(x, y, size, 0, _girl_hdl, isTranslucent);
	}
	else if (imageMap_bosses.count(path) > 0) {
		// ボス
		DrawRotaGraph(x, y, size, 0, _boss_hdl, isTranslucent);
	}
}