#pragma once


class CharacterImages {
public:

	CharacterImages() {}
	explicit CharacterImages(std::string str) {}

	~CharacterImages() {
	
		DeleteGraph(_player_hdl);
		DeleteGraph(_goddess_hdl);
		DeleteGraph(_girl_hdl);
		DeleteGraph(_boss_hdl);
	}

	void RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);

	void LoadCharacterImg(const std::string& key);

	// ���̃N���X���� std::unordered_map�^�ϐ��� Key��Value�̐ݒ���ꊇ���s
	void SetImgMapKey_AllCharacter();

	std::string GetImgMapKey_InCharacters(const std::string& key);

private:

	void SetImgMapKey_Player();
	void SetImgMapKey_Goddess();
	void SetImgMapKey_Girl();
	void SetImgMapKey_Bosses();

private:

	int _player_hdl{};
	int _goddess_hdl{};
	int _girl_hdl{};
	int _boss_hdl{};

	//�@char�^�� std::hash�ɑΉ����Ă��Ȃ��̂ŁAunordered_map<char*, char*>�͕s��
	std::unordered_map < std::string, std::string > imageMap_player{};
	std::unordered_map < std::string, std::string > imageMap_goddess{};
	std::unordered_map < std::string, std::string > imageMap_girl{};
	std::unordered_map < std::string, std::string > imageMap_bosses{};
};