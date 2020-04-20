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
	void setCost(int c) { cost = c; }
	int getDefense() { return defense; }
	void setDefense(int d) { defense = d; }
	string getName() { return name;  }
	void setName(string n) { name = n; }
	string getTier() { return tier; }
	void setTier(string t) { tier = t; }
	virtual void use() = 0;


};
class hazmatSuit : public Armor
{
public:
	hazmatSuit() : Armor(100, 250, "HAZMATSUIT", "Low"){}

	void use() 
	{ 
		
	};
		

};
class knightArmor : public Armor
{
public:
	knightArmor() : Armor(500, 250, "KNIGHTARMOR", "Mid") {}

	void use() 
	{ 
		
	};



};
class mechSuit : public Armor
{
public:
	mechSuit() : Armor(1000, 500, "MECHSUIT", "High") {}
		void use() 
		{ 
			
		};


};




#endif



