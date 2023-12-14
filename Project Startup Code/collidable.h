#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)

class collidable :public drawable
{
protected:
    bool isPaddle = false;
    point midOfCollision;
    
    static point minDistance(collidable &a, collidable &b);

public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    point getCenter() const;
    static bool collisionCheck(collidable &a, collidable &b);
    static point collisionPoint(collidable &a, collidable &b);
    virtual void collisionAction() = 0;   //action that should be performed upon collision
};


