#include "../../../utility/DxLib_Engine.h"
#include "../../../utility/tnlSequence.h"
#include "../../Button/DialogueButtons.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "SceneConversation.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include "../../Manager/SceneManager/SceneManager.h"


int SceneConversation::_CURRENT_TEXTROW = 0;
int SceneConversation::Prologue_Epilogue = 0;


namespace {

	// CSVロード関数が日本語に対応していないため、ここに直にテキストを置いています.......

	std::string prologueTextLog[140] = {

		"・・・・・・・・・",

		"・・・・・・・・・",

			"・・・・・・・・・",

			"それは深い眠りについているかのような感覚だった。",

			"ゆ・・・し・・・・ま！",

			"体を動かすことも、何かを考えることさえ億劫なそんな状態の中、何やら声が聴こえて来る。",

			"「ゆうしゃさま！！！」",

			"！？！？！？",

			"まるで気持ちよく眠っていた自分を嘲笑うかのように、その甲高い声は俺を叩き起こした。",

			"「う・・・・」",

			"「あ！？やっと起きてくださいましたね、勇者様！」",


			"鈍く痛む頭を手で押さえながら、ゆっくりと体を起こす。",

			"「・・・ここは？」",


			"現状を把握するため周囲を見渡すが、すぐさま混乱に陥る。",

			"そこは薄暗い空間だった。棒状のライト(？)が頼りなく暗闇を照らしている。",

			"後方を確認するとやはり同じように暗かったが、今自分がいる場所は目の前の扉に続く一本道\nのようだということが辛うじて分かった。",

			"(・・・あれ？・・寝ぼけてるのか？)",

			"不思議なことに目を覚ます前までのことを思い出せない。混乱による一時的なものなのか、\nそれとも記憶を失ってしまったのか、それすら判断出来なかった。",

			"しかも疑問に思ったのはそれだけではない。",

			"先程声を発していた目の前の女性に目を向ける。",

			"数秒観察してみたが、どうあがいてもそれは俺の全く知らない人物だった。",

			"(頭に変な王冠みたいのを載せてるし、変わった服を着ている。・・コスプレか？)",

			"(いやコスプレイヤーと暗闇で二人きりとかどんな状況だよ)",

			"こうして考えていても仕方がない、直接訊いた方が早いだろう。",

			"「・・・・・・あのー、すみません。ここはどこですか？」",

			"そう訊くと女性は目を逸らし、小さな声で返答した。",

			"「・・・・冥界」",

			"「は？」",

			"「勇者様、突如こちらの世界へお呼びしてしまった非礼をお詫び申し上げると共に、先にお伝え\nすることがございます」",

			"俺の目を真っ直ぐ見つめ、一呼吸おいてから再び口を開く。",

			"「あなたは死にました」",

			"・・・・・は？",

			"「混乱されるお気持ちはよく分かりますが、落ち着いてください」",

			"「あなたは死んだ、そして蘇ったのです、人の国【シュルス帝国】を救う勇者として」",

			"-----------------------------------",

			"「そんなゴミを見るような目で見つめないでください、私は真剣なのです！」",

			"何？俺今そんな顔してるのか？完全に無意識だった。",

			"「勇者様！あなた様は人の子の代表として勇者に選ばれたのです。そして選ばれた者はその責務を全うし、\n人々に安寧と秩序を齎さなくてはなりません」",

			"「これからあなた様は修羅の道を進むことになるでしょう。ですがご心配には及びません！」",

			"(・・嘘を言っているようには見えないけど内容があまりに馬鹿馬鹿しい。新手の詐欺か、もしくは\n不思議ちゃんなのか・・・？)",

			"「あなた様が選ばれたことにははっきりとした理由があるのです！強い意志を宿した瞳、精悍な面持ち、\n気高く美しく燃えるその魂・・・」",

			"「本来であれば一度死んだ魂は浄化されるまで。地上に戻ることは許されません」",

			"「しかし、他の神々との話し合いの結果、いくつかの制約付きで今回は特例を設けることと致しました」",

			"「特例？」",

			"「はい！勇者様の魂を再び地上に戻すことは神々の掟で禁じられています、が」",

			"「勇者様が今迄積んできた徳から鑑みて、今回は特例として別世界への転生が認められたのです」",

			"「つきましては、勇者様には是非その清く真っ直ぐな心を貫き通し、今の【シュルス帝国】を正しい道に\n導く先駆者となっていただきたく思います！」",

			"何を言っているのかさっぱり分からなかったが、ここで俺はある一つの可能性に気が付く。\n",

			"(ドッキリか？！)",

			"今聞かされている訳の分からない話よりは余程現実性が高い。",

			"ひとたびその考えに辿り着くと、先程まで抱えていた緊張と不安が少しだけ和らいだことを感じる。",

			"（いやでも他にどう説明するんだ？誘拐？夢？）",

			"まず誘拐という線はないだろう。そうであればこのような茶番に意味はない。",

			"であれば夢か？",

			"・・・",

			"もし夢であれば目が覚めたら全て忘れよう。こんなのただの黒歴史だ。",

			"ひとまず情報を得るため、適当に返答してみることにした。",

		   "「えーっと・・・・その話って俺に何かメリットとかってあったりするんですか？」",

			"「え？」",

			"意外な反応だったのか、目の前の女神(笑)はキョトンとした表情で固まる。",

			"「え？だってそれって要するに自分の身を危険に晒して誰かと戦えってことですよね？」",

			"「ゆ、勇者様？こ、これは人類にとってとても栄光のある使命なのですよ？！選ばれしものだけが得られる\n至高の----」",

		   "「あと何故俺がその勇者ってのに選ばれたんですか？自分で言うのもなんですけど俺って特に取り柄\nとかないし・・」",

		   "話を遮られて少し不満だったのか、女神(笑)からは先程までの笑顔が消えていた。",

			"「・・・申し訳ございませんが、今それをお伝えする時間はございません。勇者様には一刻も早く地上へ戻り、\n人々に救いの手を差し伸べて欲しいのです」",

			"(いつまで続くんだろうこれ・・・・)",

		   "「これは新たなる伝説の始まりとなるでしょう、勇者様に女神の祝福があらんことを・・・」",

		   "「いや、話は終わってな-----」",



		   //	"------------------------------------------------------------暗転--------------------------------------------------------------",

				"--------------------------------------------------------",

				"------------------------------------------",

				"----------------------------",

				   "「うおぉぉっっ！！？」",

				   "「あ、来たわね？」",

				   "突然真っ暗になったと思ったら今度は先程とは違う景色が映し出された。",

				   "どうやら、さっきの女神(笑)が俺をここに転移させたようだ・・・って、転移？？！！",

				   "頬をつねってみたが、普通に痛い。まさかそんなことをする日が来るとは思いもよらなかった。",

				   "（・・・・・・）",

				   "転移の際、恐らく一瞬だけ俺の体はこの世から存在を消していた。",

				   "一瞬の出来事だったため確証はないが、恐らくあれは本物だった。しかしそれを言っても信じる者は\nいないだろう。先程までの自分と同じように。",

				   "ただ、本物でなければこの状況をどう説明しろというのか。",

				   "・・・救いを求めるように辺りを見渡し、一人の少女と目が合った。",

				   "「・・・何か考え中のとこ悪いけど時間がないの、さっそく話を始めるわ」",

				   "(あれ・・・？デジャヴ？)",

				   "つい最近同じようなことがあったような気がするのだが、気のせいか？",

				   "少女は宣言通り、こちらの精神状態など知らんとでも言わんばかりに勝手に話を始めた。",

				   "「勇者として生まれ変わったというのはもう聞いてるわね？」",

				   "「あ、・・・・まあ一応・・・・てか君は？」",

					"「あたしのことは後よ。それよりここに来る前に女神様から何かギフトを授からなかった？」",

					"「ギフト？」",

					"「只の人間がまともに魔女と戦えるわけないじゃない、奴らと戦うためには力が要るわ。どこかに\n印のようなものが刻まれてない？」",

					"そう言われ俺は自身の体をサッと見渡す。",

					"「あ、・・これ？」",

					"右手の甲に赤い紋章のようなものが浮かび上がっている。",

				   "「あ、そうそうそれそれ！分かるわね・・・戦うのよ！それで」",

				  "紋章を見せた途端、少女のテンションが明らかに豹変した。これってそんなに凄いものなのか・・・？",

				 "「それは通称【魔拳】。その刻印を発動することによって神聖なる力を行使することが出来るの」",

				"「具体的に言うと、あなたはこれから敵と戦うとき、【ジャンケン】と呼ばれる儀式を行わなくてはならない」",

				 "「【ジャンケン】に勝つことができれば相手にダメージを与えられる。当然負ければその逆ね」",

				 "「儀式の回数は相手のレベルによって異なるけど、要するに全てに勝てばいいのよ。簡単でしょ？」",

				 "少し癪に障る言い方だったが、俺は敢えてそれを気にしないようにする。",

				 "そんなことより・・・・・・",

				"【ジャンケン】",

				"聞いたことがない単語だった。",

				"しかし不思議なことに何故か俺はそれを知っている。",

				"儀式は初めに３つの属性の内１つを選ぶことから始まり、それを自身の手で実体化する。",

				"そしてそれを相手の選んだ属性と衝突させ、勝敗を決めるのだ。",

				"単純だが、それでいて非常に奥が深い。",

			   "(この国の命運がこの手に・・・)",

			   "気が付けばつい先程まで女神を馬鹿にしていた自分はもういなくなっていた。",

			   "転移を実際にその身で味わってからか、今の状況に俺は少しずつ馴染み始めているのかもしれない。",

			   "自身の適応能力に驚愕しつつ、ふと右手を見るとそれが僅かに震えていることが分かった。",

			   "その震えは意識しても制御ができず、止まろうとはしてくれなかった。",

			   "「・・・多分まだ混乱しているみたいだけど、この世界は紛れもない現実、それは覚えといて」",

				"「・・・了解」",

				"「・・・じゃあ最後に簡単にこの国の現状を説明するわね」",

				"理解早くて助かるわぁ、と皮肉少女は話を続ける。",

				"「いい？この国は現在、スティン、シエーレ、ハーピア、セグア、そして最大の敵、レジーナによって支配され\nている。まあ、ざっくり言うとそいつらを倒してくれればあなたの使命はそこで果たされるわ」",

				"「そいつらの目的は？」",

				"「・・・さぁ？でも魔女が人間を支配するのに理由なんて要らないんじゃないかしら？手の届く範囲に丁度いい\n領土があったから自分の所有物にした、多分そんなところよ」",

				"何か説明が雑・・・とは思ったが少女の話は大体想像がつく。やったことあるＲＰＧゲームでもそういうのはあった。",

				"頷いてみせると少女は満足したかのように微笑み、まるでこの話は終わりとでも言うように話題を変えた。",

				 "「よし！じゃあ取り敢えずいつまでもここにいても仕方ないし、移動しながら話しましょう・・・あ、\nそういえば自己紹介がまだだったわ」",

				  "「私はフィナ、あなたは？」",


   "名前入力",


	"「 #name、悪くない名前ね」",


	"「そりゃどーも」",


	"「それじゃ改めて、行きましょうか・・・この国を救いに」",

"次のシーンへ"


	};




