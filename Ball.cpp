#include "Ball.h"
#include "game.h"

Ball::Ball(point center, int r_diameter, game* r_pGame) :
    collidable(center, r_diameter, r_diameter, r_pGame), diameter(r_diameter)
{
    setImageName("images\\Circle.jpg");
    vel.x = 0;
    vel.y = 0;
}

void Ball::clearScreen() const {
    window* pWind = pGame->getWind();
    pWind->DrawImage("images\\EmptySquare.jpg", uprLft.x, uprLft.y, width, height);
}

void Ball::move()
{
    clearScreen();
    checkEdges();
    uprLft.x += vel.x;
    uprLft.y += vel.y;
}

void Ball::checkEdges()
{
    window* pWind = pGame->getWind();
    int w = pWind->GetWidth();
    int h = pWind->GetHeight();


    if (uprLft.x + width >= w || uprLft.x <= 0) {
        vel.x *= -1;
    }
    if (uprLft.y - 5 < config.toolBarHeight) {
        vel.y *= -1;
    }
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

void Ball::reflectOffPaddle(Paddle& paddle)
{

    double speed = sqrt(pow(vel.x, 2) + pow(vel.y, 2));
    int distFromCenter = abs(this->getCenter().x - paddle.getCenter().x);
    double ratio = 45.0 / (double(config.paddlew) / 10); //get the width to angle ratio
    //divide by 2 as we are looking only at 1/2 the width on each side.
    double angle = ratio * distFromCenter;
    angle = 3.14 * angle / 180; // convert it to radians

    vel.x = speed * cos(angle);
    vel.y = -1 * speed * sin(angle);
    this->setPosition(uprLft.x, paddle.getPosition().y - height - 1);

}

void Ball::draw() const
{
    window* pWind = pGame->getWind();
    pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}

void Ball::collisionAction()
{
}


