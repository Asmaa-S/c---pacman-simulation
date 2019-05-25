#pragma once
#include "cell.h"
class LifeCell : public Cell
{
public:
	LifeCell(int row, int col);
	virtual ~LifeCell();
	virtual int GetCellType();

	//virtual bool ActOn(Player* p);
	bool ActOn(Player* player);
};