	std::string epilogueTextLog[140] = {


	"ついにここまで来た。",

	 "最後の戦いを前にして思いを馳せる。",

	"思い返せば決して楽な道ではなかった。",

	"目が覚めたら訳のわからないところにいて、突然「あなたは死にました」とか言われるし。\nその上勇者とかいう荷が重すぎる役目を背負わされるし。",

	"正直自分を抱きしめてやりたいほど、俺はよくやってると思う。",

		"(・・・はぁ)",

	"今の状況について流石に慣れはしたが、結局のところ理解は全くしていない。未だに意味不明だ。",

	"あれからどれくらい経ったのだろう。",

	"一月前のような気もするし、下手をすればもう半年くらい経過しているのかもしれない。",

	"とにかく俺はこの世界で生き延びることに只々必死だった。",

	"今迄だって別にこの国を救うために戦っていたわけではなく、単に身に降りかかる火の粉を払って\nきただけで、ここに辿り着いたのも成り行きだと思っている。",

	"(異世界転生って言ったら何というかもっとこう・・・・充実しているイメージがあったんだけどな)",

	"例えば俺には旅を共にする仲間がいない。ゲームだと最初は一人ぼっちだが、物語が進んでいくにつれて\n大抵は仲間が増えていく。俺にはそんな仲間がいないのだ。",

	"他には異能力も捨てがたい。女神から異能の力は授かっているものの、実際に戦いを経験して感じたのは\nもっと実践に向いた能力があったのではないか、ということ。",

	"『魔拳』は運に依拠している部分が大きい。自分が有利になるためにある程度の運を捻じ曲げることは出来るが、\nそれは絶対ではない。時には失敗もするし、不利な状況に陥ったことも何度かあった。",

	"故にこの能力については色々疑念を抱いているのだが、もしかすると他にまだ俺が知らない何かがあるのだろうか？",

	"・・・・いや、いくら考えたところで答えなど出て来ない。",

	"(これはあくまでも現実なんだ)",

	"折角異世界に来たというのに、今のところ楽しいことが一つもない。これは何かのバグか？",

	"「ふふ」",

	"そうして物思いにふけっていると、ふいに笑い声のようなものが聞こえた。",

	"俺は辺りを見渡し、やがて視界の端に一つの人影のようなものを確認する。",

	"「・・・よくぞここまで来た、我が思想に害をなそうとする下賤な人の子よ」",

	"？",

	"そう言いながら人影はこちらに向かって歩みを始める。",

	"コツコツコツ、と妙に規則正しいその足音はどこか薄気味悪い。",

	"また敵か・・・。",

	"もう毎度お馴染みのことではあるが、嫌なものはそれが例え何回目だろうと絶対に嫌なのである。",

	"やがて人影は眼前で歩みを止め-----------俺は言葉を失った。",

	"・・・・・・・美しい。",

	"腰まで伸びた長い髪、透き通るような大きな瞳、蜜のように甘い声。",

	"あっという間に俺は目の前の悪魔(？)から目を離すことが出来なくなっていた。",

	"もはやどう表現するのが正解なのか不明なほどの魅力を、俺は目の前の敵に感じてしまっていたのだ。",

	"しかしこれほどのオーラ、恐らく話に聞いていた『レジーナ』という最終目標で間違いないだろう。",

	"「あんたが『レジーナ』・・・だな？」",

	"「如何にも、我こそがこの帝国を支配する、レジーナその人である」",

	"「そうか・・・・随分余裕そうだな」",

	"別に自慢ではないが、一応俺も伊達に勇者をやってきたわけではない。数々の戦場を乗り越えその敵を屠ってきた。\nそれを知らないはずがないと思うのだが・・・",

	"するとレジーナは心の底から不思議そうに首をかしげ、答える。",

	"「逆に何を焦る必要があるのだ？まさか貴様は私を追い詰めたつもりにでもなっているのか？」",

		"「・・・・・・はぁー」",

		"心底呆れた、という感情が彼女のため息に乗って伝わってくる。明らかになめられているようだったが、\n俺はそれを不快に感じなかった。",

		"レジーナの言葉や仕草、更にはその冷徹な表情まで、あらゆる点に於いてその立ち振る舞いはまさしく\n王そのものだ。",

		"俺はそんな彼女に驚くほど夢中になっていた。それはもう怒りを覚えることすら忘れる程にだ。",

		"「問おう、貴様には今２つの選択肢がある」",

		"指を２本立て、それをこちら側へと向ける。",

		"「一つは我に忠誠を誓い、我の配下となるか」",

		"「一つは我に殺され、塵芥の如くここで朽ちて逝くか」",

		"「当然働きによっては褒美もくれてやるし、貴様には特別な席を用意してやってもいいと思っている。\nどうだ、もはや選ぶまでもなかろう？」",

		"・・・なるほど、悪い提案ではないと思った。",

		"今までこの理不尽な世界で散々自分の身を危険に晒して戦ってきた。",

		"勇者だとか言って持て囃され、今や俺が戦うのも勇者なんだから当然だと多くの人が思っている。",

		"しかし俺は元々はただの平凡な人間だ。ここまで来て確かに強くはなったが、心まで変化したわけではない。",

		"別に俺は人々の役に立ちたいとか、国を守りたいといったような立派な志など最初から持ち合わせては\nいなかったのだ。",

		"「・・・そうだな、選ぶまでもない」",

		"「であろう？ならば早速----」",

		"「断る」",

		"「契約の儀を・・・何？」",

		"「悪いがその申し出は断る」",

		"「・・・聞き間違いか？貴様、我の申し出を断る、そう言ったのか？」",

		"頷いてみせると、脱力したように天を見上げ、レジーナは再度深く息を吐いた。",

		"「・・・理解できん、貴様はそこまでの馬鹿だったのか？」",

		"「まぁ・・・馬鹿ってのは否定しないけどな。ただ、俺はあんたのその王者たる風格に惚れたんだ。\nだから俺もあんたの様に自由に生きたいと思った、それだけだ」",

		"「ほざけ・・・分かっているのか？今貴様がしようとしているのは自殺と何も変わらぬ、愚かな選択よ」",

		"「違うな、俺が選んだのは屈服でも降参でもない『第３の選択』だ」",

		"「第３の選択？」",

		"今迄勇者勇者と散々こき使われ続けて来てやったんだ、後はせいぜい俺のやりたいようにやらせてもらおう。",

		"「----俺がお前を支配してやる」",

		"「は？」",

		"まるで鳩が豆鉄砲を食ったような顔で彼女は静止した。",

		"「要は人々にとっての脅威を取り除いてやればいい。それだったら『支配』でも問題ない。そもそも\n『殺せ』と明確に依頼されたわけじゃないしな」",

		"「ふ、・・・ははっ！」",

		"初めて彼女が俺に笑顔を見せた。その笑顔が俺の支配欲に更に火を付ける。",

		"「・・・もうよい」",

		"先程までの笑顔が幻だったかのように彼女の表情が変わり、場の空気が変わった。瞬時に体制を整え\n右手を構える。",

		"「ならばやってみろ、矮小なる人間風情が！！」",

	"バトル開始",
	};
}


