#pragma once
#include <string>
#include <list>
using namespace std;

/**
 * @class Character
 *
 * @brief Character class representing characters in the game.
 *
 * This class defines the properties and methods for characters in the game,
 * including race, attack, defense, health, strength, defenseChance, and attackChance.
 */
class Character
{
public:

	// Declare Properties
	string race; /**< The race of the character. */
	int attack; /**< The attack points of the character. */
	int defence; /**< The defense points of the character. */
	int health; /**< The health points of the character. */
	int strength; /**< The strength of the character. */
	double defenseChance; /**< The chance of successfully defending against an attack. */
	double attackChance; /**< The chance of successfully executing an attack. */

	// Constructors
	  /**
		* @brief Default constructor for the Character class.
		*
		* Initializes a Character object with default values.
		*/
	Character();

	/**
	* @brief Parameterized constructor for the Character class.
	*
	* Initializes a Character object with specified values for race, attack,
	* defence, health, strength, defenseChance, and attackChance.
	*
	* @param race The race of the character.
	* @param attack The attack points of the character.
	* @param defence The defense points of the character.
	* @param health The health points of the character.
	* @param strength The strength of the character.
	* @param defenseChance The chance of successfully defending against an attack.
	* @param attackChance The chance of successfully executing an attack.
	*/
	Character(string race, int attack, int defence, int health, int strength, double defenseChance, double attackChance);

	// Declare Functions
	/**
	 * @brief Updates the enemy based on the time of day.
	 *
	 * @param isDay A boolean indicating whether it is day or night.
	 */
	void UpdateEnemyOnTimeOfDay(bool isDay);

	/**
	 * @brief Executes the defend move during combat.
	 *
	 * @param incomingDamage The incoming damage to be defended against.
	 * @param isDay A boolean indicating whether it is day or night.
	 * @return The remaining health points after defending.
	 */
	int defendMove(int& incomingDamage, bool ISDAY);

	/**
	  * @brief Executes the attack move during combat.
	  *
	  * @param enemy The target enemy character.
	  * @param isDay A boolean indicating whether it is day or night.
	  * @return The remaining health points of the enemy after the attack.
	  */
	int attackMove(Character& enemy, bool isDay);

	/**
	 * @brief Applies special abilities during combat.
	 *
	 * @param actualDamage The actual damage to be modified by special abilities.
	 * @param isDay A boolean indicating whether it is day or night.
	 */
	void applySpecialAbilities(int& actualDamage, bool isDay);

};

