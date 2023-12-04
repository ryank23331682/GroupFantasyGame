#pragma once
#include "Item.h"
class Ring : public Item
{
public:
	int strengthBonus;
	int healthBonus;
	int healthPenalty;
	Ring(std::string name, int weight, int hBonus, int sBonus, int hPenalty);
	Ring();
	void displayInfo();
	string itemType();
};