SceneConversation::SceneConversation() {

	_buttons_ptr = new DialogueButtons();

	ImageManager::GetInstance().SetBackGroundMapKey();
	ImageManager::GetInstance().SetCharacterMapKey();

}


//　各種機能----------------------------------------------------------------------------------------------------------

void SceneConversation::PrintDialogueText() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		for (int i = 0; i < 140; ++i) {

			_receiveText[i] = prologueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			_receiveText[_CURRENT_TEXTROW] = prologueTextLog[_CURRENT_TEXTROW].substr(0, _printTextSpeed);
		}
	}
	else {

		for (int i = 0; i < 140; ++i) {

			_receiveText[i] = epilogueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			_receiveText[_CURRENT_TEXTROW] = epilogueTextLog[_CURRENT_TEXTROW].substr(0, _printTextSpeed);
		}
	}

}


void SceneConversation::PrintNextByInput() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// エンターで文字送り
		if (prologueTextLog[_CURRENT_TEXTROW].length() > _printTextSpeed) {

			_printTextSpeed += _printTextSpeed_adjustRate;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (prologueTextLog[_CURRENT_TEXTROW].length() <= _printTextSpeed)) {

			_CURRENT_TEXTROW++;
			_printTextSpeed = 0;
		}
	}
	else {

		// エンターで文字送り
		if (epilogueTextLog[_CURRENT_TEXTROW].length() > _printTextSpeed) {

			_printTextSpeed += _printTextSpeed_adjustRate;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (epilogueTextLog[_CURRENT_TEXTROW].length() <= _printTextSpeed)) {

			_CURRENT_TEXTROW++;
			_printTextSpeed = 0;
		}
	}
}


