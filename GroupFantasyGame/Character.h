#pragma once
#include <string>
#include <list>
using namespace std;

class Character
{
public:
	Character();
	Character(string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance);
	string race;
	int attack;
	int defence;
	int health;	
	int strength;
	double defenseChance;
	double attackChance;
	void UpdateEnemyOnTimeOfDay(Character enemy);

};

<<<<<<< HEAD
	void equipItem(const Item& item) {
		// Implement logic to modify character attributes based on the equipped item
		// You may need to add more attributes or methods to the Character class for this.
	}
};
=======
>>>>>>> origin
