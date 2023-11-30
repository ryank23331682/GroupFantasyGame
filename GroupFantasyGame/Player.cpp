#include"Character.h"
class Player : public Character {
public:
	int gold;

	Player(std::string n, int str, int hp, int att, int def)
		: Character(n, hp, str , att, def), gold(0) {}


};