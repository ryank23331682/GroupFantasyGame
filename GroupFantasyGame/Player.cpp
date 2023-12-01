#include<string>
#include "Item.h"
#include "Player.h"
#include "Character.h"
#include <iostream>
using namespace std;

Player::Player(Character c)
	: Character(c.race, c.attack, c.defence, c.health, c.strength, c.attackChance, c.defenseChance), Inventory()
{
}

void Player::equipItem(const Item& item)
{
	Inventory = new std::vector<Item>();
	Inventory->push_back(item);
}

int Player::calculateDamage()
{
	return 0;
}

void Player::displayInventory(vector<Item>* inventory, int length)
{
	cout << "Inventory:\n";
	for (int i = 0; i < length; ++i)
	{
		// Call displayInfo on each Item object in the vector
		(*inventory)[i].displayInfo();
	}
}
int Character::defendMove(int& incomingDamage) {
	double randomValue = static_cast<double>(rand()) / RAND_MAX;  // Generate a random value between 0 and 1

	if (randomValue < defenseChance) {
		// Successful defense
		int actualDamage = std::max(0, incomingDamage - defence);
			health -= actualDamage;

		std::cout << race << " successfully defended. Damage reduced to " << actualDamage << ". Remaining health: " << health << std::endl;

		return actualDamage;  // Defense succeeded
	}
	else {
		std::cout << race << "'s defense failed. Incoming damage: " << incomingDamage << std::endl;
		return 0;  // Defense failed
	}
}

//bool attack(Player& defender, Player& attacker) {
//	if (rand() % 100 < attacker.attackChance) {
//		if (!defender.defence) {
//			return true; // Successful attack
//		}
//	}
//	return false; // Attack failed
//}

int Character::attackMove(Character& enemy) {
	double randomValue = static_cast<double>(rand()) / RAND_MAX;  // Generate a random value between 0 and 1

	if (randomValue < attackChance) {
		// Successful attack
		int damage = enemy.attack;
		int actualDamage = enemy.defendMove(damage);
		if (actualDamage > 0) {
			std::cout << race << " successfully attacked " << enemy.race << ". Damage: " << damage << std::endl;
		}

		return actualDamage;  // Attack succeeded
	}
	else {
		std::cout << race << "'s attack failed." << std::endl;
		return 0;  // Attack failed
	}
}



