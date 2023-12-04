#include "Character.h"
#include <string>
#include <list>
using namespace std;

Character::Character()
{
	attack = 0;
	defence = 0;
	health = 0;
	strength = 0;
	defenseChance = 0;
	attackChance = 0;
}
Character::Character(string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance)
	: race(race), attack(attack), defence(defence), health(health), strength(strength), defenseChance(defenseChance), attackChance(attackChance)
{

}

void Character::UpdateEnemyOnTimeOfDay(bool isDay)
{
	if (isDay)
	{
		attack = 25;
		defence = 10;
		attackChance = 0.25;
		defenseChance = 0.25;
	}
	else
	{
		attack = 45;
		defence = 25;
		attackChance = 1.00;
		defenseChance = 0.50;
	}
}

