#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Game.h"
#include "Square.h"
class Game
{
public:

	Game();
	void run();

private:
	Weapon weapons[2];
	Armour armours[2];
	Shield shields[2];
	Ring rings[2];
	const int MAX_CHARACTERS = 5;
	int ROW;
	int COLUMN;
	int CURRENTROW = 0;
	int CURRENTCOLUMN = 0;
	int InventoryCounter = 0;
	Character characters[5];
	int MOVECOUNTER = 0;
	bool ISDAY = true;
	vector<vector<Square>> game_board;
	Player player;
	void populateGameBoard();
	bool MakeMove(vector<vector<Square>>& game_board, char direction);
	void SquareInformation(vector<vector<Square>>& game_board);
	void GameOptions();
	void PlayerChoice();
	bool performAttack(vector<vector<Square>>& game_board, Player& player);
	void drop(vector<vector<Square>>& game_board, Player& player);
	void EndGame(Player& player);
	void UpdateDayNight(vector<vector<Square>>& game_board, Player& player);
	void pickUp(vector<vector<Square>>& game_board, Player& player);

};
#endif 

