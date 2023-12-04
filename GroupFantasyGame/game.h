#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Game.h"
#include "Square.h"
/**
 * @class Game
 *
 * @brief Game class representing the main game logic and state.
 *
 * This class encapsulates the game logic, including player interactions,
 * game board management, and other game-related functionalities.
 */
class Game
{
public:
    // Default constructor and public Method(s)
    /**
     * @brief Default constructor for the Game class.
     *
     * Initializes a Game object, setting up the game board and other initial conditions.
     */
    Game();

    /**
     * @brief Runs the game, handling game flow and player interactions.
     */
    void run();

private:
    //Declare Properties
    const int MAX_CHARACTERS = 5; /**< The maximum number of characters in the game. */
    Weapon weapons[2]; /**< Array storing weapon objects. */
    Armour armours[2]; /**< Array storing armour objects. */
    Shield shields[2]; /**< Array storing shield objects. */
    Ring rings[2]; /**< Array storing ring objects. */
    Character characters[5]; /**< Array storing character objects. */
    std::vector<std::vector<Square>> game_board; /**< 2D vector representing the game board. */
    Player player; /**< The player object representing the user. */
    int row; /**< The number of rows in the game board. */
    int column; /**< The number of columns in the game board. */
    int currentRow = 0; /**< The current row position of the player. */
    int currentColumn = 0; /**< The current column position of the player. */
    int inventoryCounter = 0; /**< Counter for the number of items in the player's inventory. */
    int moveCounter = 0; /**< Counter for the number of moves made by the player. */
    bool isDay = true; /**< Flag indicating whether it is day or night in the game. */

    //Declare Functions
    /**
     * @brief Populates the game board with squares and initializes other game-related entities.
     */
    void populateGameBoard();

    /**
     * @brief Makes a move on the game board based on the specified direction.
     *
     * @param game_board The 2D vector representing the game board.
     * @param direction The direction of the move (e.g., 'U' for up, 'D' for down).
     * @return A boolean indicating whether the move was successful.
     */
    bool makeMove(std::vector<std::vector<Square>>& game_board, char direction);

    /**
     * @brief Displays information about the current square on the game board.
     *
     * @param game_board The 2D vector representing the game board.
     */
    void squareInformation(std::vector<std::vector<Square>>& game_board);

    /**
     * @brief Displays available game options for the player.
     */
    void gameOptions();

    /**
     * @brief Handles the player's choice and performs the corresponding action.
     */
    void playerChoice();

    /**
     * @brief Performs an attack action on the game board.
     *
     * @param game_board The 2D vector representing the game board.
     * @param player The player object performing the attack.
     * @return A boolean indicating whether the attack was successful.
     */
    bool performAttack(std::vector<std::vector<Square>>& game_board, Player& player);

    /**
     * @brief Drops an item from the player's inventory onto the game board.
     *
     * @param game_board The 2D vector representing the game board.
     * @param player The player object dropping the item.
     */
    void drop(std::vector<std::vector<Square>>& game_board, Player& player);

    /**
     * @brief Ends the game, displaying the final result for the player.
     *
     * @param player The player object representing the user.
     */
    void endGame(Player& player);

    /**
     * @brief Updates the day-night cycle in the game.
     *
     * @param game_board The 2D vector representing the game board.
     * @param player The player object representing the user.
     */
    void updateDayNight(std::vector<std::vector<Square>>& game_board, Player& player);

    /**
     * @brief Allows the player to pick up an item from the game board.
     *
     * @param game_board The 2D vector representing the game board.
     * @param player The player object picking up the item.
     */
    void pickUp(std::vector<std::vector<Square>>& game_board, Player& player);
};

#endif
