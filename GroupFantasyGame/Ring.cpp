#include "Ring.h"
#include <string>
#include <iostream>

/**
 * @brief Parameterized constructor for the Ring class.
 *
 * Initializes a Ring object with the given properties.
 *
 * @param name The name of the ring.
 * @param weight The weight of the ring.
 * @param hBonus The health bonus provided by the ring.
 * @param sBonus The strength bonus provided by the ring.
 * @param hPenalty The health penalty applied by the ring.
 */
Ring::Ring(std::string name, int weight, int hBonus, int sBonus, int hPenalty)
    : Item(name, weight), strengthBonus(sBonus), healthBonus(hBonus), healthPenalty(hPenalty)
{

}

/**
 * @brief Default constructor for the Ring class.
 *
 * Initializes all properties of the Ring to zero or empty values.
 */
Ring::Ring()
{
    strengthBonus = 0;
    healthBonus = 0;
    healthPenalty = 0;
}

/**
 * @brief Displays information about the ring.
 *
 * Outputs the details of the ring, including its name, weight, health bonus,
 * strength bonus, and health penalty.
 */
void Ring::displayInfo()
{
    std::cout << "Ring: " << name << ", Weight: " << weight << ", Health Bonus: " << healthBonus << ", Strength Bonus: " << strengthBonus << ", Health Penalty: " << healthPenalty << "\n";
}

/**
 * @brief Gets the item type of the ring.
 *
 * Returns a string representing the type of the ring, which is "Ring".
 *
 * @return The item type of the ring.
 */
string Ring::itemType()
{
    return "Ring";
}