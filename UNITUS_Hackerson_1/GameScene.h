
#include "Scene.h"
#define BattonNumber 1
class GameScene :
	public Scene
{
public:
	GameScene(GameModes* gameMode, BasicInput* input);
	~GameScene();
	void init();
	void update();
private:
	Button* button[BattonNumber];

};
