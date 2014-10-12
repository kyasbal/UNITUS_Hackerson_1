#include "CharaButton.h"


CharaButton::CharaButton(BasicInput* input, Vector2 position, Vector2 graphPx, TCHAR* GraphName) :Button(input,position,graphPx,GraphName)
{
}


CharaButton::~CharaButton()
{
}

void CharaButton::afterDraw()
{	
	DrawFormatString((int)Top.x, (int)Top.y, GetColor(255, 255, 0), GraphName);
}

void CharaButton::afterDraw(TCHAR* str)
{
	DrawFormatString((int)Top.x, (int)Top.y, GetColor(255, 255, 0), str);
}

void CharaButton::update()
{

}
