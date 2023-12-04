#include "Ring.h"
#include <string>
#include <iostream>

Ring::Ring(std::string name, int weight, int hBonus, int sBonus, int hPenalty)
	: Item(name, weight)
{
	strengthBonus = sBonus;
	healthBonus = hBonus;
	healthPenalty = hPenalty;
}

Ring::Ring()
{
}

/*
* Ring::displayInfo()
* Computes on standard cout Ring, weight, health bonus, strength bonus and health penalty.
*
* parameter: none
*
* return:  none
*/
void Ring::displayInfo() {
	std::cout << "Ring: " << name << ", Weight: " << weight << ", Health Bonus: " << healthBonus << ", Strength Bonus: " << strengthBonus << ", Health Penalty: " << healthPenalty << "\n";
}
