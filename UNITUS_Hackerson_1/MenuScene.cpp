#include "MenuScene.h"
#include "Button.h"
#include "CharaButton.h"


MenuScene::MenuScene(GameModes* gameModes, BasicInput* input) :Scene(gameModes, input)
{
	init();
}


MenuScene::~MenuScene()
{
	for (int i = 0; i < BattonNumber; i++)
	{
		delete button[i];
	}
}
void MenuScene::init()
{
	//button[0] = new Button(input,Vector2(500, 130), Vector2(300, 400), "..\\Reversible!_1.0\\‘fÞ\\Hana.png");
	SetBackgroundColor(0, 0, 0);
	PlaySoundFile(".\\Resource\\BGM\\Frisky_Kitten.mp3", DX_PLAYTYPE_BACK);
	
}

void MenuScene::update()
{
	LoadGraphScreen(0, 0, ".\\Resource\\img\\Win7.png", FALSE);
	LoadGraphScreen(20, 500, ".\\Resource\\img\\logo.bmp", TRUE);
	
	//SetFontSize(50);
	//SetFontThickness(9);
	//DrawFormatString(600, 600, GetColor(255, 255, 0), "ƒŠƒA[–o–Å‘åìí");
	
	if ((input->clickInput & MOUSE_INPUT_LEFT) != 0){
		StopSoundFile();
		SetBackgroundColor(230, 230, 230);
		gameModes->sceneMode = 1;
	}
}