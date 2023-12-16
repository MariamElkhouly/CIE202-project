#pragma once
#include "collidable.h"
class Paddle : public collidable

{
public:
	Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void MovePaddle();
	//void MovePaddle(int& xposition, int moveStep);
	void erasepaddle();
	void collisionAction();

};

