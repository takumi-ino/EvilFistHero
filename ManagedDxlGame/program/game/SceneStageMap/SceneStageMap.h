#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/StageSymbol.h"

class EnemyBoss;

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
	
	// 講師配布のライブラリ。メモリのロードなど1度だけ実行したい処理で Sequence クラスを使用
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	StageSymbol* _symbolRef_ptr = nullptr;
	EnemyBoss*   _bossRef_ptr = nullptr;

private:

	// 背景画像ハンドル
	int          _bgImage_hdl{};
};