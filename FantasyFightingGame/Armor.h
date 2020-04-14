#ifndef ARMOR.H
#define ARMOR.H

#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

class Armor
{
protected:
	int defense;
	int cost;
	string name;
	string tier;
public:
	Armor(int c, int d, string n, string t)
	{
		name = n;
		tier = t;
		cost = c;
		defense = d;
	}
	int getCost() { return cost; }
	int setCost(int c) { cost = c; }
	int getDefense() { return defense; }
	int setDefense(int d) { defense = d; }
	string getName() { return name;  }
	string setName(string n) { name = n; }
	string getTier() { return tier; }
	string setTier(string t) { tier = t; }
	virtual void use() = 0;


};
class hazmatSuit : public Armor
{
public:
	hazmatSuit(int c, int d, string n, string t) : Armor(cost, defense, name, tier)

		Armor::use();

};
class knightArmor : public Armor
{
public:
	knightArmor(int c, int d, string n, string t) : Armor(cost, defense, name, tier)

		Armor::use();

};
class mechSuit : public Armor
{
public:
	mechSuit(int c, int d, string n, string t) : Armor(cost, defense, name, tier)

		Armor::use();
};




#endif



