#include "Bricks.h"
#include "game.h"

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
		Strength -= a.getStrength();
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
}

void powerBrick::decreaseStrength(Ball& a)
{
	brick::decreaseStrength(a);
}

BrickType powerBrick::getType() const
{
	return BRK_PWR;
}
