
#include "Button.h"
class ReaZyu :
	public Button
{
public:
	ReaZyu(BasicInput* input);
	~ReaZyu();
	void update();
	void afterDraw();
};
