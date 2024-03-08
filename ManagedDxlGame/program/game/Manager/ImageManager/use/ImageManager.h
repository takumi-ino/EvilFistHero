#pragma once
#include "BackGroundImages.h"
#include "CharacterImages.h"

class ImageManager
{
private:

	ImageManager() {}

public:

	static ImageManager& GetInstance() {

		static ImageManager instance;
		return instance;
	}

	/*
	  　 各画像クラス　CharacterImages、　BackGroundImages　では
	  　画像のロードに std::unordered_mapを使用する。このクラスのロード関数からはその Key(pathName) を渡す
	*/

	// 背景　--------------------------------------------------------------------------------
	void LoadBackGroundImage(const std::string& pathName);
	void SetBackGroundMapKey();
	void RenderBackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent);

	// キャラクター　--------------------------------------------------------------------------------
	void LoadCharacterImage(const std::string& key);
	void SetCharacterMapKey();
	void RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);

private:

	std::unique_ptr<BackGroundImages> _BG_IMAGE;   // 背景とその他アセット画像
	std::unique_ptr<CharacterImages>  _CHAR_IMAGE; // キャラクター画像
};