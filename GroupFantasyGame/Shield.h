#pragma once
#include "Item.h"

/**
 * @class Shield
 *
 * @brief Shield class representing shield items in the game.
 *
 * This class inherits from the Item class and defines properties and
 * methods specific to shield items.
 */
class Shield : public Item {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for the Shield class.
     *
     * Initializes a Shield object with specified values for name, weight,
     * defense bonus, and attack penalty.
     *
     * @param name The name of the shield.
     * @param weight The weight of the shield.
     * @param dBonus The defense bonus provided by the shield.
     * @param aPenalty The attack penalty imposed by the shield.
     */
    Shield(std::string name, int weight, int dBonus, int aPenalty);

    /**
     * @brief Default constructor for the Shield class.
     *
     * Initializes a Shield object with default values.
     */
    Shield();

    // Declare Properties
    int defenseBonus; /**< The defense bonus provided by the shield. */
    int attackPenalty; /**< The attack penalty imposed by the shield. */

    // Declare Functions
    /**
     * @brief Displays information about the shield.
     *
     * This function prints information about the shield, including its name,
     * weight, defense bonus, and attack penalty.
     */
    void displayInfo();

    /**
     * @brief Returns the item type of the shield.
     *
     * @return A string representing the item type of the shield.
     */
    std::string itemType() override;
};

