#pragma once

#include "drawable.h"
#include "Bricks.h"

class game;

class grid:public drawable
{
	brick*** brickMatrix;		//2D array (10�20)of brick pointers
	int count;
	int rows, cols;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void disappear(brick* pBrick);
	void bmbDisappear(brick* pBrick);
	void shkDisappear(brick* pBrick);
	void draw() const;
	void drawGrid() const;
	void removeGrid() const;
	int addBrick(BrickType brkType, point clickedPoint);
	//int COUNT();
	int getcount();
	void setCount(int a);
	int numBricks() const;
	brick* getBrick(int row, int column);


	void removeBrick(point Clicked);
	void saveGame(const string& filename) const; // Save the game state to a text file
	void loadGame(const string& filename);// Load the game state from a text file

};

