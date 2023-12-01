#pragma once
#include "Item.h"
#include<string>
#include "Character.h"
#include <vector>
using namespace std;
class Player : public Character {
public:
	vector<Item>* Inventory;
	int gold;
	Player(Character c);
	void equipItem(const Item& item);
	int calculateDamage();
	void displayInventory(vector<Item>* inventory, int length);
};