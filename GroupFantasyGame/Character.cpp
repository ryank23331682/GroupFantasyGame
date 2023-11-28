#include<string>
#include "Item.h"
class Character {
public:
	std::string name;
	int strength;
	int health;
	int attack;
	int defense;

	Character(std::string n, int str, int hp, int att, int def)
		: name(n), strength(str), health(hp), attack(att), defense(def) {}

	void equipItem(const Item& item) {
		// Implement logic to modify character attributes based on the equipped item
		// You may need to add more attributes or methods to the Character class for this.
	}
};