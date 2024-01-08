#include "game.h"
#include "gameConfig.h"
#include <chrono>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
#include<windows.h>
using namespace std;
game::game()
{
	collectables = nullptr; 
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;
	lives = 3;
	score = 0;
	hr = 0, min = 0;
	sec = 0; 
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft, 0, config.toolBarHeight, this);
	gameToolbar->draw();

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();

	//4- Create the Paddle
	//TODO: Add code to create and draw the paddle
	point p;
	p.x = config.paddleposx;
	p.y = config.paddleposy;
	//p.y = config.paddleAreaHeight;
	ptrPaddle = new Paddle(p, config.paddlew, config.paddleh, this);
	//paddle = new Paddle(p, config.paddlew, config.paddleAreaHeight, this);
	ptrPaddle->draw();

	//while (!kbhit()) // Wait until a key is pressed
	//{
		// Move the object based on keyboard input
	//ptrPaddle ->MovePaddle(); // Adjust the moveStep value to control the movement speed
		//ptrPaddle->draw();

	//}

	//5- Create the ball
	point b;
	b.x = config.ballx;
	b.y = config.bally;

	pBall = new Ball(b, config.ballr, this);
	pBall->draw();

	//6- Create and clear the status bar
	//setStatusBar();
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete ptrPaddle;
	delete pBall;
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}


//void game::updateCollectables()
//{
//	for (int i=0;i<bricksGrid->getcount();i++)
//	{
//		// Update the collectable's position
//		(collectables[i])->move();
//
//		// Check if the collectable is out of the screen
//		if ((collectables[i])->getUpperLeftPoint().y > getWind()->GetHeight())
//		{
//			delete (collectables[i]);
//		}
//		else if (ptrPaddle->collisionCheck(*collectables[i], *ptrPaddle))
//		{
//			// If there is a collision with the paddle
//			collectables[i]->move();  // Perform actions when a collision with the paddle occurs
//
//			delete (collectables[i]);
//		}
//	}
//}

void game::reset()
{
	score = 0;
	lives = 3;
	sec = 0;
	pBall->setPosition(config.ballx, config.bally - 50);
	pBall->setVelocity(0, -10);
	ptrPaddle->setPosition(config.paddleposx, config.paddleposy);
}




void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void game::setScore(int a)
{
	score += a;
	//will be filled according to each brick type
	}

int game::getScore() const
{
	return score;
}

void game::setLives(int b)
{
	lives = b;
	//conditions related to the brick type
	}

int game::getLives() const
{
	return lives;
}

void game::setMode(MODE a)
{
	gameMode = a;
}

MODE game::getMode() const
{
	return gameMode;
}



void game::timer()
{
	// Check the elapsed time
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	// Calculate hours, minutes, and seconds
	sec = (duration / 1000) % 60;
 	min = (duration / (1000 * 60)) % 60;
	hr = duration / (1000 * 60 * 60);
	if (sec == 60)
	{
		sec = 0;
		min++;
		if (min == 60) {
			min = 0;
			hr++;
		}
	}
	pWind->SetPen(config.penColor, 1);
	pWind->SetBrush(DARKOLIVEGREEN);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.1, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.045, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, sec);
	pWind->DrawString(config.windWidth - config.windWidth * 0.07, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, " : ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.08, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, min);

}
int game:: getTimerMinutes() const{
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	int min = (duration / (1000 * 60)) % 60;
	return min;
}

void game:: resetTimer() {
	start = std::chrono::system_clock::now(); // Reset the start time to the current time
}

//////////////////////////////////////////////////////////////////////////////////////////


void game::printMessage(string msg) const	//Prints a message on status bar
{

	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}

void game::status()
{
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	//for the timer
	pWind->SetPen(INDIANRED, 1);
	pWind->SetBrush(DARKOLIVEGREEN);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.1, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	//for the score
	pWind->SetPen(INDIANRED, 1);
	pWind->SetBrush(KHAKI);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.2, config.windHeight - config.statusBarHeight, config.windWidth - config.windWidth * 0.1, config.windHeight);
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - config.windWidth * 0.193, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Score: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.13, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, score);

	//for the lives
	pWind->SetPen(MAGENTA, 1);
	pWind->SetBrush(MISTYROSE);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.3, config.windHeight - config.statusBarHeight, config.windWidth - config.windWidth * 0.2, config.windHeight);
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - config.windWidth * 0.29, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Lives: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.23, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, lives);

	timer();
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}



