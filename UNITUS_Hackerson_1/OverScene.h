#pragma once
#include "Scene.h"
class OverScene :
	public Scene
{
public:
	OverScene(GameModes* gameMode, BasicInput* input);
	~OverScene();
	void init();
	void update();
};

