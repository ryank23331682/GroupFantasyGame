#include "Armour.h"
#include <iostream>

/**
 * @brief Parameterized constructor for the Armour class.
 *
 * Initializes an Armour object with specified values for name, weight,
 * defense bonus, and attack penalty.
 *
 * @param name The name of the armour.
 * @param weight The weight of the armour.
 * @param dBonus The defense bonus provided by the armour.
 * @param aPenalty The attack penalty imposed by the armour.
 */
Armour::Armour(std::string name, int weight, int dBonus, int aPenalty)
    : Item(name, weight), defenseBonus(dBonus), attackPenalty(aPenalty)
{
}

/**
 * @brief Default constructor for the Armour class.
 *
 * Initializes an Armour object with default values.
 */
Armour::Armour()
    : defenseBonus(0), attackPenalty(0)
{
}

/**
 * @brief Displays information about the armour.
 *
 * This function prints information about the armour, including its name,
 * weight, defense bonus, and attack penalty.
 */
void Armour::displayInfo()
{
    std::cout << "Armour: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
}

/**
 * @brief Returns the item type of the armour.
 *
 * @return A string representing the item type of the armour.
 */
std::string Armour::itemType()
{
    return "Armour";
}