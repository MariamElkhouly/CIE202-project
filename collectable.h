#pragma once
#include "collidable.h"
enum collectableType{ Up, Down};
class collectable :public collidable
{
	collectableType TYPE;
public:
	collectable(point ul, int w, int h, game* pG);
	virtual ~collectable();
	virtual collectableType getType();
	virtual void setType(collectableType a);
	void move();
	point getUpperLeftPoint() const;
	virtual int getWidth() const;
	virtual int getHeight() const;
	void setUpperLeftPoint(int x, int y);
	void setVelocity(float v_x, float v_y); 
 };


