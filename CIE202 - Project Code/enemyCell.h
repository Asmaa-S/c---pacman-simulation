#pragma once
#include "cell.h"
class enemyCell : public Cell
{
public:
	enemyCell(int row, int col);
	virtual ~enemyCell();

	virtual int GetCellType();


	bool ActOn(Player* player);
};