void SceneConversation::Control_StoryLineStream() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// 背景画像---------------------------------------------------------------------

		if (_CURRENT_TEXTROW == 9)
			ImageManager::GetInstance().LoadBackGroundImage("プロローグ");

		if (_CURRENT_TEXTROW >= 9 && _CURRENT_TEXTROW < 68)
			ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		if (_CURRENT_TEXTROW == 71)
			ImageManager::GetInstance().LoadBackGroundImage("夜");

		if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW < 127)
			ImageManager::GetInstance().RenderBackGroundImage(500, 50, 1.0f, 1);

		// キャラクター画像-------------------------------------------------------------
		ShowPlayerImage_Prologue();
		ShowGoddessImage();
		ShowGirlImage();
		// ハイライト
		SetPlayersHighlight_Prologue();
		SetGoddessHighlight();
		SetGirlHighlight();
		// 名前入力
		//SetPlayersName();
	}
	else {

		if (_CURRENT_TEXTROW == 0) {
			ImageManager::GetInstance().LoadBackGroundImage("エピローグ");
		}

		ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		//　エピローグ
		ShowPlayerImage_Epilogue();
		SetPlayersHighlight_Epilogue();
		ShowFinalBossImage();
		SetFinalBossHighlight();
	}
}


void SceneConversation::StartFinalBossBattle()
{
	if (epilogueTextLog[_CURRENT_TEXTROW] == "バトル開始") {

		SceneStageMap ss;

		ss.ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::KINGDOM);
	}
}


