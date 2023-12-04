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

/**
 * @file Player.cpp
 * @brief Implementation of the Player class.
 */

 // Define a macro for the attack chance check
#define ATTACK_CHANCE_CHECK(randomValue, chance) (randomValue < chance)

// Define a macro for the defense chance check
#define DEFENSE_CHANCE_CHECK(randomValue, chance) (randomValue < chance)

 /**
  * @brief Parameterized constructor for the Player class.
  *
  * Initializes a Player object using the properties of a Character object and
  * sets the inventory, total weight, and gold.
  *
  * @param c The Character object used to initialize the Player.
  */
Player::Player(Character c)
    : Character(c.race, c.attack, c.defence, c.health, c.strength, c.attackChance, c.defenseChance), Inventory(new vector<Item*>())
{
    totalWeight = 0;
    gold = 0;
}

/**
 * @brief Default constructor for the Player class.
 *
 * Initializes an empty inventory, total weight, and gold.
 */
Player::Player()
{
    Inventory = new vector<Item*>();
    totalWeight = 0;
    gold = 0;
}

/**
 * @brief Attempts to equip an item to the player.
 *
 * This function checks if equipping the item exceeds the player's strength. If
 * successful, the item is added to the inventory, and the player's properties
 * are adjusted accordingly.
 *
 * @param item The item to be equipped.
 * @return True if the item is equipped successfully, false otherwise.
 */
bool Player::equipItem(const Item& item)
{
    // Check if the total weight and the added weight of the item exceeds the total weight of the player
    if (item.weight + totalWeight > strength)
    {
        return false;
    }
    else
    {
        // Add to the total weight
        totalWeight += item.weight;

        // Check if the item is a Weapon, Armour, Ring, or Shield
        const Weapon* weaponPtr = dynamic_cast<const Weapon*>(&item);
        const Armour* armourPtr = dynamic_cast<const Armour*>(&item);
        const Ring* ringPtr = dynamic_cast<const Ring*>(&item);
        const Shield* shieldPtr = dynamic_cast<const Shield*>(&item);

        // Checks to see which type of item it is
        if (weaponPtr != nullptr)
        {
            //Push the item to inventory 
            Inventory->push_back(new Weapon(*weaponPtr));

            // Update the attribute the item affects
            attack += weaponPtr->attackBonus;
        }
        if (armourPtr != nullptr)
        {
            //Push the item to inventory 
            Inventory->push_back(new Armour(*armourPtr));

            // Update the attribute the item affects
            defence += armourPtr->defenseBonus;
        }
        if (ringPtr != nullptr)
        {
            //Push the item to inventory 
            Inventory->push_back(new Ring(*ringPtr));

            // Update the attribute the item affects
            health += ringPtr->healthBonus;
            health -= ringPtr->healthPenalty;
            strength -= ringPtr->strengthBonus;
        }
        if (shieldPtr != nullptr)
        {
            //Push the item to inventory 
            Inventory->push_back(new Shield(*shieldPtr));

            // Update the attribute the item affects
            defence += shieldPtr->defenseBonus;
            attack -= shieldPtr->attackPenalty;
        }
        return true;
    }
}

/**
 * @brief Displays the inventory of the player.
 *
 * This function iterates through the player's inventory and displays the
 * information of each item.
 *
 * @param length The length of the inventory.
 */
void Player::displayInventory(int length)
{
    int counter = 1;

    cout << "Inventory:\n";
    // Check if the pointer is not null before accessing its elements
    if (Inventory != nullptr)
    {
        for (auto& inventoryItem : *Inventory)
        {
            std::cout << counter << ". ";
            inventoryItem->displayInfo();
            counter++;
        }
    }
}

/**
 * @brief Drops an item from the player's inventory.
 *
 * This function removes the specified item from the inventory and adjusts
 * the player's properties accordingly.
 *
 * @param itemIndex The index of the item to be dropped.
 */
