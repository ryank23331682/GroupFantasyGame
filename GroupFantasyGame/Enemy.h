#pragma once
#include <string>
#include <list>
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
	void UpdateEnemyOnTimeOfDay(Enemy enemy);

};

