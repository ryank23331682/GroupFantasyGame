#include "Item.h"

Item::Item()
{
	weight = 0;
	attackValue = 0;
	defenseVaue = 0;
}

Item::Item(string name, int weight, int attackValue, int defenseVaue) : name(name), weight(weight), attackValue(attackValue), defenseVaue(defenseVaue)
{
}