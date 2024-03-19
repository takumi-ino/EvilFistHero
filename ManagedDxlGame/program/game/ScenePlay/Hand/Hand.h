#pragma once
#include "../../../utility/tnlSequence.h"
#include "../../../utility/DxLib_Engine.h"
#include "../Slider/SliderEvent.h"

/*
　　　　　 ScenePlay でプレイヤーとボスが使用する手をそれぞれ管理

	  主に手の描画処理、敗者のHPを減らす処理、手を選ぶときの入力処理などがある
*/

class Hand
{
public:

	// 手の種類
	enum HandType
	{
		HAND_TYPE_STONE,
		HAND_TYPE_SCISSORS,
		HAND_TYPE_PAPER,
		HAND_TYPE_MAX
	};

	// 結果
	enum JankenResult {

		RESULT_TYPE_WIN,
		RESULT_TYPE_LOSE,
		RESULT_TYPE_DRAW,
		RESULT_TYPE_MAX
	};

public:

	// 初期化----------------------------------------------------------------------------------
	Hand() {

		LoadAllHandHandle();
	}

	//　画像ハンドル
	void LoadAllHandHandle(); 

	//　----------------------------------------------------------------------------------
	// ジャンケン勝敗結果をリザルト保持変数へ代入
	void AssignJankenResult();	

	// プレイヤーが手を選ぶときにする左右の入力
	void UpdateSelectHandCursorPos();	

	// 敗者のHPを1減らす
	void SubtractLosersHP(int& playerHP, int& _bossHP);	

	// 描画----------------------------------------------------------------------------------
	 
	// 勝敗結果を示す画像
	void RenderJankenResultImage();

	// 勝敗結果を示すテキスト
	void RenderJankenResultText(const int playerHP, const int enemyHP);

private:

	// グー、チョキ、パーの画像表示
	void RenderPlayerHandSelection();

public:

	// グー、チョキ、パーの画像のハンドル
	static int _gpc_handImageHandle[HAND_TYPE_MAX];

	// グー、チョキ、パーの画像の表示位置。プレイヤー、ボスともにこの値の差分を使用し、手を表示
	static const tnl::Vector3 GU_CHOKI_PA_IMAGE_POSITIONS[HAND_TYPE_MAX];

	//プレイヤー---------------------------------------------------------------------
	static int   _playerHandIndex;                      // プレイヤーの手
	static const tnl::Vector3 RESULT_PLAYER_HAND_POS;   // プレイヤーの手の位置

	//ボス---------------------------------------------------------------------------
	static int  _bossSelectedHand;                      // ボスが実際に出した手
	static bool _canSelectBossHand;                     // ボスが手を選択できる状態か

	// ボスの出す手の確率の組み合わせ。スライダーイベントの成績によって４段階に分かれる
	static std::vector<int> _bossHandProbabilitiesByGrade[SliderEvent::MAXINDEX];

	// ボスが出すグー、チョキ、パーの確率をそれぞれ格納
	static int _guHandProbability, _chokiHandProbability, _paHandProbability;

	static const tnl::Vector3 RESULT_BOSS_HAND_POS;

private:

	//　カーソルのハンドル
	int  _gpc_cursor_hdl;

	// ジャンケンの勝敗を番号で取得
	int  _jankenResult;

	//　勝敗がついたか
	bool _isBattleOver{};

	// プレイヤーが手を選択するときに使用するカーソルの座標
	tnl::Vector3 _PLAYER_CURSOR_POS = GU_CHOKI_PA_IMAGE_POSITIONS[_playerHandIndex];
};