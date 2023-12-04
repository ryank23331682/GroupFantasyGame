#include "Character.h"
#include<iostream>
#include <string>
#include <list>
using namespace std;

/**
 * @brief Default constructor for the Character class.
 *
 * Initializes a Character object with default values for attack, defence,
 * health, strength, defense chance, and attack chance.
 */
Character::Character()
    : attack(0), defence(0), health(0), strength(0), defenseChance(0), attackChance(0)
{
}

/**
 * @brief Parameterized constructor for the Character class.
 *
 * Initializes a Character object with specified values for race, attack,
 * defence, health, strength, defense chance, and attack chance.
 *
 * @param race The race of the character.
 * @param attack The attack points of the character.
 * @param defence The defense points of the character.
 * @param health The health points of the character.
 * @param strength The strength of the character.
 * @param defenseChance The chance of successfully defending against an attack.
 * @param attackChance The chance of successfully executing an attack.
 */
Character::Character(std::string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance)
    : race(race), attack(attack), defence(defence), health(health), strength(strength), defenseChance(defenseChance), attackChance(attackChance)
{
}

/**
 * @brief Updates the enemy based on the time of day.
 *
 * @param isDay A boolean indicating whether it is day or night.
 */
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