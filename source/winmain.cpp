#include <DxLib.h>
#include"maingame.h"
#include"config.h"
#include"../laststg_source/laststg_object.h"

namespace {
	int scene = 0;
}

void LoadInit() {
	SetOutApplicationLogValidFlag(LOGSET_MODE);//ログの書き出し設定
	ChangeWindowMode(WINDOW_MODE);	//ウィンドウモードにする
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//ウィンドウサイズを設定する
	SetWindowSizeExtendRate(WINDOW_EXTEND);//ウィンドウ拡大率
	//SetWindowSizeChangeEnableFlag(TRUE);//途中大きさ変更あり
	SetWindowStyleMode(WINDOW_STYLE);//ウィンドウの最大化ボタンを機能させる。
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//SetUseIMEFlag(true);// ＩＭＥを使用するかどうかを設定する
	SetWindowText(WINDOW_NAME);

}

//プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadInit();
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

		
	//SetAlwaysRunFlag(TRUE);//ウィンドウがアクティブではない状態でも動く
	//SetUseZBuffer3D(TRUE);
	//SetWriteZBuffer3D(TRUE);
	MAINGAME* game=new MAINGAME();
	laststg_Init();
	//最初に１回呼ぶ
	game->Init();
	bool endflag = false;
	//メイン処理
	while (ProcessMessage() == 0 && !endflag) {
		clsDx();
		ClearDrawScreen();	//裏画面の描画を全て消去
		bool tkey = CheckHitKey(KEY_INPUT_ESCAPE);
		bool lkey = CheckHitKey(KEY_INPUT_L);
		 endflag = CheckHitKey(KEY_INPUT_ESCAPE)&& CheckHitKey(KEY_INPUT_LSHIFT);

		if (tkey)scene = 0;
		if (lkey)scene = 1;

		if (scene==0) {

		game->Update();
		game->Draw();
		}
		if (scene==1) {
			laststg_Update();
			laststg_Draw();
		}
		ScreenFlip();		//裏画面と表画面の入替
	}
	delete game;
	laststg_Delete();
	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
