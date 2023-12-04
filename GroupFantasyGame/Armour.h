#pragma once
#include "Item.h"

/**
 * @class Armour
 *
 * Armour class, a subclass of Item, defining armour objects.
 *
 * This class represents armour items in the game. Armour objects have properties
 * such as defenseBonus and attackPenalty, and they inherit from the Item class.
 *
 * @note
 * The defenceBonus represents the bonus to defense points, and attackPenalty
 * represents the penalty to attack points.
 */
class Armour : public Item
{
public:
	// Declare Properties
	int defenseBonus; /**< The bonus to defense points provided by the armour. */
	int attackPenalty; /**< The penalty to attack points imposed by the armour. */

	/**
	   * @brief Constructor for the Armour class.
	   *
	   * @param name The name of the armour.
	   * @param weight The weight of the armour.
	   * @param dBonus The defense bonus provided by the armour.
	   * @param aPenalty The attack penalty imposed by the armour.
	   */
	Armour(std::string name, int weight, int dBonus, int aPenalty);

	/**
	 * @brief Default constructor for the Armour class.
	 *
	 * Initializes the Armour object with default values.
	 */
	Armour();

	/**
	 * @brief Displays information about the armour.
	 *
	 * This function prints information about the armour, including its name,
	 * weight, defense bonus, and attack penalty.
	 */
	void displayInfo();

	/**
	 * @brief Returns the item type of the armour.
	 *
	 * @return A string representing the item type of the armour.
	 */
	string itemType();

private:
};

