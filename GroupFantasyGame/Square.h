#include "Item.h"
#include "Character.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Shield.h" 

/**
 * @class Square
 *
 * @brief Square class representing a square on the game board.
 *
 * This class defines properties and methods for a square on the game board,
 * including constructors for different types of squares and functions for
 * displaying information about the square and retrieving its item.
 */
class Square {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for a Square with a character.
     *
     * Initializes a Square object with a character.
     *
     * @param c The character to be placed on the square.
     */
    Square(Character c);

    /**
     * @brief Parameterized constructor for a Square with a weapon.
     *
     * Initializes a Square object with a weapon.
     *
     * @param w The weapon to be placed on the square.
     */
    Square(Weapon w);

    /**
     * @brief Parameterized constructor for a Square with an armour.
     *
     * Initializes a Square object with an armour.
     *
     * @param a The armour to be placed on the square.
     */
    Square(Armour a);

    /**
     * @brief Parameterized constructor for a Square with a shield.
     *
     * Initializes a Square object with a shield.
     *
     * @param s The shield to be placed on the square.
     */
    Square(Shield s);

    /**
     * @brief Parameterized constructor for a Square with a ring.
     *
     * Initializes a Square object with a ring.
     *
     * @param r The ring to be placed on the square.
     */
    Square(Ring r);

    /**
     * @brief Default constructor for the Square class.
     *
     * Initializes a Square object with default values.
     */
    Square();

    // Declare Properties
    Item* item; /**< Pointer to an item on the square. */
    bool hasEnemy; /**< Flag indicating whether the square has an enemy. */
    Character character; /**< The character on the square. */

    // Declare Functions
    /**
     * @brief Displays information about the square.
     *
     * This function prints information about the square, including its item,
     * whether it has an enemy, and the character on the square.
     */
    void displayInfo();

    /**
     * @brief Returns the item on the square.
     *
     * @return A pointer to the item on the square.
     */
    Item* getItem() const;

private:

};
