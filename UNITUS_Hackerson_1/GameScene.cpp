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
	ReaZyu *reaZyu = new ReaZyu(input, Vector2(375, 310));
	beginTime = GetNowCount();
}
void GameScene::update()
{
	//éûä‘ÇÃçXêV
	time = GetNowCount();
	timeFromBegin = beginTime - time;
	DrawBox(1000, 0, 1280, 720, GetColor(0, 255, 255), TRUE);
	DrawBox(0, 0, 1000, 720, GetColor(0, 0, 0), TRUE);
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->update();
	}
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->draw();
	}
}