#include<string>
#include "Item.h"
#include "Player.h"
#include "Character.h"
#include <iostream>
using namespace std;

	Player::Player(Character c)
	: Character(c.race, c.attack, c.defence, c.health, c.strength, c.attackChance, c.defenseChance),Inventory()
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
		

	bool attack(Player& defender, Player& attacker) {
		if (rand() % 100 < attacker.attackChance) {
			if (!defender.defence) {
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


