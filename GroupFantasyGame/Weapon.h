#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	int attackBonus;
	Weapon(string name, int weight, int attackBonus);
	Weapon();
	void displayInfo();
};

