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
    const int MAX_CHARACTERS = 5;
    Weapon weapons[2];
    Armour armours[2];
    Shield shields[2];
    Ring rings[2];
    Character characters[5];
    vector<vector<Square>> game_board;
    Player player;
    int row;
    int column;
    int currentRow = 0;
    int currentColumn = 0;
    int inventoryCounter = 0;
    int moveCounter = 0;
    bool isDay = true;

    void populateGameBoard();
    bool makeMove(std::vector<std::vector<Square>>& game_board, char direction);
    void squareInformation(std::vector<std::vector<Square>>& game_board);
    void gameOptions();
    void playerChoice();
    bool performAttack(std::vector<std::vector<Square>>& game_board, Player& player);
    void drop(std::vector<std::vector<Square>>& game_board, Player& player);
    void endGame(Player& player);
    void updateDayNight(std::vector<std::vector<Square>>& game_board, Player& player);
    void pickUp(std::vector<std::vector<Square>>& game_board, Player& player);
};
#endif 

