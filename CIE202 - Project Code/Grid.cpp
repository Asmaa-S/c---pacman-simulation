#include "Grid.h"
#include <string.h>
#include<string>
#include <cstdlib> 
#include "enemyCell.h"
#include "Player.h"
#include "EmptyCell.h"
#include "PlayerCell.h"
#include <iostream>
#include"CherryCell.h"
#include"CheeseCell.h"
#include"GoalCell.h"
#include"LifeCell.h"
#include"EnemyBusterCell.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


Grid::Grid() 
{
	// initializes all the GameObject pointer of the List to NULL
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)		{
			
			GameCells[i][j] = new EmptyCell(i,j);	//start with all cells as empty cells
		}
	}
	pGUI = new GUI;
	DrawAllCells();
	
}

void Grid::resetplayerposition(Player * player)
{
	for (int i = 0; i < 7; i++)
		player->Move(this, MOVE_UP);

	for (int i = 0; i < 5; i++)
		player->Move(this, MOVE_LEFT);


}



Cell Grid::GetCellClicked() {
	int x = -1, y = -1;
	pGUI->GetPointClicked(x,y,true);

	//if (y >StatusBarHeight && y < ToolBarHeight)
	//{/

		int Columnnumber = (x /50);
		int Rownumber = ((y- ToolBarHeight)/GridCellWidth);
		return Cell(Rownumber, Columnnumber);

//	}
}




/////////////////////////////////////////////////////////////////////////////////////////////
// Moves the entered position in the passed direction if possible
// updates currentCell if move takes place
// Note: It returns bool indicating if a move occured or not
// ?? ???? ?????? ??????? ???? ????? ?? ?? ?? OBSTACLE ?? ??? ??GRID ????? ?????
// ?? ?? ??aCT ON
bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir) 
{
	
	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int playerOldRow = pCurrentCell->getRow();
	int playerOldCol = pCurrentCell->getCol();

	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol ; 
	
	switch(dir)
	{
	case MOVE_UP:
		TargetRow--;
		break;
	case MOVE_DOWN:
		TargetRow++;
		break;
	case MOVE_LEFT:
		TargetCol--;
		break;
	case MOVE_RIGHT:
		TargetCol++;;
		break;
	}

	if( !IsValidCell(TargetRow, TargetCol))
		return false;

	//get the target cell
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];

	if(!pTargetCell->ActOn(player))	//The target cell is an obstacle ==> no action should be taken
		return false;

	//The target cell is not an obstacle and has acted on the player
	//The player position should be updated to the target cell


	//resolve collision with taret cell
	resolvecollision(player , pTargetCell);
	
	//Player should be moved to the target cell
	//1-delete the target cell and make it point to the PlayerCell
	setCell(TargetRow,TargetCol, pCurrentCell);

	//2- update player position
	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	//3- Convert the old player position to an Empty cell
	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow,playerOldCol);

	//4- Redraw both cells
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);

	return true;
}

void Grid::DrawAllCells() const	
{
	// Draw Empty Grid
	pGUI->ClearGridArea();

	// Draw all the GameObject of the Grid
	for (int i = 0; i < NumRowCells; i++)
		for (int j = 0; j < NumColumnCells; j++)
			pGUI->DrawCell(GameCells[i][j]);
}

void Grid::setCell(int row, int col, Cell* pCell)
{	
	if(GameCells[row][col])
		delete GameCells[row][col];	//if cell ptr is not null, delete it first
	
	GameCells[row][col] = pCell;

}


GUI * Grid::getGUI() const
{
	return pGUI;
}
///////////////////////////////////////////////////////////////////
//				Action-related functions
///////////////////////////////////////////////////////////////////




ActionType Grid::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pGUI->GetUserAction( ); 
}

////////////////////////////////////////////////////////////////////////////////////



