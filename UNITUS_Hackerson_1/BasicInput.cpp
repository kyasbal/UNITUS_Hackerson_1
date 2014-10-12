#include "BasicInput.h"


BasicInput::BasicInput()
{
	update();
}


BasicInput::~BasicInput()
{
}

void BasicInput::update()
{
	int x, y;
	GetMousePoint(&x, &y);
	Mouse = Vector2(x, y);
	mouseWheelRotVol = GetMouseWheelRotVol();
	if (GetMouseInputLog(&mouseInput, &x, &y, TRUE) == -1)
	{
		mouseInput = 0;
	}
	MouseClick = Vector2(x, y);
	GetHitKeyStateAll(Buf);
}