#include "EmptyCell.h"


EmptyCell::EmptyCell(int row, int col):Cell(row,col)
{
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}


EmptyCell::~EmptyCell(void)
{
}

int EmptyCell::GetCellType()
{
	return 1;
}
bool EmptyCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

