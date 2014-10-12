#pragma once
#include <list>
#include "Button.h"
#include "Botch.h"
#include "GameModes.h"
class Woman :
	public Button
{
public:
	Woman(GameModes* gamemodes,BasicInput* input, Vector2 position, std::list<Botch> *botchs);
	~Woman();
	void update();
	void afterDraw();
private:
	GameModes* gamemodes;
	long beginTime;
	long elapsedTime;
	std::list<Botch>* botches;
};