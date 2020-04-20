//My name is Gaj Carson
//This is my own work

#ifndef ARMOR_H
#define ARMOR_H

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
	hazmatSuit() : Armor(cost, defense, name, tier){}

	void use() 
	{ 
		setDefense(250); 
		setCost(100);
		setName("HAZMATSUIT");
		setTier("Low");

	};
		

};
class knightArmor : public Armor
{
public:
	knightArmor() : Armor(cost, defense, name, tier) {}

	void use() 
	{ 
		setDefense(500); 
		setCost(250);
		setName("KNIGHTARMOR");
		setTier("Mid");
	};



};
class mechSuit : public Armor
{
public:
	mechSuit() : Armor(cost, defense, name, tier) {}
		void use() 
		{ 
			setDefense(1000);
			setCost(500);
			setName("MECHSUIT");
			setTier("High");
		};


};




#endif



