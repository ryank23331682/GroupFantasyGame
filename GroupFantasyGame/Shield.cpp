#include "Shield.h"
#include <string>
#include <iostream>

/**
 * @brief Parameterized constructor for the Shield class.
 *
 * Initializes a Shield object with the given properties.
 *
 * @param name The name of the shield.
 * @param weight The weight of the shield.
 * @param dBonus The defense bonus provided by the shield.
 * @param aPenalty The attack penalty applied by the shield.
 */
Shield::Shield(std::string name, int weight, int dBonus, int aPenalty)
    : Item(name, weight), defenseBonus(dBonus), attackPenalty(aPenalty)
{

}

/**
 * @brief Default constructor for the Shield class.
 *
 * Initializes all properties of the Shield to zero or empty values.
 */
Shield::Shield()
{
    defenseBonus = 0;
    attackPenalty = 0;
}

/**
 * @brief Displays information about the shield.
 *
 * Outputs the details of the shield, including its name, weight, defense bonus,
 * and attack penalty.
 */
void Shield::displayInfo()
{
    std::cout << "Shield: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
}

/**
 * @brief Gets the item type of the shield.
 *
 * Returns a string representing the type of the shield, which is "Shield".
 *
 * @return The item type of the shield.
 */
string Shield::itemType()
{
    return "Shield";
}