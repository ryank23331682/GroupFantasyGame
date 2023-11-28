#pragma once
#include<string>
using namespace std;
class Item {
public:
	string name;
	int weight;
	Item(string n, int w);
	Item();
	virtual void displayInfo();
};