#include "collidable.h"
#include <iostream>

point collidable::minDistance(collidable& a, collidable& b)
{
	point Dist;

	if (a.uprLft.x < b.uprLft.x) {
		Dist.x = a.width;
	}
	else {
		Dist.x = b.width;
	}

	if (a.uprLft.y < b.uprLft.y) {
		Dist.y = a.height;
	}
	else {
		Dist.y = b.height;
	}

	return Dist;
}

point collidable::maxDistance(collidable& a, collidable& b)
{
	point Dist;

	if (a.uprLft.x > b.uprLft.x) {
		Dist.x = a.width;
	}
	else {
		Dist.x = b.width;
	}

	if (a.uprLft.y > b.uprLft.y) {
		Dist.y = a.height;
	}
	else {
		Dist.y = b.height;
	}

	return Dist;
}

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{
	vel.x = 0;
	vel.y = 0;
}

bool collidable::collisionCheck(collidable& a, collidable& b)
{
	point minDims = minDistance(a, b);

	if (abs(a.uprLft.x - b.uprLft.x) <= minDims.x && abs(a.uprLft.y - b.uprLft.y) <= minDims.y) {
		return true;
	}
	else {
		return false;
	}
}

Dir collidable::collisionDir(collidable& b)
{

	point prev_position_center, center_b, displacement;
	prev_position_center.x = this->getCenter().x - vel.x;
	prev_position_center.y = this->getCenter().y - vel.y;
	
	center_b = b.getCenter();
	
	displacement.x = abs(prev_position_center.x - center_b.x);
	displacement.y = abs(prev_position_center.y - center_b.y);

	if (displacement.y < b.height / 2 + this->height / 2)
		if (this->vel.x > 0)
			return RIGHT;
		else
			return LEFT;
	else if (displacement.x < b.width / 2 + this->width / 2)
		if (this->vel.y > 0)
			return UP;
		else
			return DOWN;


}

point collidable::getCenter() const
{
	point center;
	center.x = (uprLft.x + width) / 2;
	center.y = (uprLft.y + height) / 2;
	return center;
}


