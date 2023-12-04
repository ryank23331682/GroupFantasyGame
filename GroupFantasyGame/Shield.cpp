#include "Shield.h"
#include <string>
#include <iostream>

/*
* Shield(std::string name, int weight, int dBonus, int aPenalty)
* Computes the dense Bonus value and the attack penalty value.
*
* parameter: name
*			 weight
*		     dBonus
*			 aPenalty
*
* return:  none
*/
Shield::Shield(std::string name, int weight, int dBonus, int aPenalty)
	: Item(name, weight)
{
	defenseBonus = dBonus;
	attackPenalty = aPenalty;
}

Shield::Shield()
{
}

/*
* Shield::displayInfo()
* Computes on standard cout Shield, Weight, Defnece bonus, and Attack Penalty.
*
* parameter: none
*
* return:  none
*/
void Shield::displayInfo()
{
	std::cout << "Shield: " << name << ", Weight: " << weight << ", Defense Bonus: " << defenseBonus << ", Attack Penalty: " << attackPenalty << "\n";
}
