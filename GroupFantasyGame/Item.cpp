#include "Item.h"
#include <iostream>

Item::Item()
{
	weight = 0;
	name = "";
}

Item::~Item()
{
}

Item::Item(string name, int weight) : name(name), weight(weight)
{
}

bool Item::hasItemType(const vector<Item*>& Inventory)
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
