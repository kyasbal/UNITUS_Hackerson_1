#pragma once
class DrawableBase
{
public:
	DrawableBase();
	~DrawableBase();
	virtual void draw();
	virtual void update();
	int layer;
};

