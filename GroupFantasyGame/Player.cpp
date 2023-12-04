#include<string>
#include <random>
#include "Item.h"
#include "Player.h"
#include "Character.h"
#include <iostream>
#include "Weapon.h"
#include "Armour.h"
#include "Ring.h"
#include "Shield.h"
using namespace std;

Player::Player(Character c)
	: Character(c.race, c.attack, c.defence, c.health, c.strength, c.attackChance, c.defenseChance), Inventory(new vector<Item*>())
{
	totalWeight = 0;
	gold = 0;
}

bool Player::equipItem(const Item& item)
{

	if (item.weight + totalWeight > strength) 
	{
		return false;
	} 
	else
	{
		//Inventory->push_back(item);
		totalWeight += item.weight;

		// Check if the item is a Weapon
		const Weapon* weaponPtr = dynamic_cast<const Weapon*>(&item);
		const Armour* armourPtr = dynamic_cast<const Armour*>(&item);
		const Ring* ringPtr = dynamic_cast<const Ring*>(&item);
		const Shield* shieldPtr = dynamic_cast<const Shield*>(&item);

		if (weaponPtr != nullptr)
		{
			Inventory->push_back(new Weapon(*weaponPtr));
			// Access weapon properties
			attack += weaponPtr->attackBonus;
		}
		if (armourPtr != nullptr)
		{
			Inventory->push_back(new Armour(*armourPtr));
			// Access weapon properties
			defence += armourPtr->defenseBonus;
		}
		if (ringPtr != nullptr)
		{
			Inventory->push_back(new Ring(*ringPtr));
			// Access weapon properties
			health += ringPtr->healthBonus;
			health -= ringPtr->healthPenalty;
			strength -= ringPtr->strengthBonus;
		}
		if (shieldPtr != nullptr)
		{
			Inventory->push_back(new Shield(*shieldPtr));
			// Access weapon properties
			defence += shieldPtr->defenseBonus;
			attack -= shieldPtr->attackPenalty;
		}
		//displayPlayerProperties();
		return true;
	}
}


void Player::displayInventory(int length)
{
	cout << "Inventory:\n";
	// Check if the pointer is not null before accessing its elements
	if (Inventory != nullptr) {
		for (auto& inventoryItem : *Inventory) {
			// Assuming the name uniquely identifies the item type
			inventoryItem->displayInfo();
		}
	}
}
int Character::defendMove(int& incomingDamage) {
	std::random_device rd;
	std::mt19937 gen(rd());  // Standard mersenne_twister_engine
	std::uniform_real_distribution<> randomValueDist(0.0, 1.0);
	double randomValue = randomValueDist(gen);

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

int Character::attackMove(Character& enemy) {
	std::random_device rd;
	std::mt19937 gen(rd());  // Standard mersenne_twister_engine
	std::uniform_real_distribution<> randomValueDist(0.0, 1.0);
	double randomValue = randomValueDist(gen);

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

void Player::dropItem(int itemIndex)
{

	// Check if the index is valid
	if (itemIndex >= 0 && itemIndex < Inventory->size())
	{
		// Get the dropped item
		Item* droppedItem = (*Inventory)[itemIndex];

		// Check if the dropped item is a Weapon
		const Weapon* weaponPtr = dynamic_cast<const Weapon*>(droppedItem);
		const Armour* armourPtr = dynamic_cast<const Armour*>(droppedItem);
		const Ring* ringPtr = dynamic_cast<const Ring*>(droppedItem);
		const Shield* shieldPtr = dynamic_cast<const Shield*>(droppedItem);

		// Remove the item from the inventory
		Inventory->erase(Inventory->begin() + itemIndex);

		// Adjust player's properties based on the dropped item
		if (weaponPtr != nullptr)
		{
			// Access weapon properties
			attack -= weaponPtr->attackBonus;
		}
		else if (armourPtr != nullptr)
		{
			// Access armour properties
			defence -= armourPtr->defenseBonus;
		}
		else if (ringPtr != nullptr)
		{
			// Access ring properties
			health -= ringPtr->healthBonus;
			health += ringPtr->healthPenalty;
			strength += ringPtr->strengthBonus;
		}
		else if (shieldPtr != nullptr)
		{
			// Access shield properties
			defence -= shieldPtr->defenseBonus;
			attack += shieldPtr->attackPenalty;
		}
	}
	//displayPlayerProperties();
}

// Implementation of the new function
void Player::displayPlayerProperties()
{
	cout << "Player Properties:" << endl;
	cout << "Race: " << race << endl;
	cout << "Attack: " << attack << endl;
	cout << "Defence: " << defence << endl;
	cout << "Health: " << health << endl;
	cout << "Strength: " << strength << endl;
	cout << "Defense Chance: " << defenseChance << endl;
	cout << "Attack Chance: " << attackChance << endl;
	cout << "Gold: " << gold << endl;
	cout << "Total Weight: " << totalWeight << endl;

}




