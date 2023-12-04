#pragma once
#include "Item.h"
#include<string>
#include "Character.h"
#include <vector>
using namespace std;
class Player : public Character {
public:
	vector<Item*>* Inventory;
	int gold;
	int totalWeight;
	Player(Character c);
	Player();
	bool equipItem(const Item& item);
	void displayInventory(int length);
	void dropItem(int itemIndex);
	void displayPlayerProperties();
};