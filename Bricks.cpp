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
	if (collisionCheck(*this, a)) {
		Strength -= 1;
		if (Strength <= 0) {
			// Notify the grid to delete this brick
			// I don't know how
		}
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
	pGame->setScore(1);
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
	pGame->setScore(1);
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
	pGame->setScore(1);
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
	pGame->setScore(4);
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
	pGame->setScore(5);
}