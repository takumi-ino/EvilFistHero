#pragma once
#include "BackGroundImages.h"
#include "CharacterImages.h"

class ImageManager
{
private:

	ImageManager() {}


	std::unique_ptr<BackGroundImages> _BG_IMAGE;   // �w�i�Ƃ��̑��A�Z�b�g�摜
	std::unique_ptr<CharacterImages>  _CHAR_IMAGE; // �L�����N�^�[�摜

public:

	static ImageManager& GetInstance() {

		static ImageManager instance;
		return instance;
	}


	// �w�i�摜�� Key �� BackGroundImages.cpp ���Q��
	void Set_BackGroundMapKey();
	void Load_BackGroundImage(const std::string& pathName);
	void Render_BackGroundImage(const int& x, const int& y, const double& size, const int& isTranslucent);

	// �L�����N�^�[�摜�� Key �� CharacterImages.cpp ���Q��
	void Set_CharacterMapKey();
	void Load_CharacterImage(const std::string& key);
	void Render_CharacterImage(const int& x, const int& y, const double& size, const int& isTranslucent, const std::string& path);
};