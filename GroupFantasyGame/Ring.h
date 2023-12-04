#pragma once
#include "Item.h"

/**
 * @class Ring
 *
 * @brief Ring class representing ring items in the game.
 *
 * This class inherits from the Item class and defines properties and
 * methods specific to ring items.
 */
class Ring : public Item {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for the Ring class.
     *
     * Initializes a Ring object with specified values for name, weight,
     * strength bonus, health bonus, and health penalty.
     *
     * @param name The name of the ring.
     * @param weight The weight of the ring.
     * @param hBonus The health bonus provided by the ring.
     * @param sBonus The strength bonus provided by the ring.
     * @param hPenalty The health penalty imposed by the ring.
     */
    Ring(std::string name, int weight, int hBonus, int sBonus, int hPenalty);

    /**
     * @brief Default constructor for the Ring class.
     *
     * Initializes a Ring object with default values.
     */
    Ring();

    // Declare Properties
    int strengthBonus; /**< The strength bonus provided by the ring. */
    int healthBonus; /**< The health bonus provided by the ring. */
    int healthPenalty; /**< The health penalty imposed by the ring. */

    // Declare Functions
    /**
     * @brief Displays information about the ring.
     *
     * This function prints information about the ring, including its name,
     * weight, strength bonus, health bonus, and health penalty.
     */
    void displayInfo();

    /**
     * @brief Returns the item type of the ring.
     *
     * @return A string representing the item type of the ring.
     */
    std::string itemType() override;
};
