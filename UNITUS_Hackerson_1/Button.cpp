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
{}

void Button::update()
{}

Vector2 Button::getPosition()
{
	return (this->Bottom + this->Top)*0.5f;
}