#include "BackGroundImages.h"


void BackGroundImages::SetImgMapKey_BackGround() {

	_backGroundMap.insert({ "ステージ1","graphics/BattleScene/Forest.png" });
	_backGroundMap.insert({ "ステージ2","graphics/BattleScene/Village.png" });
	_backGroundMap.insert({ "ステージ3","graphics/BattleScene/City.png" });
	_backGroundMap.insert({ "ステージ4","graphics/BattleScene/Theocracy.png" });
	_backGroundMap.insert({ "ステージ5","graphics/BattleScene/Kingdom.png" });
	_backGroundMap.insert({ "ラストステージ","graphics/BattleScene/Continent.png" });

	_backGroundMap.insert({ "タイトル","graphics/Title.png" });
	_backGroundMap.insert({ "タイトルロゴ","graphics/TitleLogo.png" });
	_backGroundMap.insert({ "タイトルメニュー","graphics/TitleMenu.png" });

	_backGroundMap.insert({ "プロローグ","graphics/PrologueBG.jpg" });
	_backGroundMap.insert({ "エピローグ","graphics/EpilogueBG.jpg" });

	_backGroundMap.insert({ "朝","graphics/Morning.jpg" });
	_backGroundMap.insert({ "夕方","graphics/Evening.jpg" });
	_backGroundMap.insert({ "夜","graphics/Night.jpg" });

	_backGroundMap.insert({ "ワールドマップ","graphics/WorldMap.png" });
}


std::string BackGroundImages::GetImgMapKey_BackGround(const std::string& key ) {

	if (_backGroundMap.count(key) >! 0) 
		return "file not found";

	return _backGroundMap[key];
}


void BackGroundImages::LoadBackGroundImg(const std::string& key) {

	if (_BG_hdl != -1)	
		DeleteGraph(_BG_hdl);	

	_BG_hdl = LoadGraph(GetImgMapKey_BackGround(key).c_str());
}


void BackGroundImages::RenderBackGroundImg(const int& x, const int& y, const double& size, const int& isTranslucent) {

	DrawRotaGraph(x, y, size, 0, _BG_hdl, isTranslucent);
}