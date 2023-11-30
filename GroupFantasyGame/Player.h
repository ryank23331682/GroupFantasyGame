#pragma once
#include "Item.h"
#include<string>
#include "Character.h"
using namespace std;
class Player : public Character {
public:
	vector <Item> Inventory;
	Player(Character c);

	void equipItem(const Item& item) {
		// Implement logic to modify character attributes based on the equipped item
		// You may need to add more attributes or methods to the Character class for this.
	}
public:
	int calculateDamage() const {
		return 0; // Base character has no special ability
	}
};