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
		//�N���b�N�����m����Ȃ������ꍇ
	{
		clickInput = 0;
	}
	else
		//�N���b�N���ꂽ
	{
		clickInput = input;
		clickedMouse = Vector2(x, y);
	}
	GetHitKeyStateAll(Buf);
}