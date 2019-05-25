#pragma once

#include "Cell.h"


class CherryCell : public Cell
{
public:
	CherryCell(int row, int col);
	virtual ~CherryCell();

	virtual int GetCellType();


	bool ActOn(Player* player);

	//ActOn 

};
