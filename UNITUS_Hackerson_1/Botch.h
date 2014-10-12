#pragma once
#include "Button.h"
class Botch :public Button
{
public:
	Botch(BasicInput* input, Vector2 positon);
	~Botch();
	void update();
	void afterDraw();
};

