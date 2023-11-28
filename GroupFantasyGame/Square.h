#include "Enemy.h"
#include "Item.h"

class Square
{
public:
	Enemy enemy;
	Item item;
	bool hasItem;
	bool hasEnemy;
	Square(int randomValue);
	Square();

};

