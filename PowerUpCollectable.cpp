#include "PowerUpCollectable.h"
#include"Paddle.h" 
#include"game.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include<windows.h> 
#include "CMUgraphicsLib/CMUgraphics.h" 
PowerUpCollectable::PowerUpCollectable(point ul, int w, int h, game* pG) : collectable(ul, w, h, pG)
{
<<<<<<< HEAD

=======
	setType(Up);
>>>>>>> master
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
	game* pG1; 
	if (collidable::collisionCheck(*this, *pPaddle)) {
		//pG1->resetTimer();
		if (!start)
		{
			m = pG1->getTimerMinutes();
			start = true;
		}
		
		if(pG1->getTimerMinutes() <= 2 + m){
	
			pPaddle->MovePaddleup();
		}
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
		if (!start)
		{
			m = pG1->getTimerMinutes();
			start = true;
		}

		if (pG1->getTimerMinutes() <= 2 + m) {

			pG1->setLives( pG1->getLives()+1);
		}

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
		if (!start)
		{
			m = pG1->getTimerMinutes();
			start = true;
		}

		if (pG1->getTimerMinutes() <= 2 + m) {

			pG1->setScore(2 * pG1->getScore());
		}

	}
}

PowerUpType DoubleScore::getType() const
{
	return Double;
}

/////////////  Magnet Class ////////////////////
Magnet::Magnet(point ul1, int w1, int h1, game* pG1) :PowerUpCollectable(ul1,w1,h1,pG1)
{
	imageName = "images\\collectables\\magnet.jpg";
}


void Magnet::collisionAction()
{
	bool isSpacePressed = false;
	char cKeyData;
	window* pWind;
	game* pMag;
	if (collidable::collisionCheck(*this, *pPaddle)) {
		if (!start)
		{
			m = pMag->getTimerMinutes(); 
			start = true;
		}
		if (pMag->getTimerMinutes() >= 2 + m && isSpacePressed)
		{
			pBall->setVelocity(0, -10);
		}
		else
		{
			pBall->setPosition(config.ballx, config.bally);
			pBall->setVelocity(0, 0);
		}
		keytype  ktInput = pWind->GetKeyPress(cKeyData);
		if (ktInput == ASCII && cKeyData == ' ')
		{
			isSpacePressed = true;
		} 
		
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
		if (!start)
		{
			m = pG1->getTimerMinutes();
			start = true;
		}

		if (pG1->getTimerMinutes() <= 1 + m) {

			config.paddlew = 400;
		}
		

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



