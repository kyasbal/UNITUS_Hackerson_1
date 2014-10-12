#include "GameScene.h"


GameScene::GameScene(GameModes* gameMode, BasicInput* input): Scene(gameMode, input)
{
	init();
}


GameScene::~GameScene()
{
	for (int i = 0; i < BattonNumber; i++)
	{
		delete button[i];
	}
}
void GameScene::init()
{
	button[0] = new Button(input, Vector2(500, 130), Vector2(300, 400),"..DxLibテンプレート\\素材\\devilHana.png");
}
void GameScene::update()
{
	
}