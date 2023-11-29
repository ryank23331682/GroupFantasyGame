#include"Character.h"
class Player : public Character {
public:
	int gold;

	Player(std::string n, int hp, int att, int def)
		: Character(n, hp, att, def), gold(0) {}


};