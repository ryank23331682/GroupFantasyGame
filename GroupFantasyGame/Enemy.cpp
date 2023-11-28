#include "Enemy.h"
#include <string>
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