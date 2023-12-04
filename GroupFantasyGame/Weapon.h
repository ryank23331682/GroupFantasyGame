#pragma once
#include "Item.h"
/**
 * @class Weapon
 *
 * @brief Weapon class representing weapon items in the game.
 *
 * This class inherits from the Item class and defines properties and
 * methods specific to weapon items.
 */
class Weapon : public Item {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for the Weapon class.
     *
     * Initializes a Weapon object with specified values for name, weight,
     * and attack bonus.
     *
     * @param name The name of the weapon.
     * @param weight The weight of the weapon.
     * @param attackBonus The attack bonus provided by the weapon.
     */
    Weapon(std::string name, int weight, int attackBonus);

    /**
     * @brief Default constructor for the Weapon class.
     *
     * Initializes a Weapon object with default values.
     */
    Weapon();

    // Declare Properties
    int attackBonus; /**< The attack bonus provided by the weapon. */

    // Declare Functions
    /**
     * @brief Displays information about the weapon.
     *
     * This function prints information about the weapon, including its name,
     * weight, and attack bonus.
     */
    void displayInfo();

    /**
     * @brief Returns the item type of the weapon.
     *
     * @return A string representing the item type of the weapon.
     */
    std::string itemType() override;
};

