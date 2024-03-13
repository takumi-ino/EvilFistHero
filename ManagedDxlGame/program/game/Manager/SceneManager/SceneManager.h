#pragma once
#include "../../../utility/DxLib_Engine.h"
#include "../../../utility/tnlSequence.h"
#include "../../Manager/SceneManager/SceneBase.h"

class SceneManager : public SceneBase
{
public:

	static SceneManager* GetInstance(SceneBase* startScene = nullptr);

	void ChangeScene(SceneBase* next_scene, float trans_time = 0.5f);
	void ReleaseMem();

	void Render(float deltaTime);
	void Update(float deltaTime);

private:

	explicit SceneManager(SceneBase* start_scene);

	tnl::Sequence<SceneManager> _sequence = tnl::Sequence<SceneManager>(this, &SceneManager::SeqTransIn);

	bool SeqTransIn(const float delta_time);
	bool SeqTransOut(const float delta_time);
	bool SeqRunScene(const float delta_time);

private:

	SceneBase* _now_scene = nullptr;
	SceneBase* _next_scene = nullptr;

private:

	float _transTime = 0.5f;
	int   _transGraph_hdl = 0;
};