#pragma once
#include <list>
#include "Button.h"
#include "Botch.h"
class Woman :
	public Button
{
public:
	Woman(BasicInput* input, Vector2 position, std::list<Botch> *botchs);
	~Woman();
	void update();
	void afterDraw();
private:
	std::list<Botch>* botches;
};