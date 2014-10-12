
#include "Button.h"
class Woman :
	public Button
{
public:
	Woman(BasicInput* input, Vector2 position);
	~Woman();
	void update();
	void afterDraw();
};