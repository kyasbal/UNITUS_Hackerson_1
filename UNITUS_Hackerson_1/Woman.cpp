#include "Woman.h"
#include <list>
Woman::Woman(BasicInput* input, Vector2 position,std::list<Botch>* botchs) :Button(input, position, Vector2(50, 50), ".\\Resource\\img\\Woman.png")
{
	this->botches = botchs;
	beginTime = GetNowCount();
}


Woman::~Woman()
{
	
}

void Woman::update()
{
	elapsedTime = GetNowCount() - beginTime;
	if (elapsedTime > 5000)
	{
		this->isVisible = false;
	}
	if (!isVisible)return;
	Vector2 target = Vector2(500,335);
	target -= this->getPosition();
	if (target.length() < 1)
	{
		//TODO �Q�[���I�[�o�[����
	}
	target *= (1.0/target.length());
	Vector2 newPos = this->getPosition() - target;
	for (std::list<Botch>::iterator itr = this->botches->begin(); itr != this->botches->end(); itr++)
	{
		Botch b = *itr;
		if (!b.isVisible)continue;
		Vector2 dist =  b.getPosition()-newPos;
		if (dist.length() < 100)
		{
			Vector2 newDist = Vector2(-dist.y, dist.x);
			newPos = this->getPosition() - newDist;
		}
	}
	this->setPosition(newPos);
	
}

void Woman::afterDraw()
{}