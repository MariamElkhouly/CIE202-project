#include "Paddle.h"
#include "collidable.h"
#include <iostream>
#include <conio.h>



Paddle::Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Paddle\\paddle.jpg";
}

void Paddle::MovePaddle(int& xposition, int movestep)
{
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) // Check if the left arrow key is pressed
        {
            xposition -= movestep;
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // Check if the right arrow key is pressed
        {
            xposition += movestep;
        }
}

void Paddle::collisionAction(){

return;
}
