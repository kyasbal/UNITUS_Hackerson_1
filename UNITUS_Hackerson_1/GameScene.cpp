#include "GameScene.h"


GameScene::GameScene(GameModes* gameMode, BasicInput* input) : Scene(gameMode, input)
{
	init();
}


GameScene::~GameScene()
{

}
void GameScene::init()
{
	ReaZyu *reaZyu = new ReaZyu(input);
	this->Drawables.push_back(reaZyu);
	beginTime = GetNowCount();
	backgroundHandle = LoadGraph(".\\Resource\\img\\BackGround.png");
	this->Drawables.push_back(new Botch(input, Vector2(100, 100)));
	this->Drawables.push_back(new Woman(gameModes,input, Vector2(500, 200), &this->Botchs));
}
void GameScene::update()
{
	//時間の更新
	time = GetNowCount();
	timeFromBegin = time - beginTime;
	DrawExtendGraph(0, 0, 1000, 720, backgroundHandle, TRUE);
	//Drawablesの描画
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		if (!(*itr)->isVisible)continue;
		(*itr)->update();
	}
	for (std::list<DrawableBase*>::iterator itr = this->Drawables.begin(); itr != this->Drawables.end(); itr++)
	{
		if (!(*itr)->isVisible)continue;
		(*itr)->draw();
	}
	DrawBox(1000, 0, 1280, 720, GetColor(200, 200, 200), TRUE);
	//Timerの描画
	drawTimerString();
	//Botch生成
	if (input->clickInput &  MOUSE_INPUT_LEFT != 0)
	{
		Botch *botch = new Botch(input, input->mouse);
		Botchs.push_back(*botch);
		Drawables.push_back(botch);
	}
	//Womanの生成\
	{
		if (GetNowCount() - lastWomanSpawn > 1000)
		{
			float timefromBegin = this->timeFromBegin;
			timefromBegin /= 1000;
			int m = (int)timefromBegin / 60;
			timefromBegin -= m * 60;
			int s = (int)timefromBegin;
			Woman *woman = new Woman(gameModes,input, Vector2(475 + 500 * cos(s), 310 + 500 * sin(s)), &Botchs);
			{
				Drawables.push_back(woman);
			}
			lastWomanSpawn = GetNowCount();
		}
	}



void GameScene::drawTimerString(){
	float timefromBegin = this->timeFromBegin;
	timefromBegin /= 1000;
	int m = (int)timefromBegin / 60;
	timefromBegin -= m * 60;
	int s = (int)timefromBegin;
	SetFontSize(30);
	DrawFormatString(800, 680, GetColor(0, 255, 0), "%d:%d", m, s);
}

