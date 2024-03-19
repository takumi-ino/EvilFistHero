#pragma once
#include "../Manager/SceneManager/SceneBase.h"
#include "Symbol/SymbolOfStageMap.h"

class EnemyBoss;


//　ワールドマップからステージを選ぶ（　SceneConversation の次　）
class SceneStageMap : public SceneBase
{
public:

	SceneStageMap();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;
	void ReleaseMem() override;

	// プレイヤーおよびボスのHPを初期化
	void ResetHP_BeforeStartGame(const SymbolOfStageMap::TYPE symbol);

private:

	// ゲーム開始前の最終確認
	void ShowFinalCheck_BeforeStartGame();

	// エンターキーでゲームスタート
	void GameStartByInput();

	void MoveToScenePlay();
	
	// 講師配布のライブラリ機能。メモリのロードなど1度だけ実行したい処理で Sequence クラスを使用
	tnl::Sequence<SceneStageMap> _sequence = tnl::Sequence<SceneStageMap>(this, &SceneStageMap::SeqIdle);
	bool SeqIdle(float deltaTime);

private:

	SymbolOfStageMap* _symbolOfStageMap = nullptr;  // ステージマップ上に表示するシンボル

private:

	// 背景画像ハンドル
	int              _backGroundImage_hdl{};
};