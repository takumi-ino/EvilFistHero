#include "ImageManager.h"
#include "BackGroundImages.h"
#include "CharacterImages.h"


// 背景画像マップの Key
void ImageManager::Set_BackGroundMapKey() {

	_BG_IMAGE = std::make_unique<BackGroundImages>();


	if (_BG_IMAGE) _BG_IMAGE->SetImgMapKey_BackGround();
}

// 背景画像のロード
void ImageManager::Load_BackGroundImage(const std::string& key) {


	if (_BG_IMAGE) _BG_IMAGE->LoadBackGroundImg(key);
}


// 背景画像の描画
void ImageManager::Render_BackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent) {

	if (_BG_IMAGE) _BG_IMAGE->RenderBackGroundImg(x,y,size,isTranslucent);

}



// キャラクター画像マップの Key
void ImageManager::Set_CharacterMapKey() {

	_CHAR_IMAGE = std::make_unique<CharacterImages>();


	if (_CHAR_IMAGE) _CHAR_IMAGE->SetImgMapKey_AllCharacter();
}


// キャラクター画像の ロード
void ImageManager::Load_CharacterImage(const std::string& key) {

	if (_CHAR_IMAGE) _CHAR_IMAGE->LoadCharacterImg(key);
}


void ImageManager::Render_CharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent,const std::string& path) {

	if (_CHAR_IMAGE) _CHAR_IMAGE->RenderCharacterImage(x, y, size, isTranslucent, path);
}





// ↓　使ってません

//// アセット画像マップの Key
//void ImageManager::Get_SomeAssetsMapKey(const std::string& key) {
//
//	if (_BG_ASSETS_IMAGE) _BG_ASSETS_IMAGE->GetImgMapKey_SomeAssets(key);
//}
//
//
//// アセット画像の ロード
//void ImageManager::Load_SomeAssetsImage(const std::string& key) {
//
//	if (_BG_ASSETS_IMAGE) _BG_ASSETS_IMAGE->LoadSomeAssetsImg(key);
//}
//
//
//void ImageManager::Render_SomeAssetsImage(const int& x, const int& y, const double& size, const int& isTranslucent) {
//
//	if (_BG_ASSETS_IMAGE) _BG_ASSETS_IMAGE->RenderAssetsImg(x, y, size, isTranslucent);
//
//}
//
