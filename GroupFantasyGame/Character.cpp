#include<string>
#include<iostream>
#include "Enemy.h"
#include "Item.h"
#include "Character.h"
//#include "Player.cpp"
using namespace std;

class Character : public Enemy {
public:
	string name;
	int health;
	int attackChance;
	int defenseChance;

	Character(string n, int hp, int att, int def)
		:name(n), health(hp), attackChance(att), defenseChance(def) {}

	bool is_defeated() const {
		return health <= 0;
	}

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

	void attackEnemy(Character& enemy) {
		if (rand() % 4 == 0) {// attacked by orc 
			if (rand() % 3 < 2) { //succesful defense 
				int damage = calculateDamage();
				enemy.receiveDamage(damage);
				cout << name << "attacked enemy " << enemy.name << "damage given " << damage << endl;
			}
			else {
				cout << name << "'s attack was defended by " << enemy.name << "!" << endl;
			}
		}
	}

	void receiveDamage(int damage) {
		health -= damage;
		if (is_defeated()) {
			cout << name << "has been defeated " << endl;
		}
	}

};