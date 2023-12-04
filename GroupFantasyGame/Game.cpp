#pragma once
#include "Game.h"
#include <random>
#include <iostream>
#include <iomanip>

/**
 * @brief Default constructor for the Game class.
 *
 * Initializes a Game object, prompting the user to set the dimensions of
 * the game board and populating it with characters, items, and enemies.
 */
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

/**
 * @brief Runs the game, calling methods to populate the game board and
 * presenting the game options to the player.
 */
void Game::run()
{
	populateGameBoard();
	playerChoice();
	gameOptions();
}

/**
 * @brief Populates the game board with characters, items, and enemies.
 */
void Game::populateGameBoard()
{
	// Using random_device and mt19937 as needed more randomness then rand()
	random_device rd;
	mt19937 gen(rd());

	// Setup of random integers
	uniform_int_distribution<> randomEnemyDist(0, 4);
	uniform_int_distribution<> randomItemTypeDist(0, 3);
	uniform_int_distribution<> randomItemDist(0, 1);

	// two for loops to iterate through a vector of vectors and populate the square objects.
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			// First randomValue to determine if square has weapon or item
			int randomValue = randomItemDist(gen);
			if (randomValue == 0)
			{
				int randomEnemy = randomEnemyDist(gen);
				Square square = Square(characters[randomEnemy]);
				game_board[i][j] = square;
			}
			else if (randomValue == 1)
			{
				// Another random to decide which item type to assign to square
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

/**
 * @brief Moves the player on the game board in the specified direction.
 *
 * @param game_board The game board.
 * @param direction The direction to move the player (N, W, S, or E).
 *
 * @return True if the move is valid, false otherwise.
 */
bool Game::makeMove(vector<vector<Square>>& game_board, char direction)
{
	bool validMove = false;

	// Switch on direction and move through board with some error handling for the board dimensions
	switch (direction)
	{
	case 'N':
		// Check if currentRow == 0 as cannot move to position -1
		if (currentRow == 0)
		{
			cout << "Cannot Move north from this position\n";
		}
		else
		{
			// Adjust the currentRow 
			currentRow--;

			// update valid Move to adjust time of day
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
			// Adjust the currentRow 
			currentRow++;

			// update valid Move to adjust time of day
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
			// Adjust the currentRow 
			currentColumn--;

			// update valid Move to adjust time of day
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
			// Adjust the currentRow 
			currentColumn++;

			// update valid Move to adjust time of day
			validMove = true;
		}
		break;
	}
	return validMove;
}

/**
 * @brief Displays information about the current square on the game board.
 *
 * This function provides details about enemies, items, or an empty square.
 */
void Game::squareInformation(vector<vector<Square>>& game_board)
{

	// Get current square value from game board
	Square currentSquare = game_board[currentRow][currentColumn];

	// Check if current square has an enemy, if it does, display the info
	if (currentSquare.hasEnemy)
	{
		Character currentEnemy = currentSquare.character;
		cout << "This Square has an enemy with race: " << currentEnemy.race << ", attack: " << currentEnemy.attack
			<< ", defense: " << currentEnemy.defence << ", health: " << currentEnemy.health << endl;
	}
	// Check if current square has an item, if it does, display the info
	else if (currentSquare.item != nullptr)
	{
		currentSquare.item->displayInfo();
	}
	else
	{
		cout << "This square is empty" << endl;
	}
}

/**
 * @brief Presents game options to the player and processes their input.
 */
void Game::gameOptions()
{
	bool gameOver = false;
	char userInput;
	do
	{
		cout << "Current Position = (" << currentRow << ", " << currentColumn << ")\n";
		cout << "Enter a command (N, W, S, E) or (A)ttack, (P)ick up, (D)rop, (L)ook, (I)nventroy, E(X)it\n";
		cin >> userInput;
		cout << endl;

		// Switch on user input
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
			gameOver = performAttack(game_board, player);
			updateDayNight(game_board, player);
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
	} while (userInput && !gameOver);
}

/**
 * @brief Allows the player to choose their character.
 */
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

	// Set player based on user input
	player = Player(characters[characterChoice - 1]);
}

/**
 * @brief Performs an attack on an enemy if present on the current square.
 *
 * @param game_board The game board.
 * @param player The player character.
 *
 * @return True if the player is defeated, false otherwise.
 */
bool Game::performAttack(vector<vector<Square>>& game_board, Player& player)
{
	// Get the current square
	Square& currentSquare = game_board[currentRow][currentColumn];

	// if the square has an enemy and it is not already dead
	if (currentSquare.hasEnemy && !(currentSquare.character.health <= 0))
	{
		// We get the current enemy
		Character& currentEnemy = currentSquare.character;

		// the user will perform the first attack, then adjust the health of the enemy
		int damageinc = player.attackMove(currentEnemy, isDay);
		currentEnemy.health -= damageinc;

		if (currentEnemy.health <= 0)
		{
			cout << "Enemy Defeated, you gain 20 gold!" << endl;
			player.gold += 20;
			currentSquare.hasEnemy = false;
			return false;
		}

		// the enemy will then attack, and the players health will be adjusted
		int damage = currentEnemy.attackMove(player, isDay);
		player.health -= damage;

		// Check if the players health is < 0, if it is end the game
		if (player.health <= 0)
		{
			endGame(player);
			return true;
		}

	}
	else
	{
		cout << "Cannot perform attack as no enemy on square or Enemy has already been defeated!" << endl;
	}
	return false;
}

/**
 * @brief Drops an item from the player's inventory onto the current square.
 *
 * @param game_board The game board.
 * @param player The player character.
 */
void Game::drop(vector<vector<Square>>& game_board, Player& player)
{
	// Get user input to drop an item
	int itemIndex;
	cout << "which item do you want to drop ? 1 - " << inventoryCounter << ": ";
	cin >> itemIndex;

	// Handle an incorrect input 
	if (itemIndex >= 0 && itemIndex <= inventoryCounter)
	{
		player.dropItem(itemIndex - 1);
		cout << "you dropped the item" << endl;
		inventoryCounter--;
		player.displayInventory(itemIndex);
	}
	else
	{
		cout << "Item number is out or range" << endl;
	}
}

/**
 * @brief Ends the game, displaying the player's gold.
 *
 * @param player The player character.
 */
void Game::endGame(Player& player)
{
	cout << "Game Over!" << endl;
	cout << "Player's Gold: " << player.gold << endl;
}

/**
 * @brief Updates the time of day in the game and adjusts character stats.
 *
 * This function is called after a certain number of moves.
 */
void Game::updateDayNight(vector<vector<Square>>& game_board, Player& player)
{
	// We update the counter and then check if the day is a multiple of 5
	moveCounter++;
	if (moveCounter % 5 == 0)
	{
		// Negate the isDay flag
		isDay = !isDay;

		// Update the player if they choose an orc
		if (player.race == "Orc")
		{
			player.UpdateEnemyOnTimeOfDay(isDay);
		}

		// Check the game board and update all the orcs on the board
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

/**
 * @brief Allows the player to pick up an item from the current square.
 *
 * @param game_board The game board.
 * @param player The player character.
 */
void Game::pickUp(vector<vector<Square>>& game_board, Player& player)
{
	// Get the current square from the game board
	Square& currentSquare = game_board[currentRow][currentColumn];

	if (!currentSquare.hasEnemy && currentSquare.item != nullptr)
	{
		// Check the item type of the item on the board compare to what's in the players inventory
		if (!currentSquare.item->hasItemType(*player.Inventory) || currentSquare.item->itemType() == "Ring")
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
