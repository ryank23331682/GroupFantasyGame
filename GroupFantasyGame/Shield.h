#pragma once
#include "Item.h"
class Shield : public Item
{
public:
	int defenseBonus;
	int attackPenalty;
	Shield(std::string name, int weight, int dBonus, int aPenalty);
	Shield();
	void displayInfo();
};

