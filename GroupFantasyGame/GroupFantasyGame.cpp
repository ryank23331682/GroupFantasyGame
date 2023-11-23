// GroupFantasyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Square.h"
#include "Board.h"
using namespace std;

int ROW;
int COLUMN;
int main()
{

    cout << "Welcome to our fantasy Game!\n";
    cout << "Enter in the rows of the board\n";
    cin >> ROW;
    cout << "Enter in the columns of the board\n";
    cin >> COLUMN;
    //Board gameBoard = Board(ROW, COLUMN);
    Square square = Square();
    vector<vector<Square>> game_board(ROW, vector<Square>(COLUMN, square));

    // Use nested for loops to iterate over the 2D array
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            Square square = Square();
            game_board[i][j] = square; // Access the enemy 
            cout << game_board[i][j].enemy.attack; // Access the enemy 
            cout << game_board[i][j].enemy.defence; // Access the enemy 
        }
    }

    char userInput;



    do {
        cout << "Enter a command (N, W, S, E) or (A)ttack, (P)ick up, (D)rop, (L)ook, (I)nventroy, (Ex)it ";
        cin >> userInput;
        switch (userInput) {
        case 'N':
            // Code for command 'a'
            std::cout << "Command 'a' selected." << std::endl;
            break;

        case 'S':
            // Code for command 'b'
            std::cout << "Command 'b' selected." << std::endl;
            break;

        case 'W':
            // Code for command 'c'
            std::cout << "Command 'c' selected." << std::endl;
            break;

        case 'E':
            // Code for command 'q'
            std::cout << "Exiting the program." << std::endl;
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
            std::cout << "Exiting the program." << std::endl;
            break;

        case 'I':
            // Code for command 'q'
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            // Code for handling invalid input
            std::cout << "Invalid command. Please enter a, b, c, or q." << std::endl;
            break;
        }
    } while (userInput != 'Ex');

    return EXIT_SUCCESS;
    }

    


