#pragma once
#include "../../../../utility/DxLib_Engine.h"

class BackGroundImages
{
public:

	BackGroundImages(){}
	explicit BackGroundImages(const char* path) {}

	~BackGroundImages() {
		DeleteGraph(_BG_hdl);
	}

	// 背景画像ロード
	void LoadBackGroundImg(const std::string& key);

	// unordered_mapで使用する画像呼び出し用のキーをセット
	void SetImgMapKey_BackGround();

	void RenderBackGroundImg(const int& x, const int& y, const double& size, const int& isTranslucent);

private:

	std::string GetImgMapKey_BackGround(const std::string& key);

private:

	int _BG_hdl{};

	std::unordered_map < std::string, std::string > _backGroundMap;
};