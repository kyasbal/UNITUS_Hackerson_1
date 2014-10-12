#include "MenuScene.h"


MenuScene::MenuScene(GameModes* gameModes ,BasicInput* input) :Scene(gameModes,input)
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
	button[0] = new Button(input,Vector2(500, 130), Vector2(300, 400), "..\\Reversible!_1.0\\‘fÞ\\Hana.png");
}
void MenuScene::update()
{
	
}