#include "Weapon.h"
#include <string>
#include <iostream>

/*
* Weapon(string name, int weight, int aB)
* Computes Weapon values.
*
* parameter: 
*			
* return:  none
*/
Weapon::Weapon(string name, int weight, int aB)
	: Item(name, weight), attackBonus(aB)
{

}

Weapon::Weapon()
{
	attackBonus = 0;
}

/*
* Weapon::displayInfo()
* Computes in the output window Weapon, Weight and Attack Bonus.
*
* parameter: none 
*
* return:  none
*/
void Weapon::displayInfo() {
	cout << "Weapon: " << name << ", Weight: " << weight << ", Attack Bonus: " << attackBonus << "\n";
}
