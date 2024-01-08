#pragma once
#include "collectable.h"
#include "Paddle.h"
<<<<<<< HEAD
#include"game.h"
=======
#include "game.h"
>>>>>>> master
enum PowerDownType {
	Narrow,
	Reverse,
	Slow
};

class PowerDownCollectable:public collectable
{
protected:
	Paddle* pPaddle;
public:
	PowerDownCollectable(point ul, int w, int h, game* pG);
	virtual ~PowerDownCollectable();
	virtual PowerDownType getType() const = 0;

};

class NarrowPaddle :public PowerDownCollectable
{
public:
	NarrowPaddle(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerDownType getType() const override;
};

class ReverseDir :public PowerDownCollectable
{
public:
	ReverseDir(point ul1, int w1, int h1, game* pG1); 
	void collisionAction();
	PowerDownType getType() const override;

};

class SlowPaddle :public PowerDownCollectable
{
public:
	SlowPaddle(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerDownType getType() const override;
};


