#pragma once
#include "BackGroundImages.h"
#include "CharacterImages.h"

class ImageManager
{
private:

	ImageManager() {}


	std::unique_ptr<BackGroundImages> _BG_IMAGE;   // 背景とその他アセット画像
	std::unique_ptr<CharacterImages>  _CHAR_IMAGE; // キャラクター画像

public:

	static ImageManager& GetInstance() {

		static ImageManager instance;
		return instance;
	}


	// 背景画像の Key は BackGroundImages.cpp を参照
	void Set_BackGroundMapKey();
	void Load_BackGroundImage(const std::string& pathName);
	void Render_BackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent);

	// キャラクター画像の Key は CharacterImages.cpp を参照
	void Set_CharacterMapKey();
	void Load_CharacterImage(const std::string& key);
	void Render_CharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);
};