#ifndef WEAPON.H
#define WEAPON.H

#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

class Weapon
{
protected:
	int damage;
	int cost;
	string name;
	string tier;
public:
	Weapon(int c, int d, string n, string t)
	{
		name = n;
		tier = t;
		cost = c;
		damage = d;
	}
	int getCost() { return cost; }
	int setCost(int c) { cost = c; }
	int getdamage() { return damage; }
	int setdamage(int d) { damage = d; }
	string getName() { return name; }
	string setName(string n) { name = n; }
	string getTier() { return tier; }
	string setTier(string t) { tier = t; }
	virtual void use() = 0;

};
class pistol : public Weapon
{
public:
	pistol(int c, int d, string n, string t) : Weapon(cost, damage, name, tier)
		
	Weapon::use();
};
class rifle : public Weapon
{
public:
	rifle(int c, int d, string n, string t) : Weapon(cost, damage, name, tier)
		
	Weapon::use();
};

class rayGun : public Weapon
{
public: 
	rayGun(int c, int d, string n, string t) : Weapon(cost, damage, name, tier)
		
	Weapon::use();
};





#endif