////////////////////////////////////////////////////////////////////////
void game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	bool isPlay = false;
	bool isSpacePressed = false; // Flag to track spacebar press
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	pBall->setPosition(config.ballx, config.bally - 50);
	pBall->setVelocity(0, -10);
	do
	{
		char cKeyData;
		keytype  ktInput = pWind->GetKeyPress(cKeyData);
		//printMessage("Enter the space bar to start the game");
		if (ktInput == ASCII && cKeyData == ' ')
		{
			
			//*collectables = new collectable [bricksGrid->COUNT()];
			start = std::chrono::system_clock::now();
			isSpacePressed = true;
		}
		
		if (gameMode == MODE_DSIGN)
		{
			pBall->eraseball();
			reset();
			printMessage("Ready...");
			

		}
		//getMouseClick(x, y);	//Get the coordinates of the user click

		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			isSpacePressed = false;
			bricksGrid->draw();
			printMessage("Ready...");
			getMouseClick(x, y);	//Get the coordinates of the user click

			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}

		}
		else if (gameMode == MODE_PLAY && isSpacePressed) {
			
			if (getLives() <= 0) {

				printMessage("Game Over! Final Score: " + to_string(getScore()));
				gameMode = MODE_DSIGN;
				getMouseClick(x, y);
			}
			else
			{
				status();
			}

			pBall->move();
			pBall->draw();
			ptrPaddle->draw();
			ptrPaddle->MovePaddle();
			bricksGrid->removeGrid();


			pWind->GetMouseClick(x, y);
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}

			if (pBall->collisionCheck(*pBall, *ptrPaddle))
				pBall->reflectOffPaddle(*ptrPaddle);

			//updateCollectables();

			for (int i = 0; i <= 10; i++) {
				for (int j = 0; j < 20; j++) {
					pBrick = bricksGrid->getBrick(i, j);
					if (pBrick ) {
						if (collidable::collisionCheck(*pBall, *pBrick)) {
							pBall->clearScreen();
							pBall->Reflect(*pBrick);
							pBrick->decreaseStrength(*pBall); // Decrease the strength of the brick
							if (pBrick->getStrength() <= 0) {
								if (pBrick->getType() == BRK_BMB)
								{
									bricksGrid->bmbDisappear(pBrick);
									bricksGrid->disappear(pBrick);
								}
								else if (pBrick->getType() == BRK_SHK)
								{
									bricksGrid->shkDisappear(pBrick);
									bricksGrid->disappear(pBrick);
								}
								else
									bricksGrid->disappear(pBrick);
								}
							}
						}
					}
				}
			}

			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}

			if (y >= 0 && y < config.toolBarHeight) {
				ptrPaddle->MovePaddle();
				ptrPaddle->draw();
			}

			if ( bricksGrid->numBricks() == 0 ){
				printMessage("End Game! Score:" + to_string(getScore()) + " \tClick anywhere");
				getMouseClick(x, y);
				gameMode = MODE_DSIGN;
			}

			if (pBall->getPosition().y > config.windHeight - config.statusBarHeight) {

				setLives(getLives() - 1);
				if (getLives()>0)
				{
					pBall->setPosition(config.ballx, config.bally);
					ptrPaddle->setPosition(config.paddleposx, config.paddleposy);
					pBall->setVelocity(0, -10);
				}
				

			}

			else if (gameMode == MODE_PAUSE) {
				pWind->GetMouseClick(x, y);
				if (y >= 0 && y < config.toolBarHeight)
				{
					isExit = gameToolbar->handleClick(x, y);
				}
			}
			
		} while (!isExit);

		

	
}
Ball* game::getBall() const
{
	return pBall;
}
;