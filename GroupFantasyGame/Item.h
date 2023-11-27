#include <string>
using namespace std;

class Item
{
public:
	Item();
	Item(string name, int weight, int attackValue, int defenseVaue);
	string name;
	int weight;
	int attackValue;
	int defenseVaue;
};

