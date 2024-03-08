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
	  �@ �e�摜�N���X�@CharacterImages�A�@BackGroundImages�@�ł�
	  �@�摜�̃��[�h�� std::unordered_map���g�p����B���̃N���X�̃��[�h�֐�����͂��� Key(pathName) ��n��
	*/

	// �w�i�@--------------------------------------------------------------------------------
	void LoadBackGroundImage(const std::string& pathName);
	void SetBackGroundMapKey();
	void RenderBackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent);

	// �L�����N�^�[�@--------------------------------------------------------------------------------
	void LoadCharacterImage(const std::string& key);
	void SetCharacterMapKey();
	void RenderCharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);

private:

	std::unique_ptr<BackGroundImages> _BG_IMAGE;   // �w�i�Ƃ��̑��A�Z�b�g�摜
	std::unique_ptr<CharacterImages>  _CHAR_IMAGE; // �L�����N�^�[�摜
};