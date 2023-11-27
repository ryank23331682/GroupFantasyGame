// GroupFantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Board.h"
using namespace std;

void InitialiseGameBoard(vector<vector<Square>>& game_board);
void MakeMove(vector<vector<Square>>& game_board, char direction);
void SquareInformation(vector<vector<Square>>& game_board);
int ROW;
int COLUMN;
int CURRENTROW = 0;
int CURRENTCOLUMN = 0;
int main()
{

	cout << "Welcome to our fantasy Game!\n";
	cout << "Enter in the rows of the board\n";
	cin >> ROW;
	cout << "Enter in the columns of the board\n";
	cin >> COLUMN;

	srand(static_cast<unsigned>(std::time(nullptr)));
	vector<vector<Square>> game_board(ROW, vector<Square>(COLUMN));
	InitialiseGameBoard(game_board);

	char userInput;

	do {
		cout << "Current Position = (" << CURRENTROW << ", " << CURRENTCOLUMN << ")\n";
		cout << "Enter a command (N, W, S, E) or (A)ttack, (P)ick up, (D)rop, (L)ook, (I)nventroy, (Ex)it\n";
		cin >> userInput;
		switch (userInput) {
		case 'N':
		case 'S':
		case 'W':
		case 'E':
			MakeMove(game_board, userInput);
			break;
		case 'A':
			// Code for command 'q'
			std::cout << "Exiting the program." << std::endl;
			break;

		case 'P':
			// Code for command 'q'
			std::cout << "Exiting the program." << std::endl;
			break;

		case 'D':
			// Code for command 'q'
			std::cout << "Exiting the program." << std::endl;
			break;

		case 'L':
			// Code for command 'q'
			SquareInformation(game_board);
			break;

		case 'I':
			// Code for command 'q'
			std::cout << "Exiting the program." << std::endl;
			break;

		case 'X':
			exit(0);

		default:
			// Code for handling invalid input
			std::cout << "Invalid command. Please enter a, b, c, or q." << std::endl;
			break;
		}
	} while (userInput);

	return EXIT_SUCCESS;
}

static void InitialiseGameBoard(vector<vector<Square>>& game_board) {

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			int randomValue = rand() % 2;
			Square square = Square(randomValue);
			game_board[i][j] = square;
		}
	}
}

static void MakeMove(vector<vector<Square>>& game_board, char direction) {
	switch (direction) {
	case 'N':
		if (CURRENTROW == 0)
		{
			cout << "Cannot Move north from this position\n";
		}
		else
		{
			CURRENTROW--;
		}
		break;

	case 'S':
		if (CURRENTROW == ROW)
		{
			cout << "Cannot Move south from this position\n";
		}
		else
		{
			CURRENTROW++;
		}
		break;

	case 'W':
		if (CURRENTCOLUMN == 0)
		{
			cout << "Cannot Move West from this position\n";
		}
		else
		{
			CURRENTCOLUMN--;
		}
		break;

	case 'E':
		if (CURRENTCOLUMN == COLUMN)
		{
			cout << "Cannot Move East from this position\n";
		}
		else
		{
			CURRENTCOLUMN++;
		}
		break;
	}
}

static void SquareInformation(vector<vector<Square>>& game_board) {
	Square currentSquare = game_board[CURRENTROW][CURRENTCOLUMN];
	
	if (currentSquare.hasEnemy)
	{
		Enemy currentEnemy = currentSquare.enemy;
		cout << "This Square has an enemy with race: " << currentEnemy.race << ", attack: " << currentEnemy.attack
			<< ", defense: " << currentEnemy.defence << ", health: " << currentEnemy.health << endl;
	}
	if (currentSquare.hasItem)
	{
		Item currentItem = currentSquare.item;
		cout << "This Square has an : " << currentItem.name << ", weight: " << currentItem.weight
			<< ", attack: " << currentItem.attackValue << ", defence: " << currentItem.defenseVaue << endl;

	}
	
}


