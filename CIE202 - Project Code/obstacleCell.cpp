#include "obstacleCell.h"


obstacleCell::obstacleCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\obstacle.jpg";
}


obstacleCell::~obstacleCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";

}
int obstacleCell::GetCellType()
{
	return 3;
}
bool obstacleCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return false;
}


