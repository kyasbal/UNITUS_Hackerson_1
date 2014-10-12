
#include "Button.h"
class ReaZyu :
	public Button
{
public:
	ReaZyu(BasicInput* input, Vector2 positon);
	~ReaZyu();
	void update();
	void afterDraw();
};
