#include "Item.h"
#include <iostream>

Item::Item()
{
	weight = 0;
	name = "";
}

Item::Item(string name, int weight) : name(name), weight(weight)
{
}

void Item::displayInfo()
{
	cout << "Item: " << name << ", Weight: " << weight << "\n";
}