void SceneConversation::MoveToStageMap()
{
	if (prologueTextLog[_CURRENT_TEXTROW] == "次のシーンへ") {

		_CURRENT_TEXTROW = 0;

		// ステージマップで表示するシンボルを初期化
		[](SymbolOfStageMap* ss) {

			ss = new SymbolOfStageMap();
			ss->InstantiateButton();
			delete ss;
			ss = nullptr;
			};

		// ボタンポインタ削除
		delete _buttons_ptr;
		_buttons_ptr = nullptr;

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneStageMap());
	}
}


void SceneConversation::SetPlayersName() {

	GetInputName_AtLast();

	SetDrawBright(200, 200, 200);

	SetActiveKeyInput(_inputName_hdl);

	// 入力モードを描画
	DrawKeyInputModeString(640, 480);

	// 入力途中の文字列を描画
	DrawKeyInputString(0, 0, _inputName_hdl);

	char buff[256];
	GetKeyInputString(buff, _inputName_hdl);
	_PLAYER_NAME = buff;

	DrawStringEx(100, 300, -1, "%s", _PLAYER_NAME.c_str());
}


void SceneConversation::GetInputName_AtLast() {

	if (prologueTextLog[_CURRENT_TEXTROW] == "名前入力") {
		prologueTextLog[_CURRENT_TEXTROW] = "名前を入力してください";
	}
}

