#include "Square.h"
#include <stdlib.h>

Square::Square(int randomValue){

    if (randomValue == 0) {
        // Initiate an Enemy
        enemy = Enemy("test Enemy", 10, 20, 100, 20, 10, 10);
        hasEnemy = true;
        hasItem = false;
    }
    else {
        // Initiate an Item
        item = Item("test Item", 20, 10, -5);
        hasItem = true;
        hasEnemy = false;
    }
}

Square::Square()
{
}
