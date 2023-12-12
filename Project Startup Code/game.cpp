#include "game.h"
#include "gameConfig.h"
#include <chrono>
#include <string>
#include <iostream>
using namespace std;
game::game()
{
	score = 0;
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

	//5- Create the ball
	//TODO: Add code to create and draw the ball
	
	//6- Create and clear the status bar
	//setStatusBar();
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
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
	//for the timer
	pWind->SetPen(INDIANRED, 1);
	pWind->SetBrush(DARKOLIVEGREEN);
	pWind->DrawRectangle(config.windWidth-100, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	//for the score
	pWind->SetPen(INDIANRED, 1);
	pWind->SetBrush(KHAKI);
	pWind->DrawRectangle(config.windWidth - 200, config.windHeight - config.statusBarHeight, config.windWidth-100, config.windHeight);
	//for the lives
	pWind->SetPen(MAGENTA, 1);
	pWind->SetBrush(MISTYROSE);
	pWind->DrawRectangle(config.windWidth - 300, config.windHeight - config.statusBarHeight, config.windWidth-200, config.windHeight);
}

void game::setScore(int a)
{
	score = a;
	//will be filled according to each brick type
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - 195, config.windHeight - config.statusBarHeight+10, "Score: ");
	pWind->DrawInteger(config.windWidth - 130, config.windHeight - config.statusBarHeight + 10, score);
}

void game::setLives(int b)
{
	lives = b;
	//conditions related to the brick type
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - 290, config.windHeight - config.statusBarHeight + 10, "Lives: ");
	pWind->DrawInteger(config.windWidth - 230, config.windHeight - config.statusBarHeight + 10, lives);
}

void game::timer()
{
	long long hr = 0, min = 0;
	long long sec;
	bool y = true;
	// Start the timer
	auto start = std::chrono::steady_clock::now();
	// Game loop
	while (y) {
		// Check the elapsed time
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
		sec=duration;
		if (sec == 60)
		{
			sec = 0;
			min++;
			y = false;///stop after 1 min just for testing
			if (min == 60) {
				min = 0;
				hr++;
			}
		}
		pWind->DrawInteger(config.windWidth - 45, config.windHeight - config.statusBarHeight + 10, sec);
		pWind->DrawInteger(config.windWidth - 90, config.windHeight - config.statusBarHeight + 10, min);
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////


void game::printMessage(string msg) const	//Prints a message on status bar
{
	
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
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
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	
	do
	{
		printMessage("Ready...");
		setScore(8);
		setLives(3);
		timer();
		getMouseClick(x, y);	//Get the coordinates of the user click
		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit=gameToolbar->handleClick(x, y);
			}
		}

	} while (!isExit);
}