//　ハイライト設定----------------------------------------------------------------------------------------------------------
void SceneConversation::SetPlayersHighlight_Prologue() {

	if (_CURRENT_TEXTROW == 9 || _CURRENT_TEXTROW == 12 || _CURRENT_TEXTROW == 16 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 ||
		_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 ||
		_CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 54 ||
		_CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 ||
		_CURRENT_TEXTROW == 71 || _CURRENT_TEXTROW == 76 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 88 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 107 || _CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 125) {

		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}


void SceneConversation::SetPlayersHighlight_Epilogue() {

	if (_CURRENT_TEXTROW == 5 || _CURRENT_TEXTROW == 11 || _CURRENT_TEXTROW == 17 || _CURRENT_TEXTROW == 23 ||
		_CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 56 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 70)
	{
		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}


void SceneConversation::SetGoddessHighlight() {

	if (_CURRENT_TEXTROW == 10 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 32 ||
		_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 37 || _CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 40 ||
		_CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45 || _CURRENT_TEXTROW == 46 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 66)
	{
		_isSetGoddessBright = true;
	}
	else {
		_isSetGoddessBright = false;
	}
}


void SceneConversation::SetGirlHighlight() {

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 87 ||
		_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 97 || _CURRENT_TEXTROW == 98 ||
		_CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 116 ||
		_CURRENT_TEXTROW == 118 || _CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 ||
		_CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 126)
	{
		_isSetGirlBright = true;
	}
	else {
		_isSetGirlBright = false;
	}
}


void SceneConversation::SetFinalBossHighlight() {

	if (_CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 40
		|| _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47
		|| _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 57
		|| _CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 63
		|| _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 71
		|| _CURRENT_TEXTROW == 73 || _CURRENT_TEXTROW == 75)
	{
		_isSetFinalBossBright = true;
	}
	else {
		_isSetFinalBossBright = false;
	}
}


//　描画----------------------------------------------------------------------------------------------------------
void SceneConversation::ShowPlayerImage_Prologue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW < 68) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW > 72) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
}


