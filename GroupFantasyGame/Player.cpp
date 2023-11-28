#include"Character.h"
class Player : public Character {
public:
	int gold;

	Player(std::string n, int hp, int att, int def)
		: Character(n, hp, att, def), gold(0) {}

	int calculateDamage() const override {
		return 5; // Player's special ability: always deals 5 extra damage
	}
};