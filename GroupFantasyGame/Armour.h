#pragma once
#include "Item.h"
class Armour : public Item
{
public:
	int defenseBonus;
	int attackPenalty;
	Armour(std::string name, int weight, int dBonus, int aPenalty);
	Armour();
	void displayInfo();
};

