#pragma once
#include<vector>
#include<iostream>
#include "Item.h"
using namespace std;
class Inventory {
private:
	vector<Item> items;

public:
	void addItem(Item item) {
		items.push_back(item);
	}

	void displayInventory() {
		cout << "Inventory:\n";
		for (const auto& item : items) {
			std::cout << "Name: " << item.name << ", Category: " << item.category << ", Weight: " << item.weight << "\n";
		}
	}

	// Additional methods for handling inventory and character interactions could be added here
};
