#pragma once
#include<vector>
#include<iostream>
#include "Item.h"
using namespace std;

class Inventory {
private:
	vector<Item> items;
	

public:
	bool isFull;
	

	void addItem(Item item);

	void displayInventory();

	void isInventoryIsFull();
		
	// Additional methods for handling inventory and character interactions could be added here
};
