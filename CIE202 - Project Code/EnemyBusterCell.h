#pragma once

#include "Cell.h"

class EnemyBusterCell : public Cell
{
public:
	EnemyBusterCell(int row, int col);

 ~EnemyBusterCell();


 virtual int GetCellType();


 bool ActOn(Player* p);

};