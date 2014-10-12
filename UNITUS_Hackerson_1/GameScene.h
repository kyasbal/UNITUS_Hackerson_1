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
private:
	std::list<DrawableBase*> Drawables;
	std::list<Woman> Womans;
	std::list<Botch> Botchs;
	std::list<Sweats> Sweats;
	std::list<CharaButton> CharaButtons;
	ReaZyu *reaZyu;
	
};
