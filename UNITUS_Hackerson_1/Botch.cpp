#include "Botch.h"


Botch::Botch(BasicInput* input, Vector2 positon) :Button(input,positon,Vector2(50,50),".\\Resource\\img\\Botch.png")
{
	this->beginTime = GetNowCount();
}


Botch::~Botch()
{
}

void Botch::update()
{
	
}

void Botch::afterDraw()
{
	this->elapsedTime = GetNowCount()-this->beginTime;
	if (elapsedTime > 1000)
	{
		this->isVisible = false;
	}
	Vector2 pos = getPosition();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);
	DrawCircle(pos.x, pos.y, 100, GetColor(255, 255, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}