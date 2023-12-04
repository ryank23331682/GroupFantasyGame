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
	void UpdateEnemyOnTimeOfDay(bool isDay);
	int defendMove(int& incomingDamage, bool ISDAY);
	int attackMove(Character& enemy, bool isDay);
	void applySpecialAbilities(int& actualDamage, bool isDay);

};

