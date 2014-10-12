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
}
void GameScene::update()
{
	//時間の更新
	time = GetNowCount();
	timeFromBegin = time - beginTime;
	//部位ごとの背景色の描画
	DrawBox(1000, 0, 1280, 720, GetColor(200, 200, 200), TRUE);
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
	//Botch生成
	if (input->clickInput &  MOUSE_INPUT_LEFT != 0)
	{
		Botch *botch = new Botch(input, input->mouse);
		Botchs.push_back(*botch);
		Drawables.push_back(botch);
	}
	//Womanの生成
	{
		float timefromBegin = this->timeFromBegin;
		timefromBegin /= 1000;
		int m = (int)timefromBegin / 60;
		timefromBegin -= m * 60;
		int s = (int)timefromBegin;
		Woman *woman = new Woman(input, Vector2(475+ 100 * cos(s), 310 + 100 * sin(s)));
		Womans.push_back(*woman);
		Drawables.push_back(woman);
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

