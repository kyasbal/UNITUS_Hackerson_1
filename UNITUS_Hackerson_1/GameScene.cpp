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
	this->Drawables.push_back(reaZyu);
	beginTime = GetNowCount();
	backgroundHandle = LoadGraph(".\\Resource\\img\\BackGround.png");
	this->Drawables.push_back(new Botch(input, Vector2(100, 100)));
}
void GameScene::update()
{
	//時間の更新
	time = GetNowCount();
	timeFromBegin = time - beginTime;
	//部位ごとの背景色の描画
	DrawBox(1000, 0, 1280, 720, GetColor(200,200,200), TRUE);
	DrawExtendGraph(0, 0, 1000, 720, backgroundHandle, TRUE);
	//Drawablesの描画
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->update();
	}
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		(*itr)->draw();
	}
	//Timerの描画
	drawTimerString();
}

void GameScene::drawTimerString(){
	float timefromBegin = this->timeFromBegin;
	timefromBegin /= 1000;
	int m=(int)timefromBegin / 60;
	timefromBegin -= m * 60;
	int s =(int) timefromBegin;
	SetFontSize(30);
	DrawFormatString(800, 680, GetColor(0, 255, 0), "%d:%d", m, s);
}

