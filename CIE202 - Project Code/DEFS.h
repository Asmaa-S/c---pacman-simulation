#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (you can add more if needed)
{
	//  Possible action

	LOAD,	// Load game file
	SAVE,	// Save game to a file
	START,	// Start the game
	
	EXIT,	// Exit Application
	ADD_ENEMY,
	ADD_OBSTACLE,
	ADD_CHERRY,
	ADD_LIFE,
	ADD_ENEMYBUSTER,
	ADD_CHEESE,
	ADD_EMPTY,
	//  Player move direction 
	PAUSE,	//Pause the game
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	NO_MOVE,

	EMPTY,				// a click inside empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// a click inside Grid Area
	STATUS 				// a click inside StatusBar Area

	
};
enum CellType
{ BASE_CELL,
	EMPTY_CELL,
	PLAYER_CELL,
	OBSTACLE_CELL,
	ENEMY_CELL,
	LIFE_CELL,
	GOAL_CELL,
	CHERRY_CELL,
	CHEESE_CELL,
	ENEMY_BUSTER_CELL

};

#endif