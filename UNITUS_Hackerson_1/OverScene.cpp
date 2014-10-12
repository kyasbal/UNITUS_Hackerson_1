#include "OverScene.h"


OverScene::OverScene(GameModes* gameModes, BasicInput* input) :Scene(gameModes, input)
{
}


OverScene::~OverScene()
{
}

void OverScene::init()
{
	//button[0] = new Button(input,Vector2(500, 130), Vector2(300, 400), "..\\Reversible!_1.0\\‘fÞ\\Hana.png");
	SetBackgroundColor(0, 0, 0);
	LoadGraphScreen(0, 0, ".\\Resource\\img\\Iwanna.jpg", FALSE);

}

void OverScene::update()
{
	if ((input->clickInput & MOUSE_INPUT_LEFT) != 0){
		//StopSoundFile();
		SetBackgroundColor(230, 230, 230);
		gameModes->sceneMode = 0;
	}
}