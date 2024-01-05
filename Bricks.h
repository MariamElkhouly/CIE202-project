#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"
#include "Ball.h"

enum BrickType	//add more brick types
{
	BRK_EAS,//Easy Brick
	BRK_NRM,	//Normal Brick
	BRK_HRD,		//Hard Brick
	BRK_BMB, //bombbrick
	BRK_SHK, //shockwave brick
	BRK_RCK, //rock brick
	BRK_PWR //power brick
	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
	int Strength; //the strength of the brick 1 to 4
protected:
	int upScore; //the increase in score for each brick
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void SetStrength(int a); //reduces the strength of the bricks
	int getStrength() const;
	void decreaseStrength(Ball& a);
	virtual BrickType getType() const = 0;  
};

////////////////////////////////////////////////////  class easyBrick  /////////////////////////////////
class easyBrick :public brick
{
public:
	easyBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////

class bombBrick :public brick
{
public:
	bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class shockwaveBrick  /////////////////////////////////
class shockwaveBrick :public brick
{
public:
	shockwaveBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
class rockBrick :public brick
{
public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

////////////////////////////////////////////////////  class powerBrick  /////////////////////////////////
class powerBrick :public brick
{
public:
	powerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType getType() const override;
};

