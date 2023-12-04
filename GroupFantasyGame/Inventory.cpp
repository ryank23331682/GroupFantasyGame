#include<vector>
#include "Item.h"
#include<iostream>
class Inventory {
private:
	std::vector<Item> items;

public:
	void addItem(Item item) {
		items.push_back(item);
	}

/*
* DisplayInventory()
* Computes on the terminal, the item name and item weight
* 
* parameter: none
* return: no return value
*
*/
	void displayInventory() {
		std::cout << "Inventory:\n";
		for (const auto& item : items) {
			std::cout << "Name: " << item.name << ", Weight: " << item.weight << "\n";
		}
	}

	// Additional methods for handling inventory and character interactions could be added here
};