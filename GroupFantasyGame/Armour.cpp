#include "Armour.h"
#include <iostream>
Armour::Armour(std::string name, int weight, int dBonus, int aPenalty)
	: Item(name, weight)
{
	defenseBonus = dBonus;
	attackPenalty = aPenalty;
}

Armour::Armour()
{
}

void Armour::displayInfo() {
	std::cout << "Armour: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
} 