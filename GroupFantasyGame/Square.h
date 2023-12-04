#include "Item.h"
#include "Character.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Shield.h" 

class Square {
public:
	Item* item;
	bool hasEnemy;
	Character character;
	void displayInfo();
	Item* getItem() const { return item; }
	Square(Character c) : item(nullptr), hasEnemy(true), character(c) {}
	Square(Weapon w) : item(new Weapon(w)), hasEnemy(false) {}
	Square(Armour a) : item(new Armour(a)), hasEnemy(false) {}
	Square(Shield s) : item(new Shield(s)), hasEnemy(false) {}
	Square(Ring r) : item(new Ring(r)), hasEnemy(false) {}
	Square() : item(nullptr), hasEnemy(false) {}
private:

};


