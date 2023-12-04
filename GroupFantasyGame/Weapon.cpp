#include "Weapon.h"
#include <string>
#include <iostream>

Weapon::Weapon(string name, int weight, int aB)
	: Item(name, weight), attackBonus(aB)
{

}

Weapon::Weapon()
{
	attackBonus = 0;
}

void Weapon::displayInfo() 
{
	cout << "Weapon: " << name << ", Weight: " << weight << ", Attack Bonus: " << attackBonus << "\n";
}

string Weapon::itemType()
{
	return "Weapon";
}
