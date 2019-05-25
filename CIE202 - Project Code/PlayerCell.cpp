#include "PlayerCell.h"


PlayerCell::PlayerCell(int row, int col):Cell(row,col)
{
	ImagePath = "images\\Cells\\PlayerCell.jpg";
}


PlayerCell::~PlayerCell()
{
}
int PlayerCell::GetCellType()
{
	return 2;
}

bool PlayerCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}


