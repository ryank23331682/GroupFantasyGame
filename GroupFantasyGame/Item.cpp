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

/*
* Item::displayInfo()
* Computes the display infor i.e. item and weight in the output window
*
* parameter: none
* return: no return value
*/
void Item::displayInfo()
{
	cout << "Item: " << name << ", Weight: " << weight << "\n";
}