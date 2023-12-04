#pragma once
#include<string>
#include <vector>
using namespace std;
class Item {
public:
	string name;
	int weight;
	Item(string n, int w);
	Item();
	virtual void displayInfo();
	virtual string itemType();
	bool hasItemType(const vector<Item*>& Inventory);
};