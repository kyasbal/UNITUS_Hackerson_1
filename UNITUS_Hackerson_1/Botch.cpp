#include "Botch.h"


Botch::Botch(BasicInput* input, Vector2 positon) :Button(input,positon,Vector2(50,50),".\\Resource\\img\\Botch.png")
{

}


Botch::~Botch()
{
}

void Botch::update()
{
}

void Botch::afterDraw()
{
	Vector2 pos = getPosition();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);
	DrawCircle(pos.x, pos.y, 100, GetColor(255, 255, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}