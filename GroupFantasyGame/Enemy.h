#pragma once
#include <string>
using namespace std;

class Enemy
{
public:
	Enemy();
	Enemy(string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance);
	string race;
	int attack;
	int defence;
	int health;
	int strength;
	double defenseChance;
	double attackChance;

};

