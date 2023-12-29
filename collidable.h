#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)

enum Dir {NO, RIGHT, UP, DOWN, LEFT};
class collidable :public drawable
{
protected:
    bool isPaddle = false;
    point midOfCollision;
    point vel;
    static point minDistance(collidable &a, collidable &b);
    static point maxDistance(collidable& a, collidable& b);
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    point getCenter() const;
    static bool collisionCheck(collidable &a, collidable &b);
    Dir collisionDir(collidable &b);
    point collisionPoint(collidable &b);
    virtual void collisionAction() = 0;   //action that should be performed upon collision
};
//

