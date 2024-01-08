#pragma once
#include "collectable.h"
#include "Paddle.h"
#include "Ball.h"
enum PowerUpType {
	WGlide,//wind glide
	B, //bonus
	Extra, //extra lives
	Double, //double score
	Mgnt, //magnet
	Wide, //widen the paddle
	Multi //multible balls
};
class PowerUpCollectable :public collectable
{

protected:
	Paddle* pPaddle;
	Ball* pBall;

public:
	PowerUpCollectable(point ul, int w, int h, game* pG);
	virtual ~PowerUpCollectable();
	virtual PowerUpType getType() const = 0;
};

class WindGlide :public PowerUpCollectable {
public:
	WindGlide(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

class Bonus :public PowerUpCollectable {
public:
	Bonus(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;

};

class ExtraLives :public PowerUpCollectable {
public:
	ExtraLives(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

class DoubleScore :public PowerUpCollectable {
public:
	DoubleScore(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

class Magnet :public PowerUpCollectable {
public:
	Magnet(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

class WidenPaddle :public PowerUpCollectable {
public:
	WidenPaddle(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

class MultibleBalls :public PowerUpCollectable {
public:
	MultibleBalls(point ul1, int w1, int h1, game* pG1);
	void collisionAction();
	PowerUpType getType() const override;
};

