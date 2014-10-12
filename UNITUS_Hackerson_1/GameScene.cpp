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
	ReaZyu *reaZyu = new ReaZyu(input,Vector2(375,310));
}
void GameScene::update()
{
	
}