#include<string>
#include "Item.h"
#include "Character.h"
#include "Player.cpp"
using namespace std;

	Character::Character(string n, int str, int hp, int att, int def)
		: name(n), health(hp), attackChance(att), defenseChance(def) 
	{
	}

	bool attack(Character& defender, Character& attacker) {
		if (rand() % 100 < attacker.attackChance) {
			if (!defender.defense) {
				return true; // Successful attack
			}
		}
		return false; // Attack failed
	}

	//bool defend(int attackerDamage) {
	//	if (rand() % 100 < defenseChance) {
	//		// Successful defense
	//		int damage = calculateDamage();
	//		health -= max(0, attackerDamage - damage);
	//		return true;
	//	}
	//	return false; // Defense failed
	//}
	//idk why but calculate damage is not working 
	//cause we cant access virtual method?!?!
