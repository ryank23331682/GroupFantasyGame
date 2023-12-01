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
	// Additional initialization code if needed
}

void UpdateEnemyOnTimeOfDay(Character character)
{

	character. attack = 45;
	character.attackChance = 1.00;
	character.defenseChance = 0.50;

}

