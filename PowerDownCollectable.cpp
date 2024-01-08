#include "PowerDownCollectable.h"

PowerDownCollectable::PowerDownCollectable(point ul, int w, int h, game* pG) :collectable(ul,w,h,pG)
{
	setType(Down);
}

PowerDownCollectable::~PowerDownCollectable()
{
}

/////////////////  NarrowPaddle class //////////////////////////
NarrowPaddle::NarrowPaddle(point ul1, int w1, int h1, game* pG1):PowerDownCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\narrow.jpg";
}

void NarrowPaddle::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerDownType NarrowPaddle::getType() const
{
	return Narrow;
}

/////////////// ReverseDir class /////////////
ReverseDir::ReverseDir(point ul1, int w1, int h1, game* pG1) :PowerDownCollectable(ul1, w1, h1, pG1)
{
	imageName = "images\\collectables\\rev.jpg";
}

void ReverseDir::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerDownType ReverseDir::getType() const
{
	return Reverse;
}


/////////////// SlowPaddle class //////////////
SlowPaddle::SlowPaddle(point ul1, int w1, int h1, game* pG1) :PowerDownCollectable(ul1, w1, h1, pG1)
{
	imageName = "images\\collectables\\slow.jpg";
}

void SlowPaddle::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerDownType SlowPaddle::getType() const
{
	return Reverse;
}