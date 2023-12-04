#include "Weapon.h"
#include <string>
#include <iostream>

/**
 * @brief Parameterized constructor for the Weapon class.
 *
 * Initializes a Weapon object with the provided name, weight, and attack bonus.
 *
 * @param name The name of the weapon.
 * @param weight The weight of the weapon.
 * @param aB The attack bonus of the weapon.
 */
Weapon::Weapon(string name, int weight, int aB)
    : Item(name, weight), attackBonus(aB)
{

}

/**
 * @brief Default constructor for the Weapon class.
 *
 * Initializes a Weapon object with default values.
 */
Weapon::Weapon()
{
    attackBonus = 0;
}

/**
 * @brief Displays information about the weapon.
 *
 * Outputs details about the weapon, including its name, weight, and attack bonus.
 */
void Weapon::displayInfo()
{
    cout << "Weapon: " << name << ", Weight: " << weight << ", Attack Bonus: " << attackBonus << "\n";
}

/**
 * @brief Gets the item type of the weapon.
 *
 * Returns the item type of the weapon, which is "Weapon".
 *
 * @return The item type of the weapon.
 */
string Weapon::itemType()
{
    return "Weapon";
}