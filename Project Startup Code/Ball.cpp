#include "Ball.h"
#include "game.h"

Ball::Ball(point center, int r_diameter, game* r_pGame) : 
    collidable(center, r_diameter, r_diameter, r_pGame), diameter(r_diameter)
{
    setImageName("images\\Circle.jpg");
    vel.x = 0;
    vel.y = 0;
}

void Ball::clearScreen() const{
    window* pWind = pGame->getWind();
    pWind->DrawImage( "images\\EmptySquare.jpg", uprLft.x, uprLft.y, width, height);
}

void Ball::move()
{
    clearScreen();
    uprLft.x += vel.x;
    uprLft.y += vel.y;
}

point Ball::getVelocity() const
{
    return vel;
}

point Ball::getPosition() const
{
    return uprLft;
}

void Ball::setVelocity(float v_x, float v_y)
{
    vel.x = v_x;
    vel.y = v_y;
}

void Ball::setPosition(float x, float y)
{
    uprLft.x = x;
    uprLft.y = y;
}

void Ball::reflect(point collPoint,float angle = 45)
{
    point displacement, center = getCenter();
    displacement.x = center.x - collPoint.x;
    displacement.y = center.y - collPoint.y;

    if (abs(displacement.x) > abs(displacement.y)) {
        vel.x *= -1;
    }
    else {
        vel.y *= -1;
    }
}

void Ball::draw() const
{
    window* pWind = pGame->getWind();
    pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}

void Ball::collisionAction()
{
    vel.x = 0;
    vel.y = 0;
    /*
    TODO:
    - check if the collision happens with the paddle
    */
}


