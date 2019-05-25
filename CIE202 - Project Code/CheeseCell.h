#pragma once

#include "Cell.h"


class CheeseCell : public Cell
{
public:
	CheeseCell(int row, int col);
	virtual ~CheeseCell();
	virtual int GetCellType();

	//ActOn 
	bool ActOn(Player *player);
};

