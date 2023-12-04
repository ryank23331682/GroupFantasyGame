#include "Character.h"
#include "Item.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Square.h"
#include <stdlib.h>

/*
* Square::Square(Character c)
* Declares the following constructors, character, weapon, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square(Character c)
    : character(c), weapon(), hasItem(false), hasEnemy(true), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(false) {}

/*
* Square::Square(Weapon q)
* Declares the following constructors, character, weapon, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square(Weapon w)
    : weapon(w), character(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(true), hasRing(false) {}
/*
* Square::Square(Shield s)
* Declares the following constructors, character, Shield, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square(Shield s)
    : shield(s), character(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(true), hasWeapon(false), hasRing(false) {}
/*
* Square::Square(Armour a)
* Declares the following constructors, character, armour, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square(Armour a)
    : armour(a), character(), hasItem(true), hasEnemy(false), hasArmour(true), hasShield(false), hasWeapon(false), hasRing(false) {}
/*
* Square::Square(Ring r)
* Declares the following constructors, character, ring, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square(Ring r)
    : ring(r), character(), hasItem(true), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(true) {}
/*
* Square::Square()
* Declares the following constructors, character, weapon, hasItem etc.
*
* parameter: none
*
* return:  none
*/
Square::Square()
    : weapon(), character(), hasItem(false), hasEnemy(false), hasArmour(false), hasShield(false), hasWeapon(false), hasRing(false) {}
