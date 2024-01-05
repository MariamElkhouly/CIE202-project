#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <fstream>
#include <sstream>

grid::grid(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{

	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick ** [rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;
}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;

}

void grid::disappear(brick* pBrick)
{
	// Find and delete the brick in the brickMatrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] == pBrick) {
				delete brickMatrix[i][j];
				brickMatrix[i][j] = nullptr;
				return;  // Assuming each brick exists only once in the grid
			}
		}
	}
}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)

	//Here we assume that the above checks are passed
	
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y-uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y+ gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_EAS:	
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new easyBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HRD:	
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_BMB:	
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new bombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_SHK:	
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new shockwaveBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_RCK:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new rockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_PWR:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
		//TODO: 
		// handle more types
	}
	return 1;
}


brick* grid::getBrick(int row, int column)
{
	return brickMatrix[row][column];
}

void grid::removeBrick(point Clicked)
{
	int gridCellRowIndex = (Clicked.y - uprLft.y) / config.brickHeight;
    int gridCellColIndex = Clicked.x / config.brickWidth;
	point newBrickUpleft; 
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth; 
	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight; 
    if (gridCellRowIndex >= 0 && gridCellRowIndex < rows &&
        gridCellColIndex >= 0 && gridCellColIndex < cols &&
        brickMatrix[gridCellRowIndex][gridCellColIndex]) {
        delete brickMatrix[gridCellRowIndex][gridCellColIndex];
        brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
		window* pWind = pGame->getWind();
		pWind->SetPen(config.gridLinesColor, 1); 
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(newBrickUpleft.x, newBrickUpleft.y, newBrickUpleft.x +config.brickWidth, newBrickUpleft.y+config.brickHeight,FILLED,1,1);
    }
}

void grid::saveGame(const string& filename) const
{
	fstream file("file.txt",ios::out);

	// Iterate through bricks and save relevant data to the file
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j]) {
				// Save data for each brick in a comma-separated format
				file << i << "," << j << "," << brickMatrix[i][j]->getType() << "\n";
			}
		}
	}

	file.close();
}

void grid::loadGame(const string& filename)
{
	fstream file("file.txt",ios::in);
	string line; //contains the comma separated values

	// Clear existing bricks
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j]) {
				delete brickMatrix[i][j];
				brickMatrix[i][j] = nullptr;
			}
		}
	}

	while (getline(file, line)) {
		istringstream iss(line); //istringstream will treat line as an input string, and iss is line cin
		int row, col;
		int brickType;

		// Parse the comma-separated values
		if (!(iss >> row >> col >> brickType)) {
			// Handle parsing error
			continue;
		}

		BrickType brkType = static_cast<BrickType>(brickType); //convert integer to BrickType
		point brickPosition;
		brickPosition.x = col * config.brickWidth;
		brickPosition.y = row * config.brickHeight;
		addBrick(brkType, brickPosition);
	}

	file.close();


}

