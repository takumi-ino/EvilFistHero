#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"


class SoundType_BGM
{
private:

	int _BGM_hdl;

public:

	SoundType_BGM() {}
	SoundType_BGM(const char* path);

	~SoundType_BGM();

	void Play();
	void Stop();
};