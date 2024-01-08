#pragma once
#include "collidable.h"
class collectable :public collidable
{
protected:
	int m;
	bool start = false;
	game* pG1;
public:
	collectable(point ul, int w, int h, game* pG);
	virtual ~collectable();

};


