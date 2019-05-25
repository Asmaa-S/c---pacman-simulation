#pragma once
#include "Cell.h"
#include"Player.h"
class GoalCell : public Cell
{
public:
	GoalCell(int row, int col);
	virtual ~GoalCell();
	virtual int GetCellType();

	bool ActOn(Player* player);


	//ActOn 

};
