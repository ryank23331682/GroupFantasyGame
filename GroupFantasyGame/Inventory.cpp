#include<vector>
#include "Item.h"
#include "Inventory.h"
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
			std::cout << "Name: " << item.name << ", Weight: " << item.weight << "\n";
		}
	}

	void isInventoryIsFull(){
		if(items.size()==5){
			isFull(true);
		}
		else {
			isFull(false);
		}
	}
	// Additional methods for handling inventory and character interactions could be added here
};