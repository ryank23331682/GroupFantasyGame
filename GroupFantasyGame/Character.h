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

