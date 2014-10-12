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
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	BasicInput *input = new BasicInput();
	GameModes *gameModes = new GameModes();
	Scene *scene[SceneNumber];
	scene[0] = new MenuScene(gameModes, input);
	scene[1] = new GameScene(gameModes, input);
	scene[2] = new OverScene(gameModes, input);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();
		// �`����ʂ𗠂ɂ���
		SetDrawScreen(DX_SCREEN_BACK);

		input->update();
		scene[gameModes->sceneMode]->update();

		// ����ʂ̓��e��\��ʂɔ��f���܂�
		ScreenFlip();
	}
	delete input;
	delete gameModes;
	for (int i = 0; i < SceneNumber; i++)
	{
		delete scene[i];
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}