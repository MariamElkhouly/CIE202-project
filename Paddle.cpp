#include "Paddle.h"
#include"game.h"




Paddle::Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    collidable(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Paddle\\paddle.jpg";
}

void Paddle::MovePaddle()
{//MovePaddle(int& xposition, int movestep)
    
        keytype ktInput;
        char cKeyData;
        window* pw = this->pGame->getWind();
        ktInput = pw->GetKeyPress(cKeyData);
        if (ktInput == ARROW)
        {
            if (cKeyData == 4)
            {
                erasepaddle();
                uprLft.x-=5;

            }
            else if (cKeyData == 6) {
                erasepaddle();
                uprLft.x+=5;
            }

        }

 

}

void Paddle::erasepaddle()
{
    window* pw = this->pGame->getWind();
    pw->SetBrush(LAVENDER);
    pw->SetPen(LAVENDER);
    pw->DrawRectangle(0, uprLft.y, 1200, uprLft.y + height, FILLED);
}
void Paddle::collisionAction() {

    return;
}
