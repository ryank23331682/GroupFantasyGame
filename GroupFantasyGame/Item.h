#pragma once
#include<string>
using namespace std;
class Item {
public:
	string name;
	int weight;
	string category;
	Item(string n, string c, int w);
	Item();
	virtual void displayInfo();
};
