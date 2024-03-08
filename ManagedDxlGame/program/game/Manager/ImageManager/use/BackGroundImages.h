#pragma once
#include "../../../../utility/DxLib_Engine.h"
#include "../../../../utility/tnlSequence.h"

class BackGroundImages
{
public:

	BackGroundImages(){}
	explicit BackGroundImages(const char* path) {}

	~BackGroundImages() {

		DeleteGraph(_BG_hdl);
	}

	void LoadBackGroundImg(const std::string& key);

	void SetImgMapKey_BackGround();

	std::string GetImgMapKey_BackGround(const std::string& key);

	void RenderBackGroundImg(const int& x, const int& y, const double& size, const int& isTranslucent);

private:

	int _BG_hdl{};

	std::unordered_map < std::string, std::string > _backGroundMap;
};