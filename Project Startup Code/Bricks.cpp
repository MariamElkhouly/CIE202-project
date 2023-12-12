#include "Bricks.h"


////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

void brick::SetStrength(int a)
{
	Strength = a;
}

void brick::Disappear()
{
	if (Strength == 0)
	{

	}
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(2);
	imageName = "images\\bricks\\NormalBrick.jpg";
}

void normalBrick::collisionAction()
{
	//TODO: Add collision action logic
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
}

////////////////////////////////////////////////////  class shockwaveBrick  /////////////////////////////////
shockwaveBrick::shockwaveBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	SetStrength(4);
	imageName = "images\\bricks\\shockwave.jpg";
}
void shockwaveBrick::collisionAction()
{
}