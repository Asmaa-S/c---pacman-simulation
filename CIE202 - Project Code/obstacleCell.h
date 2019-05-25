#pragma once
#include "cell.h"
class obstacleCell : public Cell
{
public:
	obstacleCell(int row, int col);
	 ~obstacleCell();
	 virtual int GetCellType();

	virtual bool ActOn(Player* p);
};

