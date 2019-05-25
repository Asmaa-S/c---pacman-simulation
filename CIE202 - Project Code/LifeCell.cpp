#include "LifeCell.h"
#include "Player.h"

LifeCell::LifeCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\lifeCoin.jpg";
}


LifeCell::~LifeCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}

int LifeCell::GetCellType()
{
	return 5;
}
bool LifeCell::ActOn(Player * player)
{
	player->add_life();
	return true;
}



