#include"GoalCell.h"

GoalCell::GoalCell(int row, int col) : Cell(row, col)
{
	ImagePath = "Images\\Cells\\goal.jpg";

}
int GoalCell::GetCellType()
{
	return 6;
}
GoalCell::~GoalCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}

bool GoalCell::ActOn(Player * player)
{
	player->makewin();

	return false;
}

//ActOn 
