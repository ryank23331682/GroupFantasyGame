#pragma once
#include "Item.h"
#include<string>
using namespace std;
class Character {
public:
	string name;
	int strength;
	int health;
	int attack;
	int defense;
	int attackChance;
	int defenseChance;

	Character(string n, int str, int hp, int att, int def);

	void equipItem(const Item& item) {
		// Implement logic to modify character attributes based on the equipped item
		// You may need to add more attributes or methods to the Character class for this.
	}
public:
	int calculateDamage() const {
		return 0; // Base character has no special ability
	}
};