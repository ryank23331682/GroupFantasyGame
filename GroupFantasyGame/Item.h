#pragma once
#include<string>
#include <vector>
using namespace std;
/**
 * @class Item
 *
 * @brief Item class representing items in the game.
 *
 * This class defines the properties and methods for items in the game,
 * including constructors, properties such as name and weight, and virtual methods.
 */
class Item {
public:
    // Constructors
    /**
     * @brief Parameterized constructor for the Item class.
     *
     * Initializes an Item object with specified values for name and weight.
     *
     * @param n The name of the item.
     * @param w The weight of the item.
     */
    Item(std::string n, int w);

    /**
     * @brief Default constructor for the Item class.
     *
     * Initializes an Item object with default values.
     */
    Item();

    // Declare Properties
    std::string name; /**< The name of the item. */
    int weight; /**< The weight of the item. */

    // Declare Functions
    /**
     * @brief Virtual destructor for the Item class.
     *
     * Ensures proper cleanup when derived classes are deleted.
     */
    virtual ~Item();

    /**
     * @brief Virtual method to display information about the item.
     *
     * This method must be implemented by derived classes to provide
     * specific details about the item.
     */
    virtual void displayInfo() = 0;

    /**
     * @brief Virtual method to get the item type.
     *
     * This method must be implemented by derived classes to return
     * a string representing the type of the item.
     *
     * @return A string representing the item type.
     */
    virtual std::string itemType() = 0;

    /**
     * @brief Checks if an item of the same type exists in the inventory.
     *
     * @param Inventory A vector of Item pointers representing the inventory.
     * @return A boolean indicating whether an item of the same type exists in the inventory.
     */
    bool hasItemType(const std::vector<Item*>& Inventory);
};
