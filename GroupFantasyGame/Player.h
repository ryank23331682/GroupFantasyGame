#pragma once
#include "Item.h"
#include<string>
#include "Character.h"
#include <vector>
using namespace std;
class Player : public Character {
public:
	vector<Item>* Inventory;
	Player(Character c);
	void equipItem(const Item& item);
	void dropItem(vector<Item>* Inventory,int itemIndex);
	int calculateDamage();
	void displayInventory(vector<Item>* inventory, int length);
};