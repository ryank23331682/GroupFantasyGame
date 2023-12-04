#include "Shield.h"
#include <string>
#include <iostream>

Shield::Shield(std::string name, int weight, int dBonus, int aPenalty)
	: Item(name, weight)
{
	defenseBonus = dBonus;
	attackPenalty = aPenalty;
}

Shield::Shield()
{
	defenseBonus = 0;
	attackPenalty = 0;
}

void Shield::displayInfo()
{
	std::cout << "Shield: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
}

string Shield::itemType()
{
	return "Shield";
}
