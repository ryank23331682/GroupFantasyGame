#pragma once
#include "Item.h"
using namespace std;
class Character {
public:
	string name;
	int strength;
	int health;
	int attackChance;
	int defenseChance;


	Character(string n, int str, int hp, int att, int def)
		: name(n), strength(str), health(hp), attackChance(att), defenseChance(def) {}

	void equipItem(const Item& item) {
		// Implement logic to modify character attributes based on the equipped item
		// You may need to add more attributes or methods to the Character class for this.
	}
	Character(string n, int hp, int att, int def);
};