#include<string>
using namespace std;
class Item {
public:
	std::string name;
	std::string category;
	int weight;

	Item(std::string n, std::string cat, int w) : name(n), category(cat), weight(w) {}
};