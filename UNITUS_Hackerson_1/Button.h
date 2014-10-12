#pragma once
#include "DxLib.h"
#include "tchar.h"
#include "BasicInput.h"
#include "Vector2.cpp"
#include "DrawableBase.h"
class Button : DrawableBase
{
public:
	Button(BasicInput* input, Vector2 positon, Vector2 graphPx, TCHAR* GraphName);
	~Button();
	void draw();
	void update();
	Vector2 Top;
	Vector2 Botom;
	TCHAR* GraphName;
	BasicInput* input;
};
