go
#include "Enemy.h"
#include "Item.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"


#include "Square.h"
#include <stdlib.h>

Square::Square(Enemy e)
	: enemy(e), weapon(), hasItem(false), hasEnemy(true), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(false) {}

Square::Square(Weapon w)
	: weapon(w), enemy(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(true), hasRing(false) {}

Square::Square(Shield s)
	: shield(s), enemy(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(true), hasWeapon(false), hasRing(false) {}

Square::Square(Armour a)
	: armour(a), enemy(), hasItem(true), hasEnemy(false), hasArmour(true), hasShield(false), hasWeapon(false), hasRing(false) {}

Square::Square(Ring r)
	: ring(r), enemy(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(true) {}

Square::Square()
	: weapon(), enemy(), hasItem(false), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(false) {}
