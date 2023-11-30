#include "Enemy.h"
#include <string>
#include <list>
using namespace std;

Enemy::Enemy()
{
	attack = 0;
	defence = 0;
	health = 0;
	strength = 0;
	defenseChance = 0;
	attackChance = 0;
}
Enemy::Enemy(string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance)
	: race(race), attack(attack), defence(defence), health(health), strength(strength), defenseChance(defenseChance), attackChance(attackChance)
{
	// Additional initialization code if needed
}

void UpdateEnemyOnTimeOfDay(Enemy enemy)
{

	enemy. attack = 45;
	enemy.attackChance = 1.00;
	enemy.defenseChance = 0.50;

}

