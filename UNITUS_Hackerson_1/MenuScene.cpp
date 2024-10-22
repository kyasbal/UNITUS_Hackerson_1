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
	//button[0] = new Button(input,Vector2(500, 130), Vector2(300, 400), "..\\Reversible!_1.0\\素材\\Hana.png");
	SetBackgroundColor(0, 0, 0);
	
	
}

void MenuScene::update()
{
	LoadGraphScreen(0, 0, ".\\Resource\\img\\Win7.png", FALSE);
	LoadGraphScreen(20, 500, ".\\Resource\\img\\logo.bmp", TRUE);
	if (CheckSoundFile()==0){
		PlaySoundFile(".\\Resource\\BGM\\湖のほとりで風を感じる的なBGM.mp3", DX_PLAYTYPE_LOOP);
	}
	//SetFontSize(50);
	//SetFontThickness(9);
	//DrawFormatString(600, 600, GetColor(255, 255, 0), "リア充撲滅大作戦");
	
	if ((input->clickInput & MOUSE_INPUT_LEFT) != 0){
		//StopSoundFile();
		SetBackgroundColor(230, 230, 230);
		gameModes->sceneMode = 1;
	}
}