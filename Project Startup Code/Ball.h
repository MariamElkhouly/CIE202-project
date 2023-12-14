#pragma once
#include "collidable.h"

class Ball :
    public collidable
{
private:
    image background;
    float diameter;
    bool collidingWithPaddle;
    point vel; //velocity vector
public:
    Ball(point center, int radius, game* r_pGame);
    void move();   
    point getVelocity() const;
    point getPosition() const;
    void setVelocity(float v_x, float v_y);
    void setPosition(float x, float y);
    void reflect(point collPoint, float angle);
    void draw() const override;
    void clearScreen() const;
    void collisionAction();
};

