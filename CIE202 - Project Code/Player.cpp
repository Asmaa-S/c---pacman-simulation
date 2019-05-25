#include "Player.h"
#include "Grid.h"
#include "GUI.h"

void Player::initializethings()
{
	lives = 4;
	score = 0;
	health = 100;
	win = false;
}

bool Player::getwin()
{
	return win;
}
void Player::makewin()
{
	win = true;
}

Player::Player(Cell pos)
{
	PositionCell = pos;
	lives = 4;
	health = 100;
	score = 0; // icreases with cheese or cherry collection
	// Makes all the needed initialization
}

void Player::Move(Grid* pGrid, ActionType dir)
{
	// Take a copy of the position before change
	Cell oldPosition = PositionCell; 

	// Try to take a Move from Keyboard
	GUI* pGUI = pGrid->getGUI();
	//DIRECTION dir = pGUI->TakeMoveDirection(PositionCell);

	// Check if the Move is Possible (No Obstacles)
	pGrid->MoveIfPossible(&PositionCell, dir); // if the move is possible, position will be changed (passed by ref)

}

void Player::setPosition(Cell pos)
{
	PositionCell = pos;
}
Cell Player::getPosition()
{
	return  PositionCell;
}

void Player::change_score(int SCore)
{
	score += SCore;
}
void Player::add_life()
{
	lives+=1;
}
void Player::remove_life()
{
	lives--;
}

void Player::track_health()
{
	if (health == 0)
	{
		lives--;
		health = 100;
	}
}

int Player::get_health()
{
	return health;
}

int Player::get_score()
{
	return score;
}

int Player::get_lives()
{
	return lives;
}


void Player::change_health(int h, string a)
{
	if (a == "add")
		health += h;
	else if (a == "sub")
		health -= h;
}
