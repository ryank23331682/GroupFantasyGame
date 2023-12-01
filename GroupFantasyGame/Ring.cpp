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

void Ring::displayInfo() {
	std::cout << "Ring: " << name << ", Weight: " << weight << ", Health Bonus: " << healthBonus << ", Strength Bonus: " << strengthBonus << ", Health Penalty: " << healthPenalty << "\n";
}
