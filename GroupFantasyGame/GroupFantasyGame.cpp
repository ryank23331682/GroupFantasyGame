// GroupFantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Board.h"
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"
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
	/*Player player("Player", 100, 70, 30);
	Enemy enemy("Dragon", 150, 50, 20, 10);

	while (player.health > 0 && enemy.health > 0) {
		if (player.attack(enemy, 20)) {
			std::cout << "Player successfully attacked enemy!\n";
			if (enemy.health <= 0) {
				std::cout << "Enemy defeated! Gold collected: " << enemy.defenseValue << "\n";
				player.gold += enemy.defenseValue;
			}
		}
		else {
			std::cout << "Player's attack failed!\n";
		}

		if (enemy.health > 0 && enemy.attack(player, 15)) {
			std::cout << "Enemy successfully attacked player!\n";
		}
		else {
			std::cout << "Enemy's attack failed!\n";
		}

		std::cout << "Player Health: " << player.health << " Gold: " << player.gold << "\n";
		std::cout << "Enemy Health: " << enemy.health << "\n\n";
	}

	std::cout << "Game Over. Gold collected: " << player.gold << "\n";

	return 0;*/

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

	Enemy enemies[5] = {
		Enemy("Human", 30, 20, 60, 100, 0.50, 0.67),
		Enemy("Elf", 40, 10, 40, 70, 0.25, 1.00),
		Enemy("Dwarf", 30, 20, 50, 130, 0.33, 0.67),
		Enemy("Hobbit", 25, 20, 70, 85, 0.67, 0.33),
		Enemy("Orc", 25, 10, 50, 130, 0.25, 0.25),
	};
	Weapon weapons[2] = {
		Weapon("Sword", 10, 10),
		Weapon("Dagger", 5, 5)
	};
	Armour armours[2] = {
		Armour("Plate Armour", 40, 10, 5),
		Armour("Leather Armour", 20, 0, 5),
	};
	Shield shields[2] = { 
		Shield("Large Shield", 30, 10, 5),
		Shield("Small Shield", 10, 5, 0),
	};
	Ring rings[2] = {
	Ring("Ring of Life", 1, 10, 0, 0),
	Ring("Ring of Strength", 1, 0, 50, 10),
	};

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			int randomValue = rand() % 2;
			if (randomValue == 0) {
				int randomEnemy = rand() % 5;
				Square square = Square(enemies[randomEnemy]);
				game_board[i][j] = square;
			}
			else 
			{
				int randomItemType = rand() % 4;
				int randomItem = rand() % 2;
				switch (randomItemType) {
				case 0:
					game_board[i][j] = Square(weapons[randomItem]);
					break;

				case 1:
					game_board[i][j] = Square(armours[randomItem]);
					break;

				case 2:
					game_board[i][j] = Square(shields[randomItem]);
					break;

				case 3:
					game_board[i][j] = Square(rings[randomItem]);
					break;
				}
			}
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
		if (CURRENTROW == ROW -1)
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
		if (CURRENTCOLUMN == COLUMN -1)
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
		if (currentSquare.hasArmour) 
		{
			currentSquare.armour.displayInfo();
		} 
		else if (currentSquare.hasWeapon)
		{
			currentSquare.weapon.displayInfo();
		}
		else if (currentSquare.hasRing)
		{
			currentSquare.ring.displayInfo();
		}
		else if (currentSquare.hasShield)
		{
			currentSquare.shield.displayInfo();
		}

	}

}


