#include"CheeseCell.h"
#include"Player.h"

CheeseCell::CheeseCell(int row, int col) : Cell(row, col)
{
	ImagePath = "Images\\Cells\\cheese.jpg";

}
CheeseCell::~CheeseCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}
int CheeseCell::GetCellType()
{
	return 8;
}
bool CheeseCell::ActOn(Player* player)
{
	player->change_score(10);
	return true;
	
}
//actOn 
