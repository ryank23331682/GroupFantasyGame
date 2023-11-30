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
#include "Player.h"
using namespace std;

void PopulateGameBoard(vector<vector<Square>>& game_board);
void MakeMove(vector<vector<Square>>& game_board, char direction);
void SquareInformation(vector<vector<Square>>& game_board);
void GameOptions(vector<vector<Square>> game_board);
Player PlayerChoice();

int ROW;
int COLUMN;
int CURRENTROW = 0;
int CURRENTCOLUMN = 0;
bool ISDAY = true;
int MOVECOUNTER = 0;
Character characters[5] = {
	Character("Human", 30, 20, 60, 100, 0.50, 0.67),
	Character("Elf", 40, 10, 40, 70, 0.25, 1.00),
	Character("Dwarf", 30, 20, 50, 130, 0.33, 0.67),
	Character("Hobbit", 25, 20, 70, 85, 0.67, 0.33),
	Character("Orc", 25, 10, 50, 130, 0.25, 0.25),
};
int main()
{
	cout << "Welcome to our fantasy Game!\n";
	cout << "Enter in the rows of the board\n";
	cin >> ROW;
	cout << "Enter in the columns of the board\n";
	cin >> COLUMN;
	vector<vector<Square>> game_board(ROW, vector<Square>(COLUMN));
	PopulateGameBoard(game_board);

	Player player = PlayerChoice();

	int InventoryCounter = 1;
	player.equipItem(Weapon("Sword", 10, 10));
	player.displayInventory(player.Inventory, InventoryCounter);

	GameOptions(game_board);

	return EXIT_SUCCESS;
}

static void PopulateGameBoard(vector<vector<Square>>& game_board) {

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
				Square square = Square(characters[randomEnemy]);
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
		Character currentEnemy = currentSquare.character;
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

void GameOptions(vector<vector<Square>> game_board)
{
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
}

Player PlayerChoice()
{
	int characterChoice;

	for (Character character : characters) {
		cout << "Race: " << character.race << "\n";
		cout << "Attack: " << character.attack << "\n";
		cout << "Defense: " << character.defence << "\n";
		cout << "Health: " << character.health << "\n";
		cout << "Strength: " << character.strength << "\n";
		cout << "Defense Chance: " << character.defenseChance << "\n";
		cout << "Attack Chance: " << character.attackChance << "\n\n";
	}
	cout << "Choose youre character (1-5): ";
	cin >> characterChoice;
	return Player(characters[characterChoice - 1]);
}

static void UpdateDayNight(vector<vector<Square>>& game_board) {

	MOVECOUNTER++;
	if (MOVECOUNTER % 5 == 0) {
		ISDAY = !ISDAY;
	}

	if (!ISDAY)
	{
		list<Character> enemies;
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				if (game_board[ROW][COLUMN].hasEnemy && game_board[ROW][COLUMN].character.race == "Orc") 
				{
					game_board[ROW][COLUMN].character.UpdateEnemyOnTimeOfDay(game_board[ROW][COLUMN].character);
				}
			}
		}

	}
}




