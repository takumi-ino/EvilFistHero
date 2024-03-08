#include "ImageManager.h"
#include "BackGroundImages.h"
#include "CharacterImages.h"


// 背景画像マップの Key
void ImageManager::SetBackGroundMapKey() {

	_BG_IMAGE = std::make_unique<BackGroundImages>();

	if (_BG_IMAGE)
		_BG_IMAGE->SetImgMapKey_BackGround();
}

// 背景画像のロード
void ImageManager::LoadBackGroundImage(const std::string& key) {

	if (_BG_IMAGE)
		_BG_IMAGE->LoadBackGroundImg(key);
}


// 背景画像の描画
void ImageManager::RenderBackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent) {

	if (_BG_IMAGE) 
		_BG_IMAGE->RenderBackGroundImg(x,y,size,isTranslucent);
}


// キャラクター画像マップの Key
void ImageManager::SetCharacterMapKey() {

	_CHAR_IMAGE = std::make_unique<CharacterImages>();

	if (_CHAR_IMAGE)
		_CHAR_IMAGE->SetImgMapKey_AllCharacter();
}


// キャラクター画像の ロード
void ImageManager::LoadCharacterImage(const std::string& key) {

	if (_CHAR_IMAGE)
		_CHAR_IMAGE->LoadCharacterImg(key);
}


void ImageManager::RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent,const std::string& path) {

	if (_CHAR_IMAGE) 
		_CHAR_IMAGE->RenderCharacterImage(x, y, size, isTranslucent, path);
}