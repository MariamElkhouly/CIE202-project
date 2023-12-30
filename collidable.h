#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)

enum Dir {UP, DOWN, RIGHT, LEFT};
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
    static bool collisionCheck(const collidable &a,const collidable &b);
    Dir collisionDir(const collidable &b);
    virtual void collisionAction() = 0;   //action that should be performed upon collision
};

