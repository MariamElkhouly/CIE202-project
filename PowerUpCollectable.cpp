#include "PowerUpCollectable.h"

PowerUpCollectable::PowerUpCollectable(point ul, int w, int h, game* pG) : collectable(ul, w, h, pG)
{
	setType(Up);
}

PowerUpCollectable::~PowerUpCollectable()
{
}

////////// WindGlide class ////////////
WindGlide::WindGlide(point ul1, int w1, int h1, game* pG1) :PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\wind.jpg";
}

void WindGlide::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType WindGlide::getType() const
{
	return  WGlide;
}


////////// Bonus class ////////////

Bonus::Bonus(point ul1, int w1, int h1, game* pG1): PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\bonus.jpg";
}

void Bonus::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType Bonus::getType() const
{
	return B;
}



////////// ExtraLives class ////////////

ExtraLives::ExtraLives(point ul1, int w1, int h1, game* pG1) :PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\extra.jpg";
}

void ExtraLives::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType ExtraLives::getType() const
{
	return Extra;
}

/////////// DoubleScore class ////////

DoubleScore::DoubleScore(point ul1, int w1, int h1, game* pG1):PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\double.jpg";
}

void DoubleScore::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType DoubleScore::getType() const
{
	return Double;
}

/////////////  Magmet Class ////////////////////
Magnet::Magnet(point ul1, int w1, int h1, game* pG1) :PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\magnet.jpg";
}


void Magnet::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType Magnet::getType() const
{
	return Mgnt;
}


//////////// WidenPaddle Class //////////

WidenPaddle::WidenPaddle(point ul1, int w1, int h1, game* pG1):PowerUpCollectable (ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\wide.jpg";
}

void WidenPaddle::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType WidenPaddle::getType() const
{
	return Wide;
}

/////////// MultibleBalls class ////////////

MultibleBalls::MultibleBalls(point ul1, int w1, int h1, game* pG1):PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\multible.jpg";
}

void MultibleBalls::collisionAction()
{
	if (collidable::collisionCheck(*this, *pPaddle)) {

	}
}

PowerUpType MultibleBalls::getType() const
{
	return Multi;
}



