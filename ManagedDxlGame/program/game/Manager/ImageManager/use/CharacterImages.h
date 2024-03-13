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

	// このクラス内の std::unordered_map型変数の KeyとValueの設定を一括実行
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

	//　char型は std::hashに対応していないので、unordered_map<char*, char*>は不可
	std::unordered_map < std::string, std::string > imageMap_player{};
	std::unordered_map < std::string, std::string > imageMap_goddess{};
	std::unordered_map < std::string, std::string > imageMap_girl{};
	std::unordered_map < std::string, std::string > imageMap_bosses{};
};