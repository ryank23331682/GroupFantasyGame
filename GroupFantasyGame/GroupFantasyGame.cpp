// GroupFantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Authors: Ryan Kelly, Lucas Paval Dommier, Kevin Chesser, Varad Lele, Divya Acharya
// Date: 04.12.2023
//
//

/**
 * @file main.cpp
 * @brief Entry point for the fantasy game.
 */
#include <iostream>
#include "Game.h"
using namespace std;

/**
 * @brief Entry point of the program.
 *
 * This function initializes the game and runs its main loop.
 *
 * @return An integer indicating the exit status of the program.
 */
int main()
{
    // Create a Game object
    Game game = Game();

    // Run the game
    game.run();

    // Return EXIT_SUCCESS to indicate successful program execution
    return EXIT_SUCCESS;
}





