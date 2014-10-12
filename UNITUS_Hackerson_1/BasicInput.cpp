#include "BasicInput.h"


BasicInput::BasicInput()
{
	int x, y;
	GetMousePoint(&x, &y);
	mouseMove = Vector2(0, 0);
	mouse = Vector2(x, y);
	mouseWheelRotVol = GetMouseWheelRotVol();
	if (GetMouseInputLog(&mouseInput, &x, &y, TRUE) == -1)
	{
		mouseInput = 0;
	}
	clickedMouse = Vector2(x, y);
	GetHitKeyStateAll(Buf);
}


BasicInput::~BasicInput()
{
}

void BasicInput::update()
{
	int x, y;
	GetMousePoint(&x, &y);
	mouseMove = Vector2(x, y) - mouse;
	mouse = Vector2(x, y);
	mouseWheelRotVol = GetMouseWheelRotVol();
	mouseInput = GetMouseInput();
	int input;
	if (GetMouseInputLog(&input, &x, &y, TRUE) == -1)
		//クリックが検知されなかった場合
	{
		clickInput = 0;
	}
	else
		//クリックされた
	{
		clickInput = input;
		clickedMouse = Vector2(x, y);
	}
	GetHitKeyStateAll(Buf);
}