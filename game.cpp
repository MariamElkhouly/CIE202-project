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
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;


	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
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
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - config.windWidth * 0.193, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Score: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.13, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, score);
}

int game::getScore() const
{
	return score;
}

void game::setLives(int b)
{
	lives = b;
	//conditions related to the brick type
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - config.windWidth * 0.29, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Lives: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.23, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, lives);
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
	int hr = 0, min = 0;
	int sec = 0;
	bool y = true;
	// Start the timer
	auto start = std::chrono::steady_clock::now();
	// Game loop
	//while (y) {
	//	// Check the elapsed time
	//	auto end = std::chrono::steady_clock::now();
	//	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	//	sec=duration;
	//	if (sec == 60)
	//	{
	//		sec = 0;
	//		min++;
	//		y = false;///stop after 1 min just for testing
	//		if (min == 60) {
	//			min = 0;
	//			hr++;
	//		}
	//	} this is a failed trial to display the accurate time 
	pWind->SetPen(config.penColor, 1);
	pWind->SetBrush(DARKOLIVEGREEN);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.1, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.045, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, sec);
	pWind->DrawString(config.windWidth - config.windWidth * 0.07, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, " : ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.08, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, min);

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
	//for the lives
	pWind->SetPen(MAGENTA, 1);
	pWind->SetBrush(MISTYROSE);
	pWind->DrawRectangle(config.windWidth - config.windWidth * 0.3, config.windHeight - config.statusBarHeight, config.windWidth - config.windWidth * 0.2, config.windHeight);

	setScore(0);
	setLives(3);
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
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	pBall->setPosition(config.ballx, config.bally - 50);
	pBall->setVelocity(0, -10);
	do
	{
	
		/*ptrPaddle->MovePaddle();
		ptrPaddle->draw(); */
		if (gameMode == MODE_DSIGN)
		{
			printMessage("Ready...");
		
		}
		//getMouseClick(x, y);	//Get the coordinates of the user click

		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{

			printMessage("Ready...");
			getMouseClick(x, y);	//Get the coordinates of the user click
			
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit=gameToolbar->handleClick(x, y);
			}
		
		}
		else if(gameMode == MODE_PLAY) {
			
			status();


			pBall->move();
			pBall->draw();

			if (pBall->collisionCheck(*pBall, *ptrPaddle))
				pBall->reflectOffPaddle(*ptrPaddle);

			pWind->GetMouseClick(x, y);
			ptrPaddle->MovePaddle();
			ptrPaddle->draw();
			
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
			if (y >= 0 && y < config.toolBarHeight) {
				ptrPaddle->MovePaddle();
				ptrPaddle->draw();
				if (pBrick->getStrength() == 0)
					bricksGrid->disappear(pBrick); //to make the brick disappear if the brick's strength�is�0	
			}
			
		}
		
		
	} while (!isExit);
}