#pragma once
#include "SoundType_BGM.h"


class SoundManager
{
public:
	
	static SoundManager& GetInstance() {

		static SoundManager instance;
		return instance;
	}

	void LoadBGM( const char* pathName);
	void PlayBGM();
	void StopBGM();

private:

	SoundManager(){}

	std::unique_ptr<SoundType_BGM> _BGM;
};