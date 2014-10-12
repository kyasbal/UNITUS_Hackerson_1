#include "GameScene.h"


GameScene::GameScene(GameModes* gameMode, BasicInput* input): Scene(gameMode, input)
{
	init();
}


GameScene::~GameScene()
{
	
}
void GameScene::init()
{
   reaZyu = new ReaZyu(input,Vector2(375,310));
}
void GameScene::update()
{
	reaZyu->draw();
}