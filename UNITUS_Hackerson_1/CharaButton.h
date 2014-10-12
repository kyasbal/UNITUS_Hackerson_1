#pragma once
#include "Button.h"

class CharaButton :
	public Button
{
public:
	CharaButton(BasicInput* input, Vector2 position, Vector2 graphPx, TCHAR* GraphName);
	~CharaButton();
	void draw();
	void draw(TCHAR* str);
	void update();
	Vector2 Top;
	Vector2 Botom;
	TCHAR* GraphName;
	BasicInput* input;
};

