#include"CherryCell.h"
#include "Player.h"
CherryCell::CherryCell(int row, int col) : Cell(row, col)
{
	ImagePath = "Images\\Cells\\cherry.jpg";

}
CherryCell :: ~CherryCell() {
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}
int CherryCell::GetCellType()
{
	return 7;
}
//ActOn 
bool CherryCell::ActOn(Player* player)
{
	player->change_score(50);
	return true;
}