#pragma once
#include "cell.h"
#include "GUI.h"
#include "Cell.h"
#include "Player.h"
class Grid;
class enemyCell : public Cell
{
public:
	enemyCell(int row, int col); //constructor
	virtual ~enemyCell();
	void Move(Cell &enemyCurrentCell);
	
	virtual int GetCellType();


	bool ActOn(Player* player);
};

