#pragma once
#include "Item.h"
#include<string>
#include "Character.h"
#include <vector>
using namespace std;

class Player : public Character {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for the Player class.
     *
     * Initializes a Player object with a specified character.
     *
     * @param c The character used as a base for the player.
     */
    Player(Character c);

    /**
     * @brief Default constructor for the Player class.
     *
     * Initializes a Player object with default values.
     */
    Player();

    // Declare Properties
    std::vector<Item*>* Inventory; /**< Pointer to a vector of Item pointers representing the player's inventory. */
    int gold; /**< The amount of gold owned by the player. */
    int totalWeight; /**< The total weight of items carried by the player. */

    // Declare Functions
    /**
     * @brief Attempts to equip an item to the player.
     *
     * @param item The item to be equipped.
     * @return A boolean indicating whether the item was successfully equipped.
     */
    bool equipItem(const Item& item);

    /**
     * @brief Displays the contents of the player's inventory.
     *
     * @param length The length of the inventory to display.
     */
    void displayInventory(int length);

    /**
     * @brief Drops an item from the player's inventory.
     *
     * @param itemIndex The index of the item to be dropped.
     */
    void dropItem(int itemIndex);

    /**
     * @brief Displays properties specific to the player.
     */
    void displayPlayerProperties();
};