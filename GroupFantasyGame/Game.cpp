#pragma once
#include "Game.h"
#include <random>
#include <iostream>
#include <iomanip>

Game::Game()
{
	cout << "Welcome to our fantasy Game!\n";
	cout << "Enter in the rows of the board\n";
	cin >> row;
	cout << "Enter in the columns of the board\n";
	cin >> column;
	game_board = vector<vector<Square>>(row, vector<Square>(column));

	weapons[0] = Weapon("Sword", 10, 10);
	weapons[1] = Weapon("Dagger", 5, 5);

	armours[0] = Armour("Plate Armour", 40, 10, 5);
	armours[1] = Armour("Leather Armour", 20, 0, 5);

	shields[0] = Shield("Large Shield", 30, 10, 5);
	shields[1] = Shield("Small Shield", 10, 5, 0),

	rings[0] = Ring("Ring of Life", 1, 10, 0, 0);
	rings[1] = Ring("Ring of Strength", 1, 0, 50, 10);

	characters[0] = Character("Human", 30, 20, 60, 100, 0.50, 0.67);
	characters[1] = Character("Elf", 40, 10, 40, 70, 0.25, 1.00);
	characters[2] = Character("Dwarf", 30, 20, 50, 130, 0.33, 0.67);
	characters[3] = Character("Hobbit", 25, 20, 70, 85, 0.67, 0.33);
	characters[4] = Character("Orc", 25, 10, 50, 130, 0.25, 0.25);
}

void Game::run()
{
	populateGameBoard();
	playerChoice();
	gameOptions();
}

void Game::populateGameBoard() 
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> randomEnemyDist(0, 4);
	uniform_int_distribution<> randomItemTypeDist(0, 3);
	uniform_int_distribution<> randomItemDist(0, 1);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			int randomValue = randomItemDist(gen);
			if (randomValue == 0) 
			{
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

bool Game::makeMove(vector<vector<Square>>& game_board, char direction)
{
	bool validMove = false;
	switch (direction) 
	{
		case 'N':
			if (currentRow == 0)
			{
				cout << "Cannot Move north from this position\n";
			}
			else
			{
				currentRow--;
				validMove = true;
			}
			break;

		case 'S':
			if (currentRow == row - 1)
			{
				cout << "Cannot Move south from this position\n";
			}
			else
			{
				currentRow++;
				validMove = true;
			}
			break;

		case 'W':
			if (currentColumn == 0)
			{
				cout << "Cannot Move West from this position\n";
			}
			else
			{
				currentColumn--;
				validMove = true;
			}
			break;
		case 'E':
			if (currentColumn == column - 1)
			{
				cout << "Cannot Move East from this position\n";
			}
			else
			{
				currentColumn++;
				validMove = true;
			}
			break;
	}
	return validMove;
}

void Game::squareInformation(vector<vector<Square>>& game_board)
{
	Square currentSquare = game_board[currentRow][currentColumn];

	if (currentSquare.hasEnemy)
	{
		Character currentEnemy = currentSquare.character;
		cout << "This Square has an enemy with race: " << currentEnemy.race << ", attack: " << currentEnemy.attack
			<< ", defense: " << currentEnemy.defence << ", health: " << currentEnemy.health << endl;
	}
	else if (currentSquare.item != nullptr)
	{
		currentSquare.item->displayInfo();
	}
	else
	{
		cout << "This square is empty" << endl;
	}
}

void Game::gameOptions()
{
	char userInput;
	do 
	{
		cout << "Current Position = (" << currentRow << ", " << currentColumn << ")\n";
		cout << "Enter a command (N, W, S, E) or (A)ttack, (P)ick up, (D)rop, (L)ook, (I)nventroy, (Ex)it\n";
		cin >> userInput;
		cout << endl;
		switch (userInput) 
		{
			case 'N':
			case 'S':
			case 'W':
			case 'E':
				if (makeMove(game_board, userInput))
				{
					updateDayNight(game_board, player);
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
				squareInformation(game_board);
				break;

			case 'I':
				player.displayInventory(inventoryCounter);
				break;

			case 'X':
				exit(0);

			default:
				std::cout << "Invalid command. Please enter a, b, c, or q." << std::endl;
				break;
		}
	} while (userInput);
}

void Game::playerChoice()
{
	int characterChoice;

	// Print header
	std::cout << setw(10) << "Race" << std::setw(10) << "Attack" << std::setw(10) << "Defense"
		<< std::setw(10) << "Health" << std::setw(10) << "Strength" << std::setw(15) << "Def. Chance"
		<< std::setw(15) << "Att. Chance" << std::endl;

	for (const Character& character : characters)
	{
		// Print character details in a table format
		std::cout << std::setw(10) << character.race << std::setw(10) << character.attack
			<< std::setw(10) << character.defence << std::setw(10) << character.health
			<< std::setw(10) << character.strength << std::setw(15) << character.defenseChance
			<< std::setw(15) << character.attackChance << std::endl;
	}

	std::cout << "Choose your character (1-5): ";
	std::cin >> characterChoice;

	player = Player(characters[characterChoice - 1]);
}

bool Game::performAttack(vector<vector<Square>>& game_board, Player& player)
{
	Square& currentSquare = game_board[currentRow][currentColumn];

	if (currentSquare.hasEnemy && !(currentSquare.character.health <= 0))
	{
		Character& currentEnemy = currentSquare.character;
		currentEnemy.health -= player.attackMove(currentEnemy);
		player.health -= currentEnemy.attackMove(player);
		if (player.health <= 0)
		{
			return true;
			endGame(player);
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
	return false;
}

void Game::drop(vector<vector<Square>>& game_board, Player& player)
{
	int itemIndex;
	cout << "which item do you want to drop ? 1 / 2/ 3 /4 /5";
	cin >> itemIndex;
	player.displayInventory(itemIndex);
	player.dropItem(itemIndex - 1);
	cout << "you erased an item";
	inventoryCounter--;
	player.displayInventory(inventoryCounter);
}

void Game::endGame(Player& player)
{
	cout << "Game Over!" << endl;
	cout << "Player's Gold: " << player.gold << endl;
}

void Game::updateDayNight(vector<vector<Square>>& game_board, Player& player)
{
	moveCounter++;
	if (moveCounter % 5 == 0)
	{
		isDay = !isDay;
		if (player.race == "Orc")
		{
			player.UpdateEnemyOnTimeOfDay(isDay);
		}
		list<Character> enemies;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if (game_board[i][j].hasEnemy && game_board[i][j].character.race == "Orc")
				{
					game_board[i][j].character.UpdateEnemyOnTimeOfDay(isDay);
				}
			}
		}
	}
}

void Game::pickUp(vector<vector<Square>>& game_board, Player& player)
{
	Square& currentSquare = game_board[currentRow][currentColumn];
	bool alreadyHasItem = currentSquare.item->hasItemType(*player.Inventory);
	if (!currentSquare.hasEnemy && currentSquare.item != nullptr)
	{
		if (!alreadyHasItem)
		{
			player.equipItem(*(currentSquare.getItem()));
			game_board[currentRow][currentColumn].item = nullptr;
			inventoryCounter++;
		}
		else
		{
			cout << "You already have this Item type in you're inventory!" << endl;
		}
	}
	else
	{
		cout << "No Item to pick up" << endl;
	}
}
