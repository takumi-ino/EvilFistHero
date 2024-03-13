#pragma once


class SoundType_BGM
{
public:

	SoundType_BGM() {}
	SoundType_BGM(const char* path);

	~SoundType_BGM();

	void Play();
	void Stop();

private:

	int _BGM_hdl{};
};