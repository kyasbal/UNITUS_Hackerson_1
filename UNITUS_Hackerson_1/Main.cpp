#include "DxLib.h"
#include "BasicInput.h"
#include "GameModes.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "OverScene.h"
#define SceneNumber 3

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);
	SetMainWindowText("DxLib");
	SetBackgroundColor(230, 230, 230);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	BasicInput *input = new BasicInput();
	GameModes *gameModes = new GameModes();
	Scene *scene[SceneNumber];
	scene[0] = new MenuScene(gameModes, input);
	scene[1] = new GameScene(gameModes, input);
	scene[2] = new OverScene(gameModes, input);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);

		input->update();
		scene[gameModes->sceneMode]->update();

		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}
	delete input;
	delete gameModes;
	for (int i = 0; i < SceneNumber; i++)
	{
		delete scene[i];
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}