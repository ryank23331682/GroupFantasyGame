// GroupFantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> 
#include <vector>
#include <string>
#include <random>
#include "Square.h"
#include "Board.h"
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"
#include "Player.h"
using namespace std;

void PopulateGameBoard(vector<vector<Square>>& game_board);
bool MakeMove(vector<vector<Square>>& game_board, char direction);
void SquareInformation(vector<vector<Square>>& game_board);
void GameOptions(vector<vector<Square>> game_board, Player player);
void performAttack(vector<vector<Square>>& game_board, Player& player);
void pickUp(vector<vector<Square>>& game_board, Player& player);
void drop(vector<vector<Square>>& game_board, Player& player);
void EndGame(Player& player);
void UpdateDayNight(vector<vector<Square>>& game_board, Player& player);
//bool hasItemType(const Item& item, const vector<Item>& Inventory);
Player PlayerChoice();


int ROW;
int COLUMN;
int CURRENTROW = 0;
int CURRENTCOLUMN = 0;
bool ISDAY = true;
int MOVECOUNTER = 0;
int InventoryCounter = 0;
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

	GameOptions(game_board, player);

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
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> randomEnemyDist(0, 4);
	uniform_int_distribution<> randomItemTypeDist(0, 3);
	uniform_int_distribution<> randomItemDist(0, 1);

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			int randomValue = randomItemDist(gen);
			if (randomValue == 0) {
				int randomEnemy = randomEnemyDist(gen);
				Square square = Square(characters[randomEnemy]);
				game_board[i][j] = square;
			}
			else
			{
				int randomItemType = randomItemTypeDist(gen);
				int randomItem = randomItemDist(gen);
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

static bool MakeMove(vector<vector<Square>>& game_board, char direction) {
	bool validMove = false;
	switch (direction) {
	case 'N':
		if (CURRENTROW == 0)
		{
			cout << "Cannot Move north from this position\n";
		}
		else
		{
			CURRENTROW--;
			validMove = true;
		}
		break;

	case 'S':
		if (CURRENTROW == ROW - 1)
		{
			cout << "Cannot Move south from this position\n";
		}
		else
		{
			CURRENTROW++;
			validMove = true;
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
			validMove = true;
		}
		break;

	case 'E':
		if (CURRENTCOLUMN == COLUMN - 1)
		{
			cout << "Cannot Move East from this position\n";
		}
		else
		{
			CURRENTCOLUMN++;
			validMove = true;
		}
		break;
	}
	return validMove;
}

static void SquareInformation(vector<vector<Square>>& game_board) {
	Square currentSquare = game_board[CURRENTROW][CURRENTCOLUMN];

	if (currentSquare.hasEnemy)
	{
		Character currentEnemy = currentSquare.character;
		cout << "This Square has an enemy with race: " << currentEnemy.race << ", attack: " << currentEnemy.attack
			<< ", defense: " << currentEnemy.defence << ", health: " << currentEnemy.health << endl;
	}
	else if(currentSquare.item != nullptr)
	{
		currentSquare.item->displayInfo();
	}
	else
	{
		cout << "This square is empty" << endl;
	}
}

void GameOptions(vector<vector<Square>> game_board, Player player)
{
	char userInput;

	do {
		cout << "Current Position = (" << CURRENTROW << ", " << CURRENTCOLUMN << ")\n";
		cout << "Enter a command (N, W, S, E) or (A)ttack, (P)ick up, (D)rop, (L)ook, (I)nventroy, (Ex)it\n";
		cin >> userInput;
		cout << endl;
		switch (userInput) {
		case 'N':
		case 'S':
		case 'W':
		case 'E':
			if(MakeMove(game_board, userInput))
			{
				UpdateDayNight(game_board, player);
			}
			break;
		case 'A':
			performAttack(game_board, player);
			break;

		case 'P':
			pickUp(game_board, player);
			break;

		case 'D':
			drop(game_board, player);
			break;

		case 'L':
			SquareInformation(game_board);
			break;

		case 'I':
			player.displayInventory(InventoryCounter);
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

void performAttack(vector<vector<Square>>& game_board, Player& player)
{
	Square& currentSquare = game_board[CURRENTROW][CURRENTCOLUMN];

	if (currentSquare.hasEnemy && !(currentSquare.character.health <= 0))
	{
		Character& currentEnemy = currentSquare.character;
		currentEnemy.health -= player.attackMove(currentEnemy);
		player.health -= currentEnemy.attackMove(player);
		if (player.health <= 0) 
		{
			EndGame(player);
		}
		else if (currentEnemy.health <= 0) 
		{
			cout << "Enemy Defeated, you gain 20 gold!" << endl;
			player.gold += 20;
		}
	}
	else
	{
		cout << "Cannot perform attack as no enemy on square or Enemy has already been defeated!" << endl;
	}
}

void drop(vector<vector<Square>>& game_board, Player& player)
{
	int itemIndex;
	cout << "which item do you want to drop ? 1 / 2/ 3 /4 /5";
	cin >> itemIndex;
	player.displayInventory(itemIndex);
	player.dropItem(itemIndex - 1);
	cout << "you erased an item";
	InventoryCounter--;
	player.displayInventory( InventoryCounter);
}

void EndGame(Player& player)
{
	cout << "Game Over!" << endl;
	cout << "Player's Gold: " << player.gold << endl;
}

Player PlayerChoice()
{
	int characterChoice;

	// Print header
	std::cout << setw(10) << "Race" << std::setw(10) << "Attack" << std::setw(10) << "Defense"
		<< std::setw(10) << "Health" << std::setw(10) << "Strength" << std::setw(15) << "Def. Chance"
		<< std::setw(15) << "Att. Chance" << std::endl;

	for (const Character& character : characters) {
		// Print character details in a table format
		std::cout << std::setw(10) << character.race << std::setw(10) << character.attack
			<< std::setw(10) << character.defence << std::setw(10) << character.health
			<< std::setw(10) << character.strength << std::setw(15) << character.defenseChance
			<< std::setw(15) << character.attackChance << std::endl;
	}

	std::cout << "Choose your character (1-5): ";
	std::cin >> characterChoice;

	return Player(characters[characterChoice - 1]);
}

static void UpdateDayNight(vector<vector<Square>>& game_board, Player& player) {

	MOVECOUNTER++;
	if (MOVECOUNTER % 5 == 0) {
		ISDAY = !ISDAY;
		if (player.race == "Orc")
		{
			player.UpdateEnemyOnTimeOfDay(ISDAY);
		}
		list<Character> enemies;
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				if (game_board[i][j].hasEnemy && game_board[i][j].character.race == "Orc")
				{
					game_board[i][j].character.UpdateEnemyOnTimeOfDay(ISDAY);
				}
			}
		}
	}
}

static void pickUp(vector<vector<Square>>& game_board, Player& player) {
	Square& currentSquare = game_board[CURRENTROW][CURRENTCOLUMN];

	if (!currentSquare.hasEnemy && currentSquare.item != nullptr) 
	{
		player.equipItem(*(currentSquare.getItem()));
		game_board[CURRENTROW][CURRENTCOLUMN].item = nullptr;  
		InventoryCounter++;
	}
}

bool hasItemType(const Item& item, const vector<Item>& Inventory) {
	//for (const auto& inventoryItem : Inventory) {

	//	if (derivedItem != nullptr && derivedItemOfItem != nullptr && *derivedItem == *derivedItemOfItem) {
	//		// Item of the same type found in the inventory
	//		return true;
	//	}
	//}
	// Item type not found in the inventory
	return false;
}