// Creates an action and executes it
void Grid::ExecuteAction(ActionType ActType) 
{
	string health = std::to_string(player->get_health());
	string score = std::to_string(player->get_score());
	string lives = std::to_string(player->get_lives());

	switch (ActType)
	{
	case LOAD:
		// Call Load function to load game from a file
		

	case SAVE:
		// Call Save function to Save current game to a file
		if (pGUI->getInterfaceMode() == MODE_MENU)
			SaveGrid();
		
		break;

	case START:	//start game 
		pGUI->PrintMessage("Health= "+ health +"  lives=  "+lives  +"  score = "+  score);
		pGUI->setInterfaceMode(MODE_GAME);
		player-> initializethings();
		RunModes();
		break;
	case PAUSE:	//pause game
		pGUI->setInterfaceMode(MODE_MENU);
		break;
	case ADD_ENEMY:
		if (pGUI->getInterfaceMode()==MODE_MENU)
		pGUI->PrintMessage("You have selected enemy, choose a cell to place it");
		
		break;
		if (pGUI->getInterfaceMode() == MODE_MENU)
	case ADD_OBSTACLE:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected obstacle, choose a cell to place it");
	

		break;
		
	case ADD_CHEESE:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected cheese, choose a cell to place it");
		
		break;
	case ADD_CHERRY:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected cherry, choose a cell to place it");
		

		break;
	case ADD_LIFE:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected life coin, choose a cell to place it");
		
		break;
	case ADD_ENEMYBUSTER:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected enemy buster, choose a cell to place it");
		break;
	case ADD_EMPTY:
		if (pGUI->getInterfaceMode() == MODE_MENU)
		pGUI->PrintMessage("You have selected the eraser, choose a cell to erase its content");

	

	///TODO: Add a case for EACH Action type
	case MOVE_UP:
		if (pGUI->getInterfaceMode() == MODE_GAME )
			player->Move(this, ActType);
		break;
	case MOVE_DOWN:
		if (pGUI->getInterfaceMode() == MODE_GAME)
			player->Move(this, ActType);
		break;
	case MOVE_RIGHT:
		if (pGUI->getInterfaceMode() == MODE_GAME)
			player->Move(this, ActType);
		break;
	case MOVE_LEFT:
		if (pGUI->getInterfaceMode() == MODE_GAME)
			player->Move(this, ActType);
		break;
	player->Move(this,ActType);
			

	//case STATUS:	// a click on the status bar ==> no action
		//return;


		
	}

}


Grid::~Grid()
{
	delete pGUI;
}

void Grid::addselectedmenuitem(ActionType actxion)
{
	ActionType currentaxn; //ADD_EMPTY;

    Cell cell = GetCellClicked();
	int row = cell.getRow();
	int col = cell.getCol();
		

	if (row == 7 && col == 12 || row == NumRowCells - 2 && col == NumColumnCells - 2) {
		pGUI->PrintMessage("You can't replace or delete either the player cell or the goal cell");
	}
	else {
		if (actxion == ADD_ENEMY)
		{
			enemyCell* eCell = new enemyCell(row, col);
			setCell(row, col, eCell);

			pGUI->DrawCell(eCell);




		}
		else if (actxion == ADD_OBSTACLE)
		{


			obstacleCell* oCell = new obstacleCell(row, col);
			setCell(row, col, oCell);

			pGUI->DrawCell(oCell);


		}

		else if (actxion == ADD_CHERRY)
		{


			CherryCell * cherCell = new CherryCell(row, col);
			setCell(row, col, cherCell);
			pGUI->DrawCell(cherCell);

		}

		else if (actxion == ADD_CHEESE)
		{


			CheeseCell * chesCell = new CheeseCell(row, col);
			setCell(row, col, chesCell);
			pGUI->DrawCell(chesCell);

		}

		else if (actxion == ADD_LIFE)
		{


			LifeCell * gCell = new LifeCell(row, col);
			setCell(row, col, gCell);
			pGUI->DrawCell(gCell);
		}



		else if (actxion == ADD_ENEMYBUSTER)
		{

			EnemyBusterCell * ebCell = new EnemyBusterCell(row, col);
			setCell(row, col, ebCell);
			pGUI->DrawCell(ebCell);

		}


		else if (actxion == ADD_EMPTY)
		{


			EmptyCell* emCell = new EmptyCell(row, col);
			setCell(row, col, emCell);

			pGUI->DrawCell(emCell);

		}

	}

		}
		
