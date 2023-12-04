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
	virtual ~Item(); 
	virtual void displayInfo() = 0;
	virtual string itemType() = 0;
	bool hasItemType(const vector<Item*>& Inventory);
};