#include "collidable.h"

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
		Dist.x = a.height;
	}
	else {
		Dist.x = b.height;
	}

	return Dist;
}

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame):
			drawable(r_uprleft, r_width, r_height,  r_pGame)
{
}

bool collidable::collisionCheck(collidable &a, collidable &b)
{
	point minDims = minDistance(a, b);

	if (abs(a.uprLft.x - b.uprLft.x) <= minDims.x && abs(a.uprLft.y - b.uprLft.y) <= minDims.y) {
		return true;
	}
	else {
		return false;
	}

	/*point center_a, center_b, limiting_distance;
	point mid;

	limiting_distance.x = a.width / 2 + b.width / 2;
	limiting_distance.y = a.height / 2 + b.height / 2;

	center_a.x = (a.uprLft.x + a.width) / 2;
	center_a.y = (a.uprLft.y + a.height) / 2;
	center_b.x = (b.uprLft.x + b.width) / 2;
	center_b.y = (b.uprLft.y + b.height) / 2;

	if ( abs(center_a.x - center_b.x) <= limiting_distance.x && abs(center_a.y - center_b.y) <= limiting_distance.y)
	{

		a.collisionAction();
		b.collisionAction();
		return true;
	}
	else {
		return false;
	}*/

}

point collidable::collisionPoint(collidable &a, collidable &b)
{
	point center_a, center_b, limiting_distance;
	point mid, displacement;
	float similarity;

	limiting_distance.x = a.width / 2 + b.width / 2;
	limiting_distance.y = a.height / 2 + b.height / 2;

	center_a = a.getCenter();
	center_b = b.getCenter();

	// getting the displacement vector from the center of b to a;
	displacement.x = center_a.x - center_b.x;
	displacement.y = center_a.y - center_b.y;
	double magnitude = sqrt(pow(displacement.y, 2) + pow(displacement.x, 2));
	double tan_t = double(displacement.y) / double(displacement.x);

	if ( abs(tan_t) < 1){
		mid.x = center_b.x + b.width / 2;
		similarity = b.width / displacement.x; //we have 1 similar triangles, and we get the similarity coefficients
		mid.y = center_b.y + displacement.y * similarity; 
	}
	else {
		mid.y = center_b.y + b.height / 2;
		similarity = b.height / displacement.y;
		mid.x = center_b.x + displacement.x * similarity;
	}

	return mid;
}

point collidable::getCenter() const
{
	point center;
	center.x = (uprLft.x + width) / 2;
	center.y = (uprLft.y + height) / 2;
	return center;
}


