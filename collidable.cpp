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

	point center_a = this->getCenter(), center_b = b.getCenter();
	point displacement;
	point maxDims = collidable::maxDistance(*this, b);
	point minDims = collidable::minDistance(*this, b);

	displacement.x = abs(center_a.x - center_b.x);
	displacement.y = abs(center_a.y - center_b.y);

	if (maxDims.x / 2 <= displacement.x + minDims.x / 2 && maxDims.y / 2 > displacement.y + minDims.y / 2) {

		if (this->uprLft.x < b.uprLft.x)
			return RIGHT;
		else
			return LEFT;
	}
	else
	{
		if (this->uprLft.y < b.uprLft.y)
			return UP;
		else
			return DOWN;
	}
	return NO;

}


point collidable::collisionPoint(collidable& b)
{

	point p = b.uprLft;
	Dir collDirection = this->collisionDir(b);

	if (collDirection == UP) {

	}

	return p;
}





point collidable::getCenter() const
{
	point center;
	center.x = (uprLft.x + width) / 2;
	center.y = (uprLft.y + height) / 2;
	return center;
}


