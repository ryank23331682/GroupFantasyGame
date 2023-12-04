#include "Item.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Square.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * @brief Parameterized constructor for the Square class with a Character.
 *
 * Initializes a Square object with the provided Character.
 *
 * @param c The Character for the Square.
 */
Square::Square(Character c) : item(nullptr), hasEnemy(true), character(c)
{

}

/**
 * @brief Parameterized constructor for the Square class with a Weapon.
 *
 * Initializes a Square object with the provided Weapon.
 *
 * @param w The Weapon for the Square.
 */
Square::Square(Weapon w) : item(new Weapon(w)), hasEnemy(false)
{

}

/**
 * @brief Parameterized constructor for the Square class with an Armour.
 *
 * Initializes a Square object with the provided Armour.
 *
 * @param a The Armour for the Square.
 */
Square::Square(Armour a) : item(new Armour(a)), hasEnemy(false)
{

}

/**
 * @brief Parameterized constructor for the Square class with a Shield.
 *
 * Initializes a Square object with the provided Shield.
 *
 * @param s The Shield for the Square.
 */
Square::Square(Shield s) : item(new Shield(s)), hasEnemy(false)
{

}

/**
 * @brief Parameterized constructor for the Square class with a Ring.
 *
 * Initializes a Square object with the provided Ring.
 *
 * @param r The Ring for the Square.
 */
Square::Square(Ring r) : item(new Ring(r)), hasEnemy(false)
{

}

/**
 * @brief Default constructor for the Square class.
 *
 * Initializes a Square object with default values.
 */
Square::Square() : item(nullptr), hasEnemy(false)
{

}

/**
 * @brief Displays information about the square.
 *
 * Outputs details about the square, including enemy information or item details.
 */
void Square::displayInfo()
{
    if (hasEnemy)
    {
        cout << "This Square has an enemy with race: " << character.race
            << ", attack: " << character.attack << ", defense: "
            << character.defence << ", health: " << character.health << endl;
    }
    else if (item != nullptr)
    {
        item->displayInfo();
    }
    else
    {
        cout << "This square is empty" << endl;
    }
}

/**
 * @brief Gets the item in the square.
 *
 * Returns a pointer to the item in the square.
 *
 * @return The item in the square.
 */
Item* Square::getItem() const
{
    return item;
}
