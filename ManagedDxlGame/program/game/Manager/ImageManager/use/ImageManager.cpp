#include "ImageManager.h"
#include "BackGroundImages.h"
#include "CharacterImages.h"


// �w�i�摜�}�b�v�� Key
void ImageManager::SetBackGroundMapKey() {

	_BG_IMAGE = std::make_unique<BackGroundImages>();

	if (_BG_IMAGE)
		_BG_IMAGE->SetImgMapKey_BackGround();
}

// �w�i�摜�̃��[�h
void ImageManager::LoadBackGroundImage(const std::string& key) {

	if (_BG_IMAGE)
		_BG_IMAGE->LoadBackGroundImg(key);
}


// �w�i�摜�̕`��
void ImageManager::RenderBackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent) {

	if (_BG_IMAGE) 
		_BG_IMAGE->RenderBackGroundImg(x,y,size,isTranslucent);
}


// �L�����N�^�[�摜�}�b�v�� Key
void ImageManager::SetCharacterMapKey() {

	_CHAR_IMAGE = std::make_unique<CharacterImages>();

	if (_CHAR_IMAGE)
		_CHAR_IMAGE->SetImgMapKey_AllCharacter();
}


// �L�����N�^�[�摜�� ���[�h
void ImageManager::LoadCharacterImage(const std::string& key) {

	if (_CHAR_IMAGE)
		_CHAR_IMAGE->LoadCharacterImg(key);
}


void ImageManager::RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent,const std::string& path) {

	if (_CHAR_IMAGE) 
		_CHAR_IMAGE->RenderCharacterImage(x, y, size, isTranslucent, path);
}