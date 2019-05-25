#include "enemyCell.h"
#include "cell.h"
#include "Player.h"
enemyCell::enemyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\enemy.jpg";
}


enemyCell::~enemyCell()
{
	ImagePath = "Images\\Cells\\EmptyCell.jpg";
}

int enemyCell::GetCellType()
{
	return 4;
}
bool enemyCell::ActOn(Player * player)
{
	
	player->change_health(25,"sub");
	player->track_health();
	
	return true;
}

//bool enemyCell::ActOn(Player* p)
//{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	//return true;
//}


