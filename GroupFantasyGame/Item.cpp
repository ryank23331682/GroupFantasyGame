#include "Item.h"
#include <iostream>

Item::Item()
{
	weight = 0;
	name = "";
	category = "";
}

Item::Item(string name,string category, int weight) : name(name),category(category), weight(weight)
{
}

void Item::displayInfo()
{
	cout << "Item: " << name << ", Weight: " << weight << "\n";
}
