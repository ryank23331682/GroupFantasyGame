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

	void displayInventory() {
		std::cout << "Inventory:\n";
		for (const auto& item : items) {
			std::cout << "Name: " << item.name << ", Category: " << item.category << ", Weight: " << item.weight << "\n";
		}
	}

	// Additional methods for handling inventory and character interactions could be added here
};