void SceneConversation::ShowPlayerImage_Epilogue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("立ち絵2＿プレイヤー");
	}
	if (_CURRENT_TEXTROW < 77) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "立ち絵2＿プレイヤー");
	}
}

void SceneConversation::ShowGirlImage() {


	if (_isSetGirlBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 71) {
		ImageManager::GetInstance().LoadCharacterImage("シルエット＿少女");
	}

	if (_CURRENT_TEXTROW > 71 && _CURRENT_TEXTROW <= 80) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "シルエット＿少女");
	}

	if (_CURRENT_TEXTROW == 81) {
		ImageManager::GetInstance().LoadCharacterImage("ノーマル＿少女");
	}

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 83 ||
		_CURRENT_TEXTROW == 84 || _CURRENT_TEXTROW == 87 || _CURRENT_TEXTROW == 88 || _CURRENT_TEXTROW == 97 ||
		_CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 115) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "ノーマル＿少女");
	}

	if (_CURRENT_TEXTROW == 85) {
		ImageManager::GetInstance().LoadCharacterImage("真剣＿少女");
	}

	if (_CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 113) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "真剣＿少女");
	}

	if (_CURRENT_TEXTROW == 93) {
		ImageManager::GetInstance().LoadCharacterImage("笑顔＿少女");
	}

	if (_CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 94 || _CURRENT_TEXTROW == 98 || _CURRENT_TEXTROW == 99 ||
		_CURRENT_TEXTROW == 100 || _CURRENT_TEXTROW == 101 || _CURRENT_TEXTROW == 102 ||
		_CURRENT_TEXTROW == 103 || _CURRENT_TEXTROW == 104 || _CURRENT_TEXTROW == 105 ||
		_CURRENT_TEXTROW == 106 || _CURRENT_TEXTROW == 107 || _CURRENT_TEXTROW == 108 ||
		_CURRENT_TEXTROW == 109 || _CURRENT_TEXTROW == 110 || _CURRENT_TEXTROW == 111 ||
		_CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 || _CURRENT_TEXTROW == 123 ||
		_CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 125 || _CURRENT_TEXTROW == 126) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "笑顔＿少女");
	}

	if (_CURRENT_TEXTROW == 89) {
		ImageManager::GetInstance().LoadCharacterImage("怒り2＿少女");
	}

	if (_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 90 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 92) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "怒り2＿少女");
	}

	if (_CURRENT_TEXTROW == 116) {
		ImageManager::GetInstance().LoadCharacterImage("怒り1＿少女");
	}

	if (_CURRENT_TEXTROW == 116 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 118 ||
		_CURRENT_TEXTROW == 119 || _CURRENT_TEXTROW == 120) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "怒り1＿少女");
	}
}


