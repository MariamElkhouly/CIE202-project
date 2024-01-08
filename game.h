#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include <chrono>
#include <string>
#include "Ball.h"
#include "Paddle.h"
#include "collectable.h"
#include <vector>
#include <iostream>

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
	int hr, min;
	int sec;
	std::chrono::time_point<std::chrono::system_clock> start; 
	MODE gameMode;

	/// Add more members if needed

	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	Paddle* ptrPaddle;
	Ball* pBall; 
	brick* pBrick;
	collectable** collectables;
	int score = 0;
	int lives;
public:
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user
	window* CreateWind(int, int, int, int) const; //creates the game window

	void reset();
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
//	void updateCollectables();

	Ball* getBall() const;
	window* getWind() const;		//returns a pointer to the graphics window



	grid* getGrid() const;
};

