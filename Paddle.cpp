#include "Paddle.h"
#include "collidable.h"


Paddle::Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Paddle\\paddle.jpg";
}

void Paddle::collisionAction(){

return;
}
