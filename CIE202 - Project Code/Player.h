#pragma once

#include "Cell.h"
#include "GUI.h"
class Grid;

class Player 
{
	int lives;    // number of lives (initially 3)
	float health; // player's health percentage (initially 100% -> full health)
	float score;  // player's score (initially 0)
	Cell PositionCell;
	bool win= false;

public:
	void initializethings();
	bool getwin();
	void makewin();
	Player(Cell pos); // Constructor
	
	void setPosition(Cell);
	Cell getPosition();
	void Move(Grid* pGrid, ActionType MoveAction); // Moves the Player in a specific direction if possible

	void change_score(int SCore);
	void add_life();// lifecell encounter
	void remove_life();
	void track_health();//while app_running
	int get_health();// status bar
	int get_score();//status bar
	int get_lives();//status bar
	void change_health(int h,string action); // action is either "add" or "sub"
};

