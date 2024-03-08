#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/StageSymbol.h"
#include "../ScenePlay/Boss/EnemyBoss.h"
#include "../../utility/DxLib_Engine.h"
#include "../../utility/tnlSequence.h"


class SceneStageMap : public SceneBase
{
public:

	SceneStageMap();

	void Update(float deltaTime) override;
	void Render(float deltaTime) override;
	void ReleaseMem() override;

	// 選択したステージへ飛ぶために必要な情報をセット
	void SetStageInfo_BeforeStartGame(const StageSymbol::Symbol symbol);

private:

	// ゲーム開始前の最終確認
	void ShowFinalCheck_BeforeStartGame();

	// エンターキーでゲームスタート
	void GameStartByInput();
	
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	StageSymbol* _symbolRef_ptr = nullptr;
	EnemyBoss*   _bossRef_ptr = nullptr;

private:

	// 背景画像ハンドル
	int          _bgImage_hdl{};
};