#pragma once
#include "../../../utility/DxLib_Engine.h"
#include "../../../utility/tnlSequence.h"
#include "SoundType_BGM.h"


class SoundManager
{
private:

	SoundManager(){}

	std::unique_ptr<SoundType_BGM> _BGM;

public:
	
	static SoundManager& GetInstance() {

		static SoundManager instance;
		return instance;
	}

	void LoadBGM( const char* pathName);
	void PlayBGM();
	void StopBGM();
};