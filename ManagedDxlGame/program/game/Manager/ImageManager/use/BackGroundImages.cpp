#include "BackGroundImages.h"


void BackGroundImages::SetImgMapKey_BackGround() {

	_backGroundMap.insert({ "�X�e�[�W1","graphics/BattleScene/Forest.png" });
	_backGroundMap.insert({ "�X�e�[�W2","graphics/BattleScene/Village.png" });
	_backGroundMap.insert({ "�X�e�[�W3","graphics/BattleScene/City.png" });
	_backGroundMap.insert({ "�X�e�[�W4","graphics/BattleScene/Theocracy.png" });
	_backGroundMap.insert({ "�X�e�[�W5","graphics/BattleScene/Kingdom.png" });
	_backGroundMap.insert({ "���X�g�X�e�[�W","graphics/BattleScene/Continent.png" });

	_backGroundMap.insert({ "�^�C�g��","graphics/Title.png" });
	_backGroundMap.insert({ "�^�C�g�����S","graphics/TitleLogo.png" });
	_backGroundMap.insert({ "�^�C�g�����j���[","graphics/TitleMenu.png" });

	_backGroundMap.insert({ "�v�����[�O","graphics/PrologueBG.jpg" });
	_backGroundMap.insert({ "�G�s���[�O","graphics/EpilogueBG.jpg" });

	_backGroundMap.insert({ "��","graphics/Morning.jpg" });
	_backGroundMap.insert({ "�[��","graphics/Evening.jpg" });
	_backGroundMap.insert({ "��","graphics/Night.jpg" });

	_backGroundMap.insert({ "���[���h�}�b�v","graphics/WorldMap.png" });
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