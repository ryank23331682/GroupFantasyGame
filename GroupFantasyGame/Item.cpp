#include "Item.h"
#include <iostream>

/**
 * @brief Default constructor for the Item class.
 *
 * Initializes an Item object with default values for name and weight.
 */
Item::Item()
    : weight(0), name("")
{
}

/**
 * @brief Destructor for the Item class.
 *
 * This function is called when an Item object is no longer in use.
 */
Item::~Item()
{
}

/**
 * @brief Parameterized constructor for the Item class.
 *
 * Initializes an Item object with specified values for name and weight.
 *
 * @param name The name of the item.
 * @param weight The weight of the item.
 */
Item::Item(std::string name, int weight)
    : name(name), weight(weight)
{
}

/**
 * @brief Checks if an item of the same type exists in the inventory.
 *
 * This function compares the item type of the current item with the item
 * types in the inventory to determine if an item of the same type is present.
 *
 * @param Inventory The inventory to check for item types.
 *
 * @return True if an item of the same type is found, false otherwise.
 */
bool Item::hasItemType(const std::vector<Item*>& Inventory)
{
    for (const auto& inventoryItem : Inventory)
    {
        if (inventoryItem->itemType() == itemType())
        {
            // Item of the same type found in the inventory
            return true;
        }
    }
    // Item type not found in the inventory
    return false;
}