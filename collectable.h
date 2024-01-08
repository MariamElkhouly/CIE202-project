#pragma once
#include "collidable.h"
class collectable :public collidable
{
public:
	collectable(point ul, int w, int h, game* pG);
	virtual ~collectable();

};