void SceneConversation::ShowGoddessImage() {

	if (_isSetGoddessBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {
		ImageManager::GetInstance().LoadCharacterImage("シルエット＿女神");
	}

	if (_CURRENT_TEXTROW < 20) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "シルエット＿女神");
	}
	else if (_CURRENT_TEXTROW >= 20) {

		if (_CURRENT_TEXTROW == 20) {
			ImageManager::GetInstance().LoadCharacterImage("ノーマル＿女神");
		}

		if (_CURRENT_TEXTROW == 20 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 || _CURRENT_TEXTROW == 23 ||
			_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 25 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 32 ||
			_CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 58 ||
			_CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 66 || _CURRENT_TEXTROW == 67) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "ノーマル＿女神");
		}

		if (_CURRENT_TEXTROW == 28) {
			ImageManager::GetInstance().LoadCharacterImage("真剣＿女神");
		}

		if (_CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 29 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 35 ||
			_CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47 || _CURRENT_TEXTROW == 48 ||
			_CURRENT_TEXTROW == 49 || _CURRENT_TEXTROW == 50 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 52 || _CURRENT_TEXTROW == 53 ||
			_CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 56 || _CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 61 ||
			_CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 63 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 65) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "真剣＿女神");
		}

		if (_CURRENT_TEXTROW == 33) {
			ImageManager::GetInstance().LoadCharacterImage("笑顔＿女神");
		}

		if (_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 37 ||
			_CURRENT_TEXTROW == 40 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "笑顔＿女神");
		}
	}
}


void SceneConversation::ShowFinalBossImage() {

	if (_isSetFinalBossBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 19) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿シルエット");
	}

	if (_CURRENT_TEXTROW >= 19 && _CURRENT_TEXTROW <= 34) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿シルエット");
	}

	if (_CURRENT_TEXTROW == 35) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW >= 35 && _CURRENT_TEXTROW <= 39) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW == 40) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿デフォルト");
	}

	if (_CURRENT_TEXTROW >= 40 && _CURRENT_TEXTROW <= 43) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿デフォルト");
	}

	if (_CURRENT_TEXTROW == 44) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW >= 44 && _CURRENT_TEXTROW <= 54) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW == 55) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿笑顔");
	}

	if (_CURRENT_TEXTROW >= 55 && _CURRENT_TEXTROW <= 56) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿笑顔");
	}

	if (_CURRENT_TEXTROW == 57) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿デフォルト");
	}

	if (_CURRENT_TEXTROW >= 57 && _CURRENT_TEXTROW <= 58) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿デフォルト");
	}

	if (_CURRENT_TEXTROW == 59) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW >= 59 && _CURRENT_TEXTROW <= 70) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW == 71) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_2");
	}

	if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW <= 72) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_2");
	}

	if (_CURRENT_TEXTROW == 73) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW >= 73 && _CURRENT_TEXTROW <= 74) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_1");
	}

	if (_CURRENT_TEXTROW == 75) {
		ImageManager::GetInstance().LoadCharacterImage("ステージ5＿ボス＿ダメージ_4");
	}

	if (_CURRENT_TEXTROW >= 75) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "ステージ5＿ボス＿ダメージ_4");
	}
}


void SceneConversation::Render(const float deltaTime) {

	SetDrawBright(255, 255, 255);

	SetFontSize(20);
	DrawBox(0, 500, 1280, 800, GetColor(20, 20, 20), true);

	// テキスト描画
	PrintDialogueText();
	SetFontSize(22);
	DrawString(90, 550, _receiveText[_CURRENT_TEXTROW].c_str(), -1);


	// ボタン描画
	_buttons_ptr->RenderDialogueButton();


	SetFontSize(35); // 右下に表示
	DrawString(1070, 620, "Enter", -1);
}


//　更新----------------------------------------------------------------------------------------------------------
void SceneConversation::Update(const float deltaTime) {

	MoveToStageMap();

	StartFinalBossBattle();

	Control_StoryLineStream();

	// ダイアログボタン-----------------------------------------
	_buttons_ptr->AutoDialogue();
	PrintNextByInput();
}

void SceneConversation::ReleaseMem() {

	DeleteGraph(_bg_hdl);
}
