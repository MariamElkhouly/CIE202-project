#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include <chrono>
#include <string>
#include "Ball.h"
#include "Paddle.h"


//Main class that coordinates the game operation
enum MODE	//Game mode
{
	MODE_DSIGN,	//Desing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_PAUSE
};
//Main class that coordinates the game operation
class game
{
	MODE gameMode;

	/// Add more members if needed

	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	Paddle* ptrPaddle;
	Ball* pBall; 
	brick* pBrick;

	int score = 0;
	int lives;

public:
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window

	void clearStatusBar() const;	//Clears the status bar
	void setScore(int a);
	int getScore() const;
	void setLives(int b);
	int getLives() const;
	void setMode(MODE a); //changing the mode
	MODE getMode()const;
	void timer(); //timer for the play mode
	void printMessage(string msg) const;	//Print a message on Status bar
	void status();
	void go();
	void handleBrickCollision();

	window* getWind() const;		//returns a pointer to the graphics window



	grid* getGrid() const;
};

