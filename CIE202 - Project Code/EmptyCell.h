#pragma once
#include "cell.h"
class EmptyCell :
	public Cell
{
public:
	EmptyCell(int row, int col);
	
	virtual int GetCellType();
	
	 ~EmptyCell();

	 bool ActOn(Player* p);
};

