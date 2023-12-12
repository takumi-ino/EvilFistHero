#pragma once

class SceneBase
{
public:
	virtual void Initialize() {}
	virtual void Update(float delta_time) {}
	virtual void Render(float delta_time) {}
	virtual void ReleaseMem() {}
};