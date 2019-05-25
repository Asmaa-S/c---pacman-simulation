#include "EnemyBusterCell.h"


EnemyBusterCell::EnemyBusterCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\enemyBuster.jpg"; //needs to be changed
}


EnemyBusterCell::~EnemyBusterCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}
int EnemyBusterCell::GetCellType()
{
	return 9;
}

bool EnemyBusterCell::ActOn(Player* p)
{
	
	//it returns true as it is NOT an obstacle cell
	return true;
}