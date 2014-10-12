#pragma once
#include "BasicInput.h"
#include "GameModes.h"
#include "Button.h"

class Scene
{
public:
	Scene(GameModes* sceneMode, BasicInput* input);
	virtual ~Scene();
	virtual void init();
	virtual void update();
	GameModes* gameModes;
	BasicInput* input;
};

