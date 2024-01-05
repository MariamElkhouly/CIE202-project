#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include <ctime>
#include <iostream>
#include <fstream>

fstream file("file.txt", ios::out |ios::in);

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame):
	drawable(r_uprleft, r_width, r_height,  r_pGame)
{}

////////////////////////////////////////////////////  class iconPlay   //////////////////////////////////////////////
iconPlay::iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPlay::onClick()
{
	pGame->setMode(MODE_PLAY);
}

////////////////////////////////////////////////////  class iconAddEasyBrick   //////////////////////////////////////////////
iconAddEasyBrick::iconAddEasyBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddEasyBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Easy Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_EAS, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}


////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height,  r_pGame)
{}

void iconAddNormalBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_NRM, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_HRD, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Bomb Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_BMB, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconAddshockwaveBrick   //////////////////////////////////////////////
iconAddShockWaveBrick::iconAddShockWaveBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddShockWaveBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Shockwave Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_SHK, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_RCK, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconAddPowerBrick   //////////////////////////////////////////////
iconAddPowerBrick::iconAddPowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowerBrick::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on empty cells to add Power Bricks  ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->addBrick(BRK_PWR, clicked);
			pGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}
}

////////////////////////////////////////////////////  class iconDelete //////////////////////////////////////////////
iconDelete::iconDelete(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconDelete::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) {
		pGame->printMessage("Click on the bricks you want to delete ==> Right-Click to stop <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			grid* pGrid = pGame->getGrid();
			pGrid->removeBrick(clicked);
			

			t = pGame->getMouseClick(x, y);
		}
		pGame->printMessage("");
	}

}

////////////////////////////////////////////////////  class iconLoad //////////////////////////////////////////////
iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconLoad::onClick()
{
	if (pGame->getMode() == MODE_PLAY) {
		grid* pGrid = pGame->getGrid(); 
		if (pGrid) {
			pGrid->loadGame("file.txt"); 
		}

	}


}
//
////////////////////////////////////////////////////  class iconSave //////////////////////////////////////////////
iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconSave::onClick()
{
	if (pGame->getMode() == MODE_DSIGN) { 
		grid* pGrid = pGame->getGrid();
		if (pGrid) {
			pGrid->saveGame("file.txt");
		}
	}

}


////////////////////////////////////////////////////  class iconPause   //////////////////////////////////////////////
iconPause::iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPause::onClick()
{
	if (pGame->getMode() == MODE_PLAY) {
	}


}

////////////////////////////////////////////////////  class iconContinue  //////////////////////////////////////////////
iconContinue::iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconContinue::onClick()
{
	if (pGame->getMode() == MODE_PLAY) {
	}

}

////////////////////////////////////////////////////  class iconStop //////////////////////////////////////////////
iconStop::iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconStop::onClick()
{
	if (pGame->getMode() == MODE_PLAY) {
	}

}

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height,  r_pGame)
{}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here
}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{	
	
	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_PLAY] = "images\\ToolbarIcons\\play.jpg";
	iconsImages[ICON_ADD_EASY] = "images\\ToolbarIcons\\easy.jpg";
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\hard.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\bomb.jpg";
	iconsImages[ICON_ADD_SHOCK] = "images\\ToolbarIcons\\shockwave.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\rock.jpg";
	iconsImages[ICON_ADD_POWER] = "images\\ToolbarIcons\\power.jpg";
	iconsImages[ICON_DELETE] = "images\\ToolbarIcons\\delete.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\load.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\save.jpg";
	iconsImages[ICON_PAUSE] = "images\\ToolbarIcons\\pause.jpg";
	iconsImages[ICON_CONTINUE] = "images\\ToolbarIcons\\continue.jpg";
	iconsImages[ICON_STOP] = "images\\ToolbarIcons\\stop.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";

	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon* [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_PLAY] = new iconPlay(p, config.iconWidth, height, pGame); 
	p.x += config.iconWidth;
	iconsList[ICON_ADD_EASY] = new iconAddEasyBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x+= config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_SHOCK] = new iconAddShockWaveBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWER] = new iconAddPowerBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_DELETE] = new iconDelete(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth; 
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_CONTINUE] = new iconContinue(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(ROYALBLUE,3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;
	
	
	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;	
	
	return false;


}

void toolbar::Hide()
{
}

void toolbar::Show()
{
}

