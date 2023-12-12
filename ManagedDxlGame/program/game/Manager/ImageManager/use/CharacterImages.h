#pragma once
#include "../../../../utility/DxLib_Engine.h"
#include "../../../../utility/tnlSequence.h"


class CharacterImages {

private:

	int _player_hdl;
	int _goddess_hdl;
	int _girl_hdl;
	int _boss_hdl;


	//@charŒ^‚Í std::hash‚É‘Î‰‚µ‚Ä‚¢‚È‚¢‚Ì‚ÅAunordered_map<char*, char*>‚Í•s‰Â
	std::unordered_map < std::string, std::string > imageMap_player;
	std::unordered_map < std::string, std::string > imageMap_goddess;
	std::unordered_map < std::string, std::string > imageMap_girl;
	std::unordered_map < std::string, std::string > imageMap_bosses;



	void SetImgMapKey_Player();
	void SetImgMapKey_Goddess();
	void SetImgMapKey_Girl();
	void SetImgMapKey_Bosses();

public:


	CharacterImages() {}

	explicit CharacterImages(std::string str) {}

	~CharacterImages() {}

	void RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);



	void SetImgMapKey_AllCharacter();

	// GetKey
	std::string GetImgMapKey_InCharacters(const std::string& key);
	// LoadPath
	void LoadCharacterImg(const std::string& key);
};
