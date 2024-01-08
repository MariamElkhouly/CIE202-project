#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j]) {
				delete brickMatrix[i][j];
				brickMatrix[i][j] = nullptr;
			}
		}
		delete[] brickMatrix[i];
	}
	delete[] brickMatrix;
}

void grid::disappear(brick* pBrick)
{
	// Find and delete the brick in the brickMatrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] == pBrick) {
					window* pWind = pGame->getWind();
					pWind->SetPen(config.gridLinesColor, 1);
					pWind->SetBrush(LAVENDER);
					pWind->DrawRectangle(brickMatrix[i][j]->getPosition().x, brickMatrix[i][j]->getPosition().y, pBrick->getPosition().x + config.brickWidth, pBrick->getPosition().y + config.brickHeight);
					delete brickMatrix[i][j];
					brickMatrix[i][j] = nullptr;
				
				//return;  // Assuming each brick exists only once in the grid
			}
		}
	}
}

void grid::bmbDisappear(brick* pBrick)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] == pBrick) {
				window* pWind = pGame->getWind();
				if (pBrick->getType() == BRK_BMB) {
					// Disappear brick below
					if (i + 1 < rows && brickMatrix[i + 1][j]) {
						pWind->SetPen(config.gridLinesColor, 1);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(brickMatrix[i + 1][j]->getPosition().x, brickMatrix[i + 1][j]->getPosition().y, brickMatrix[i + 1][j]->getPosition().x + config.brickWidth, brickMatrix[i + 1][j]->getPosition().y + config.brickHeight);
						delete brickMatrix[i + 1][j];
						brickMatrix[i + 1][j] = nullptr;
					}
					// Disappear brick above
					if (i - 1 >= 0 && brickMatrix[i - 1][j]) {
						pWind->SetPen(config.gridLinesColor, 1);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(brickMatrix[i - 1][j]->getPosition().x, brickMatrix[i - 1][j]->getPosition().y, brickMatrix[i - 1][j]->getPosition().x + config.brickWidth, brickMatrix[i - 1][j]->getPosition().y + config.brickHeight);
						delete brickMatrix[i - 1][j];
						brickMatrix[i - 1][j] = nullptr;
					}
					// Disappear brick to the right
					if (j + 1 < cols && brickMatrix[i][j + 1]) {
						pWind->SetPen(config.gridLinesColor, 1);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(brickMatrix[i][j + 1]->getPosition().x, brickMatrix[i][j + 1]->getPosition().y, brickMatrix[i][j + 1]->getPosition().x + config.brickWidth, brickMatrix[i][j + 1]->getPosition().y + config.brickHeight);
						delete brickMatrix[i][j + 1];
						brickMatrix[i][j + 1] = nullptr;
					}
					// Disappear brick to the left
					if (j - 1 >= 0 && brickMatrix[i][j - 1]) {
						pWind->SetPen(config.gridLinesColor, 1);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(brickMatrix[i][j - 1]->getPosition().x, brickMatrix[i][j - 1]->getPosition().y, brickMatrix[i][j - 1]->getPosition().x + config.brickWidth, brickMatrix[i][j - 1]->getPosition().y + config.brickHeight);
						delete brickMatrix[i][j - 1];
						brickMatrix[i][j - 1] = nullptr;
					}

					// Delete the bomb brick itself
					pWind->SetPen(config.gridLinesColor, 1);
					pWind->SetBrush(LAVENDER);
					pWind->DrawRectangle(brickMatrix[i][j]->getPosition().x, brickMatrix[i][j]->getPosition().y, brickMatrix[i][j]->getPosition().x + config.brickWidth, brickMatrix[i][j]->getPosition().y + config.brickHeight);
					delete brickMatrix[i][j];
					brickMatrix[i][j] = nullptr;
				}
			}
		}
	}
}

void grid::shkDisappear(brick* pBrick)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] == pBrick) {
				window* pWind = pGame->getWind();
				if (pBrick->getType() == BRK_SHK) {
					// Disappear entire row except for the shockwave brick
					for (int k = 0; k < cols; k++) {
						if (brickMatrix[i][k] && k != j) {
							pWind->SetPen(config.gridLinesColor, 1);
							pWind->SetBrush(LAVENDER);
							pWind->DrawRectangle(brickMatrix[i][k]->getPosition().x, brickMatrix[i][k]->getPosition().y, brickMatrix[i][k]->getPosition().x + config.brickWidth, brickMatrix[i][k]->getPosition().y + config.brickHeight);
							delete brickMatrix[i][k];
							brickMatrix[i][k] = nullptr;
						}
					}

					// Disappear entire column except for the shockwave brick
					for (int k = 0; k < rows; k++) {
						if (brickMatrix[k][j] && k != i) {
							pWind->SetPen(config.gridLinesColor, 1);
							pWind->SetBrush(LAVENDER);
							pWind->DrawRectangle(brickMatrix[k][j]->getPosition().x, brickMatrix[k][j]->getPosition().y, brickMatrix[k][j]->getPosition().x + config.brickWidth, brickMatrix[k][j]->getPosition().y + config.brickHeight);
							delete brickMatrix[k][j];
							brickMatrix[k][j] = nullptr;
						}
					}
				}
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

void grid::removeGrid() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(LAVENDER, 2);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y + rows * config.brickHeight);
	}

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

//int grid::COUNT()
//{
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (brickMatrix[i][j]->getType() ==BRK_PWR ) {
//				count++;
//			}
//		}
//	}
//	return count;
//}

int grid::getcount()
{
	return count;
}

void grid::setCount(int a)
{
	count = a;
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
	ofstream outfile("file.txt");

	// Iterate through bricks and save relevant data to the file
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j]) {
				outfile << i << " " << j << " " << brickMatrix[i][j]->getType() << "\n";
			}
		}
	}

	outfile.close();
}

void grid::loadGame(const string& filename)
{
	ifstream infile("file.txt");

	// Clear existing bricks
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j]) {
				delete brickMatrix[i][j];
				brickMatrix[i][j] = nullptr;
			}
		}
	}

	while (!infile.eof()) {
		int row, col;
		int brickType;

		infile >> row >> col >> brickType;

		BrickType brkType = static_cast<BrickType>(brickType); //convert integer to BrickType
		point brickPosition;
		brickPosition.x = col * config.brickWidth;
		brickPosition.y = (row+2) * config.brickHeight;
		draw();
		addBrick(brkType, brickPosition);
	}

	infile.close();


}
