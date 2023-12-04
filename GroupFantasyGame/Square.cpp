#include "Item.h"
#include "Armour.h"
#include "Ring.h"
#include "Weapon.h"
#include "Square.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void Square::displayInfo()
{
    if (hasEnemy) {
        cout << "This Square has an enemy with race: " << character.race
            << ", attack: " << character.attack << ", defense: "
            << character.defence << ", health: " << character.health << endl;
    }
    else if (item != nullptr) {
        item->displayInfo();  // Use polymorphism to display item information
    }
    else {
        cout << "This square is empty" << endl;
    }
}

