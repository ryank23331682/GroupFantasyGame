#include "Armour.h"
#include <iostream>
/*
* Armour (name, weight, dBonus, aPenalty)
* Computes defenceBonus value and attackPenalty value
*
* parameter: name
*			 weight
*			 dBonus
*			 aPenalty
* 
* return: no return value
*
*/
Armour::Armour(std::string name, int weight, int dBonus, int aPenalty)
	: Item(name, weight)
{
	defenseBonus = dBonus;
	attackPenalty = aPenalty;
}

Armour::Armour()
{
}

/*
* Armour::displayInfo()
* Displays Armour info
*
* parameter: none
* return: no return value
*
*/
void Armour::displayInfo() {
	std::cout << "Armour: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
} 