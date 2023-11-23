#pragma once
class Enemy
{
public:
	Enemy();
	Enemy(int attack, int defence);
	int attack;
	int defence;
	int health;	
	int strength;
	double defenseChance;
	double attackChance;

};

