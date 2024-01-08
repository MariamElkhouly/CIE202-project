#include "Collectable.h"
#include "game.h"
collectable::collectable(point ul, int w, int h, game* pG) : collidable(ul, w, h, pG)
{
}
collectable::~collectable()
{
}
collectableType collectable::getType()
{
    return TYPE;
}
void collectable::setType(collectableType a)
{
    TYPE = a;
}
void collectable::move()
{
    window* pWind = pGame->getWind();
    pWind->DrawRectangle(uprLft.x, width, uprLft.y,height);
    int w = pWind->GetWidth();
    int h = pWind->GetHeight();
    if (uprLft.x + width >= w || uprLft.x <= 0) {
        vel.x *= -1;
    }
    if (uprLft.y - 5 < config.toolBarHeight) {
        vel.y *= -1;
    }
    uprLft.x += vel.x;
    uprLft.y += vel.y;
}
point collectable::getUpperLeftPoint() const
{
    return uprLft;
}
int collectable::getWidth() const
{
    return width;
}
int collectable::getHeight() const
{
    return height;
}
void collectable::setUpperLeftPoint(int x,int y)
{
    uprLft.x = x;
    uprLft.y = y;
}
void collectable::setVelocity(float v_x, float v_y)
{
    vel.x = v_x;
    vel.y = v_y;
}


