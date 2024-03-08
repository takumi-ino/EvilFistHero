#include "CharacterImages.h"



void CharacterImages::SetImgMapKey_Player() {

	imageMap_player.insert({ "�����G2�Q�v���C���[","graphics/CharacterImg/Protagonist/StandingPose2.png" });
	imageMap_player.insert({ "�h�������Q�v���C���[", "graphics/CharacterImg/Protagonist/�\���/�h������.png" });
	imageMap_player.insert({ "�m�[�}���Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�m�[�}��.png" });
	imageMap_player.insert({ "�m�[�}��2","graphics/CharacterImg/Protagonist/�\���/�m�[�}��2.png" });
	imageMap_player.insert({ "�����Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/����.png" });
	imageMap_player.insert({ "�Ί�1�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�Ί�1.png" });
	imageMap_player.insert({ "�Ί�2�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�Ί�2.png" });
	imageMap_player.insert({ "�Ί�3�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�Ί�3.png" });
	imageMap_player.insert({ "�{��1�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�{��1.png" });
	imageMap_player.insert({ "�{��2�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�{��2.png" });
	imageMap_player.insert({ "����Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/����.png" });
	imageMap_player.insert({ "����2�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/����2.png" });
	imageMap_player.insert({ "����3�Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/����3.png" });
	imageMap_player.insert({ "�^��Q�v���C���[","graphics/CharacterImg/Protagonist/�\���/�^��.png" });
}

void CharacterImages::SetImgMapKey_Goddess() {

	imageMap_goddess.insert({ "�m�[�}���Q���_", "graphics/CharacterImg/Goddess/normal.png" });
	imageMap_goddess.insert({ "�Ί�Q���_","graphics/CharacterImg/Goddess/smile.png" });
	imageMap_goddess.insert({ "�^���Q���_","graphics/CharacterImg/Goddess/serious.png" });
	imageMap_goddess.insert({ "�V���G�b�g�Q���_","graphics/CharacterImg/Goddess/secret.png" });
}

void CharacterImages::SetImgMapKey_Girl() {

	imageMap_girl.insert({ "�m�[�}���Q����","graphics/CharacterImg/Girl/girl_normal.png" });
	imageMap_girl.insert({ "�^���Q����","graphics/CharacterImg/Girl/girl_serious.png" });
	imageMap_girl.insert({ "�Ί�Q����","graphics/CharacterImg/Girl/girl_smile.png" });
	imageMap_girl.insert({ "�{��1�Q����","graphics/CharacterImg/Girl/girl_mad1.png" });
	imageMap_girl.insert({ "�{��2�Q����","graphics/CharacterImg/Girl/girl_mad2.png" });
	imageMap_girl.insert({ "�V���G�b�g�Q����","graphics/CharacterImg/Girl/girl_secret.png" });
}

void CharacterImages::SetImgMapKey_Bosses() {

	// Episode1
	imageMap_bosses.insert({ "�X�e�[�W1�Q�{�X�Q�f�t�H���g","graphics/CharacterImg/Boss_Forest/�f�t�H���g.png" });

	// Episode2
	imageMap_bosses.insert({ "�X�e�[�W2�Q�{�X�Q�f�t�H���g","graphics/CharacterImg/Boss_Village/�f�t�H���g.png" });
	imageMap_bosses.insert({ "�X�e�[�W2�Q�{�X�Q�_���[�W_1","graphics/CharacterImg/Boss_Village/oneHit.png" });

	// Episode3
	imageMap_bosses.insert({ "�X�e�[�W3�Q�{�X�Q�f�t�H���g","graphics/CharacterImg/Boss_City/�f�t�H���g.png" });
	imageMap_bosses.insert({ "�X�e�[�W3�Q�{�X�Q�_���[�W_1","graphics/CharacterImg/Boss_City/oneHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W3�Q�{�X�Q�_���[�W_2","graphics/CharacterImg/Boss_City/twoHit.png" });

	// Episode4
	imageMap_bosses.insert({ "�X�e�[�W4�Q�{�X�Q�f�t�H���g","graphics/CharacterImg/Boss_Theocracy/�f�t�H���g.png" });
	imageMap_bosses.insert({ "�X�e�[�W4�Q�{�X�Q�_���[�W_1","graphics/CharacterImg/Boss_Theocracy/oneHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W4�Q�{�X�Q�_���[�W_2","graphics/CharacterImg/Boss_Theocracy/twoHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W4�Q�{�X�Q�_���[�W_3","graphics/CharacterImg/Boss_Theocracy/threeHit.png" });

	// Episode5
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�f�t�H���g","graphics/CharacterImg/Boss_Kingdom/�f�t�H���g.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�_���[�W_1","graphics/CharacterImg/Boss_Kingdom/oneHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�_���[�W_2","graphics/CharacterImg/Boss_Kingdom/twoHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�_���[�W_3","graphics/CharacterImg/Boss_Kingdom/threeHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�_���[�W_4","graphics/CharacterImg/Boss_Kingdom/fourHit.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�Ί�","graphics/CharacterImg/Boss_Kingdom/smile.png" });
	imageMap_bosses.insert({ "�X�e�[�W5�Q�{�X�Q�V���G�b�g","graphics/CharacterImg/Boss_Kingdom/secret.png" });

	// LastEpisode
	imageMap_bosses.insert({ "���X�g�X�e�[�W_�{�X","graphics/CharacterImg/Boss_Continent/�f�t�H���g.png" });
}


void CharacterImages::SetImgMapKey_AllCharacter() {

	SetImgMapKey_Player();
	SetImgMapKey_Goddess();
	SetImgMapKey_Girl();
	SetImgMapKey_Bosses();
}



std::string CharacterImages::GetImgMapKey_InCharacters(const std::string& key) {

	if (imageMap_player.count(key) > 0) {
		// �v���C���[
		return imageMap_player[key];
	}
	else if (imageMap_goddess.count(key) > 0) {
		//�@���_
		return imageMap_goddess[key];
	}
	else if (imageMap_girl.count(key) > 0) {
		//�@����
		return imageMap_girl[key];
	}
	else if (imageMap_bosses.count(key) > 0) {
		//�@�{�X
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
		// �v���C���[
		DrawRotaGraph(x, y, size, 0, _player_hdl, isTranslucent);
	}
	else if (imageMap_goddess.count(path) > 0) {
		// ���_
		DrawRotaGraph(x, y, size, 0, _goddess_hdl, isTranslucent);
	}
	else if (imageMap_girl.count(path) > 0) {
		// ����
		DrawRotaGraph(x, y, size, 0, _girl_hdl, isTranslucent);
	}
	else if (imageMap_bosses.count(path) > 0) {
		// �{�X
		DrawRotaGraph(x, y, size, 0, _boss_hdl, isTranslucent);
	}
}