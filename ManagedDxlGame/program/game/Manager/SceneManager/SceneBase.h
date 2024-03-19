#pragma once

class SceneBase
{
public:

	virtual ~SceneBase(){}

	virtual void Initialize() {}
	virtual void Update(const float deltaTime) {}
	virtual void Render(const float deltaTime) {}
	virtual void ReleaseMem() {}
};