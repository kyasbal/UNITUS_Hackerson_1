#pragma once
#include "Scene.h"
#include "Woman.h"
#include "ReaZyu.h"
#include "Botch.h"
#include "Sweats.h"
#include "CharaButton.h"
#include "Button.h"
#include <list>
class GameScene :
	public Scene
{
public:
	GameScene(GameModes* gameMode, BasicInput* input);
	~GameScene();
	void init();
	void update();
	float time;
	float timeFromBegin;
	float beginTime;
private:
	long lastWomanSpawn = 0;
	std::list<DrawableBase*> Drawables;
	std::list<Botch> Botchs;
	std::list<Sweats> Sweats;
	std::list<CharaButton> CharaButtons;
	ReaZyu *reaZyu;
	void drawTimerString();
	int backgroundHandle;

};
