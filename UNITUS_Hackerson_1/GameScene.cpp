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
	//ŠÔ‚ÌXV
	time = GetNowCount();
	timeFromBegin = time - beginTime;
	//•”ˆÊ‚²‚Æ‚Ì”wŒiF‚Ì•`‰æ
	DrawBox(1000, 0, 1280, 720, GetColor(0, 255, 255), TRUE);
	DrawBox(0, 0, 1000, 720, GetColor(0, 0, 0), TRUE);
	//Drawables‚Ì•`‰æ
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->update();
	}
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->draw();
	}
	//Timer‚Ì•`‰æ
	drawTimerString();
}

void GameScene::drawTimerString(){
	float timefromBegin = this->timeFromBegin;
	timefromBegin /= 1000;
	int m=(int)timefromBegin / 60;
	timefromBegin -= m * 60;
	int s =(int) timefromBegin;
	DrawFormatString(800, 700, GetColor(0, 255, 0), "%d:%d", m, s);
}

