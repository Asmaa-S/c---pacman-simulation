#pragma once

#include "GUI.h"
#include "DEFS.h"
#include "Cell.h"
#include "enemyCell.h"
#include "obstacleCell.h"


class Player;	//forward class declaration
class obstacle;
class enemy;
class Grid
{
	GUI * pGUI;   // a pointer to the the interface
	Cell*GameCells[NumRowCells][NumColumnCells];	// Array of Pointers to Cell
	Player* player;
	

	obstacle* Obstacle;
public:

	Grid();	  
	void resetplayerposition(Player * player);
	

	// ========== Action-Related Functions ==========

	

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type

	void ExecuteAction(ActionType) ;  // Creates an action of the passed actionType and executes it

	void setCell(int r, int c, Cell* pCell);	//updates cell r,c to hold the new pointer pCell
	
	void MoveRand(Cell* enemyCurrentCell);  
	bool MoveIfPossible(Cell * pCurrentCell, ActionType dir); // Moves the entered position in the passed direction if no obstacles
	                                                       // updates currentCell if move takes place
	                                                       // Note: It returns bool indicating if a move occured or not

	bool IsValidCell(int r, int c) const;

	void SaveGrid() const;

	void DrawAllCells() const; // Draws the Grid and All its GameObjects

	void RunModes();

	GUI * getGUI() const;	// Gets a Pointer to the GUI



	Cell  GetCellClicked(); //its for a mouse click and Returns the Clicked Cell
								 // It is needed only in Create-Grid Mode
								 // If the click is NOT on a cell, (-1,-1) is returned
	

	~Grid();
	void addselectedmenuitem(ActionType actxion );
	//void msgbarprint();
	void RunApp();	//Runs the application
	void resolvecollision(Player* player, Cell* cell);
};
