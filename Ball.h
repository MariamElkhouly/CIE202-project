#pragma once
#include "collidable.h"
#include "gameConfig.h"
#include "Paddle.h"
class brick;
class Ball :
    public collidable
{
private:
    image background;
    float diameter;
    bool collidedWithPaddle = false;
    void checkEdges();

public:
    Ball(point center, int radius, game* r_pGame);
    void move();
    point getVelocity() const;
    point getPosition() const;
    void setVelocity(float v_x, float v_y);
    void setPosition(float x, float y);
    void reflectOffPaddle(Paddle& paddle);
    void reflectOffBrick(brick& brk);
    void draw() const override;
    void clearScreen() const;
    void collisionAction();
    void eraseball();
};

