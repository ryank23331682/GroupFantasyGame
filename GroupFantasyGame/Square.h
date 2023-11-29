#include "Enemy.h"
#include "Item.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Shield.h" 

class Square {
public:
	Enemy enemy;
	Weapon weapon;
	Armour armour;
	Ring ring;
	Shield shield;
	bool hasItem;
	bool hasEnemy;
	bool hasArmour;
	bool hasShield;
	bool hasWeapon;
	bool hasRing;

	Square(Enemy e);
	Square(Weapon w);
	Square(Ring r);
	Square(Shield s);
	Square(Armour a);
	Square();

};


