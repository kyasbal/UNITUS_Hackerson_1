#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280,720, 32);
	SetBackgroundColor(230, 230, 230);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);

		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}