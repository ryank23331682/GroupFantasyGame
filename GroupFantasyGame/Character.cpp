#include<string>
#include "Item.h"
#include "Character.h"
#include "Player.cpp"
using namespace std;
class Character {
public:
	string name;
	int health;
	int attackChance;
	int defenseChance;

	Character(string n, int hp, int att, int def)
		: name(n), health(hp), attackChance(att), defenseChance(def) {}

	int calculateDamage() const {
		return 0;
	}
	bool defend(int attackerDamage) {
		if (rand() % 100 < defenseChance) {
			// Successful defense
			int damage = calculateDamage();
			health -= max(0, attackerDamage - damage);
			return true;
		}
		return false; // Defense failed
	}

	bool attack(Character& defender, int weaponDamage) {
		if (rand() % 100 < attackChance) {
			if (!defender.defend(weaponDamage)) {
				return true; // Successful attack
			}
		}
		return false; // Attack failed
	}


};