//////////////////////////////////////////////////////////////////////////////////


// Runs the application


void Grid::RunModes()
{
	
	while (1)
	{
		if (pGUI->getInterfaceMode() == MODE_MENU)

		{
			ActionType act = GetUserAction();

			if (act == EXIT)
				return;


			ExecuteAction(act);

			addselectedmenuitem(act);
			/*
			if (pGUI->GetUserAction() == START)
			{
				ExecuteAction(START);
				pGUI->setInterfaceMode(MODE_GAME);
				resetplayerposition(player);
				RunModes();
			}
			*/
		}
		if (pGUI->getInterfaceMode() == MODE_GAME)

		{
			ActionType act = GetUserAction();

			if (act == EXIT)
				return;
			/// implement game mode functionalities
			ExecuteAction(act);

			if (player->get_lives() == 0)
			{
				pGUI->PrintMessage(" you have lost all your lives , game over buddy :/ , click exit to exit or start to start another game");
				pGUI->setInterfaceMode(MODE_MENU);
				RunModes();
			}
			if (player->getwin() == true)
			{
				pGUI->PrintMessage("congratulations, you have won, click exit to exit or start to start another game");

				pGUI->setInterfaceMode(MODE_MENU);
              RunModes();
			}
		}
	}
}
void Grid::RunApp()
{
	int row = 7, col=12;
	int rowg = NumRowCells, colg = NumColumnCells;
	PlayerCell* pCell = new PlayerCell(row,col);
	setCell(row,col, pCell);
	player = new Player(*pCell);
	pGUI->DrawCell(pCell);
	GoalCell* ggCell = new GoalCell(rowg-2, colg-2);
	setCell(rowg-2, colg-2, ggCell);
	pGUI->DrawCell(ggCell);
	
	ExecuteAction(GetUserAction());
	RunModes();
	


}

void Grid::resolvecollision(Player * player, Cell * cell)
{
	player->track_health();
	Cell playerpos = player->getPosition();
	int playerrow = playerpos.getRow();
	int playercol = playerpos.getCol();
	int cellrow = cell->getRow();
	int cellcol = cell->getCol();
	cell->ActOn(player);

	string health = std::to_string(player->get_health());
	string score = std::to_string(player->get_score());
	string lives = std::to_string(player->get_lives());

	pGUI->PrintMessage("health= " + health + "  lives =  " + lives + "  score=   " + score);




}


////////////////////////////////////////////////////////////////////////////////////
bool Grid::IsValidCell(int row, int col) const
{
	return (row >= 0 && row < NumRowCells) 
			&& (col >=0 && col < NumColumnCells);
}

void Grid::SaveGrid() const
{
	string FileName;
	pGUI->PrintMessage("Enter the File name, Then press enter");
	cout << "enter file name  ";
	cin >> FileName;
	ofstream SaveFile(FileName.c_str());
	int Total_Number_of_nonEmpty_Cells = 0;
	int Cell_type;

	for (int Row = 0; Row < NumRowCells; Row++)
	{
		for (int Column = 0; Column < NumColumnCells; Column++)
		{
			bool x = GameCells[Row][Column];
			if (x)

			Cell_type = (GameCells[Row][Column])->GetCellType();
			if (Cell_type != 1)
			{
				SaveFile << setw(3) << Cell_type << setw(3) << Row << setw(3) << Column << endl;
				Total_Number_of_nonEmpty_Cells++;
			}

		}
	}
	//going back to the begining of the file
	SaveFile.clear();
	// saving player info
	//order of player info (player row, player column, player lives, health , score)
	SaveFile << player->getPosition().getRow() << endl << player->getPosition().getCol() << endl;
	SaveFile << player->get_lives() << endl << player->get_health() << endl << player->get_score() << endl;
	// saving Total_Number_of_nonEmpty_Cells 
	SaveFile << Total_Number_of_nonEmpty_Cells;
	SaveFile.close();
}

