#include "Button.h"



Button::Button(BasicInput* input, Vector2 position, Vector2 graphPx, TCHAR* GraphName)
{
	this->input = input;
	this->Top = position;
	this->Bottom = position + graphPx;
	this->GraphName = GraphName;
}

Button::~Button()
{
}

void Button::draw()
{
	LoadGraphScreen(Top.x,Top.y, GraphName, TRUE);
	afterDraw();
}

void Button::update()
{}
void Button::afterDraw()
{}
