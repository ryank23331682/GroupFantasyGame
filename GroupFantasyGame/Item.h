#pragma once
#include <string>
using namespace std;
class Item {
public:
	string name;
	string category;
	int weight;

	Item(string name, string category, int weight) : name(name), category(category), weight(weight) {}
};