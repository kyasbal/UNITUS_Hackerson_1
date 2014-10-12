#pragma once
#include "DxLib.h"
#include "tchar.h"
#include "BasicInput.h"
#include "Vector2.cpp"
#include "DrawableBase.h"
class Button :public DrawableBase
{
public:
	Button(BasicInput* input, Vector2 positon, Vector2 graphPx, TCHAR* GraphName);
	~Button();
	virtual void draw();
	virtual void update();
	Vector2 Top;
	Vector2 Bottom;
	TCHAR* GraphName;
	BasicInput* input;
protected:
	Vector2 getPosition();
};