void Player::dropItem(int itemIndex)
{
    // Check if the index is valid
    if (itemIndex >= 0 && itemIndex < Inventory->size())
    {
        // Get the dropped item
        Item* droppedItem = (*Inventory)[itemIndex];

        // Check if the dropped item is a Weapon, Armour, Ring, or Shield
        const Weapon* weaponPtr = dynamic_cast<const Weapon*>(droppedItem);
        const Armour* armourPtr = dynamic_cast<const Armour*>(droppedItem);
        const Ring* ringPtr = dynamic_cast<const Ring*>(droppedItem);
        const Shield* shieldPtr = dynamic_cast<const Shield*>(droppedItem);

        // Remove the item from the inventory
        Inventory->erase(Inventory->begin() + itemIndex);

        // Adjust player's properties based on the dropped item
        if (weaponPtr != nullptr)
        {
            attack -= weaponPtr->attackBonus;
        }
        else if (armourPtr != nullptr)
        {
            defence -= armourPtr->defenseBonus;
        }
        else if (ringPtr != nullptr)
        {
            health -= ringPtr->healthBonus;
            health += ringPtr->healthPenalty;
            strength += ringPtr->strengthBonus;
        }
        else if (shieldPtr != nullptr)
        {
            defence -= shieldPtr->defenseBonus;
            attack += shieldPtr->attackPenalty;
        }
    }
}

/**
 * @brief Displays the properties of the player.
 *
 * This function prints the race, attack, defence, health, strength, defense
 * chance, attack chance, gold, and total weight of the player.
 */
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

/**
 * @brief Applies special abilities based on the character's race.
 *
 * This function applies special abilities based on the character's race after
 * a successful defense.
 *
 * @param actualDamage The actual damage received after a successful defense.
 * @param isDay Boolean indicating whether it is day or night.
 */
void Character::applySpecialAbilities(int& actualDamage, bool isDay)
{
    // If the race is human or dwarf update the attributes assocciated with its ability
	if (race == "Human" || race == "Dwarf") {
		health -= actualDamage;
	}
	else if (race == "Elf") {
		health += 1;
	}
	else if (race == "Hobbit") {
		int hobbitDamage = rand() % 5;
		health -= hobbitDamage;
		std::cout << race << " successfully defended. Damage caused: " << hobbitDamage << ". Remaining health: " << health << std::endl;
	}
	else if (race == "Orc") {
		if (!isDay) {

			health += 1;
		}
	}
}

/**
 * @brief Defends against an incoming attack.
 *
 * Generates a random value and compares it with the defense chance of the character.
 * If the random value is less than the defense chance, the defense is successful, and
 * the character takes reduced damage. The special abilities are applied, and the remaining
 * health is updated.
 *
 * @param incomingDamage The incoming damage from an attack.
 * @param ISDAY A boolean indicating if it is daytime.
 * @return The actual damage taken after the defense.
 */
int Character::defendMove(int& incomingDamage, bool ISDAY)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> randomValueDist(0.0, 1.0);
    double randomValue = randomValueDist(gen);

    if (DEFENSE_CHANCE_CHECK(randomValue, defenseChance))
    {
        // Successful defense
        int actualDamage = std::max(0, incomingDamage - defence);
        applySpecialAbilities(actualDamage, ISDAY);

        std::cout << race << " successfully defended. Damage reduced to " << actualDamage
            << ". Remaining health: " << health << std::endl;

        return actualDamage;  // Defense succeeded
    }
    else
    {
        std::cout << race << "'s defense failed. Incoming damage: " << incomingDamage << std::endl;
        return incomingDamage;  // Defense failed
    }
}

/**
 * @brief Performs an attack on an enemy character.
 *
 * Generates a random value and compares it with the attack chance of the character.
 * If the random value is less than the attack chance, the attack is successful, and
 * damage is dealt to the enemy character. The actual damage is determined by the
 * enemy's defense move. If the attack succeeds, information about the attack is printed.
 *
 * @param enemy The enemy character to attack.
 * @param isDay A boolean indicating if it is daytime.
 * @return The actual damage dealt to the enemy after the attack.
 */
int Character::attackMove(Character& enemy, bool isDay)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> randomValueDist(0.0, 1.0);
    double randomValue = randomValueDist(gen);

    if (ATTACK_CHANCE_CHECK(randomValue, attackChance))
    {
        // Successful attack
        int damage = enemy.attack;
        int actualDamage = enemy.defendMove(damage, isDay);
        if (actualDamage > 0)
        {
            std::cout << race << " successfully attacked " << enemy.race
                << ". Damage: " << damage << std::endl;
        }

        return actualDamage; 
    }
    else
    {
        std::cout << race << "'s attack failed." << std::endl;
        return 0;  // Attack failed
    }
}



