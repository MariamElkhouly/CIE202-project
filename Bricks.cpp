#pragma once
#include "Bricks.h"
#include "game.h"
#include "PowerDownCollectable.h"
#include "PowerUpCollectable.h"
#include "drawable.h"
////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

void brick::SetStrength(int a)
{
	Strength = a;
}

int brick::getStrength() const
{
	return Strength;
}

void brick::decreaseStrength(Ball& a)
{
	if (Strength > 0) {
		Strength -= 1;
		// Call the collision action for the specific brick type
		collisionAction();
	}
}




////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(2);
	imageName = "images\\bricks\\NormalBrick.jpg";
}

void normalBrick::collisionAction()
{
	if (getStrength() == 0)
	pGame->setScore(1);
}

void normalBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType normalBrick::getType() const
{
	return BRK_NRM;
}

////////////////////////////////////////////////////  class easyBrick  /////////////////////////////////
easyBrick::easyBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(1);
	imageName = "images\\bricks\\easy.jpg";
}

void easyBrick::collisionAction()
{
	if(getStrength()==0)
	pGame->setScore(1);
}

BrickType easyBrick::getType() const
{
	return BRK_EAS;
}

void easyBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a); // Call the base class method
}


////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(3);
	imageName = "images\\bricks\\hard.jpg";
}
void hardBrick::collisionAction()
{
	if (getStrength() == 0)
	pGame->setScore(1);
}

void hardBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType hardBrick::getType() const
{
	return BRK_HRD;
}

////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(4);
	imageName = "images\\bricks\\bomb.jpg";
}
void bombBrick::collisionAction()
{
	if (getStrength() == 0) {
		pGame->setScore(4);
	}
}

void bombBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType bombBrick::getType() const
{
	return BRK_BMB;
}

////////////////////////////////////////////////////  class shockwaveBrick  /////////////////////////////////
shockwaveBrick::shockwaveBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(5);
	imageName = "images\\bricks\\shockwave.jpg";
}
void shockwaveBrick::collisionAction()
{
	if (getStrength() == 0)
	pGame->setScore(5);
}

void shockwaveBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType shockwaveBrick::getType() const
{
	return BRK_SHK;
}

////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(500);
	imageName = "images\\bricks\\rock.jpg";
}
void rockBrick::collisionAction()
{
	if (getStrength() == 0)
		pGame->setScore(5);
	
}
void rockBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType rockBrick::getType() const
{
	return BRK_RCK;
}

////////////////////////////////////////////////////  class powerBrick  /////////////////////////////////
powerBrick::powerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(1);
	imageName = "images\\bricks\\power.jpg";
}
void powerBrick::collisionAction()
{

if (getStrength() == 0) {
}
launchCollectible();
}



void powerBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType powerBrick::getType() const
{
	return BRK_PWR;
}

void powerBrick::launchCollectible()
{
	srand(time(0));

	// Determine whether to launch a power-up or power-down
	int randomUpAndDown = rand() % 2;

	collectable* pCollectable=nullptr;

	if (randomUpAndDown == 0) {
		// Launch a PowerUp collectable
		PowerUpType powerUpType = static_cast<PowerUpType>(rand() % 7);
		switch (powerUpType) {
		case PowerUpType::WGlide:
			pCollectable = new WindGlide(uprLft,width,height,pGame);
			break;
		case PowerUpType::B:
			pCollectable = new Bonus(uprLft, width, height, pGame);
			break;
		case PowerUpType::Double:
			pCollectable = new DoubleScore(uprLft, width, height, pGame);
			break;
		case PowerUpType::Extra:
			pCollectable = new ExtraLives(uprLft, width, height, pGame);
			break;
		case PowerUpType::Mgnt:
			pCollectable = new Magnet(uprLft, width, height, pGame);
			break;
		case PowerUpType::Multi:
			pCollectable = new MultibleBalls(uprLft, width, height, pGame);
			break;
		case PowerUpType::Wide:
			pCollectable = new WidenPaddle(uprLft, width, height, pGame);
			break;
		}
	}
	else {
		// Launch a PowerDown collectable
		PowerDownType powerDownType = static_cast<PowerDownType>(rand() % 3);
		switch (powerDownType) {
		case PowerDownType::Narrow:
			pCollectable = new NarrowPaddle(uprLft, width, height, pGame); 
			break;
		case PowerDownType::Reverse:
			pCollectable = new ReverseDir(uprLft, width, height, pGame);
			break;
		case PowerDownType::Slow:
			pCollectable = new SlowPaddle(uprLft, width, height, pGame);
			break;
		}
		
	}

	// Set the vertical position randomly
	int randomVerticalPosition = 30+rand() % (pGame->getWind()->GetHeight()-30 + 1);
	pCollectable->setUpperLeftPoint(pCollectable->getUpperLeftPoint().x, randomVerticalPosition);

	// Set the velocity to move vertically downwards
	pCollectable->setVelocity(0, 5);

}
