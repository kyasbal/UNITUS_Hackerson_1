#pragma once
#include "Scene.h"
#define BattonNumber 1
class MenuScene :
	public Scene
{
public:
	MenuScene(GameModes* gameMode, BasicInput* input);
	~MenuScene();
	void init();
	void update();
private:
	Button* button[BattonNumber];
};

