#pragma once
#include "collidable.h"
class Paddle : public collidable

{
public:
	Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void MovePaddle();
	void erasepaddle();
	void setPosition(float x, float y);
	void collisionAction();

};

