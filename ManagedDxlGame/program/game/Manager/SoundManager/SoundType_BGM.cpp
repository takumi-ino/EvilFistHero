#include "SoundType_BGM.h"
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"


SoundType_BGM::SoundType_BGM(const char* path)
{
	_BGM_hdl = LoadSoundMem(path);
}

SoundType_BGM::~SoundType_BGM()
{
	DeleteSoundMem(_BGM_hdl);
}

void SoundType_BGM::Play()
{
	PlaySoundMem(_BGM_hdl, DX_PLAYTYPE_BACK, true);
}

void SoundType_BGM::Stop()
{
	StopSoundMem(_BGM_hdl);
}
