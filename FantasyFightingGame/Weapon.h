//My name is Gaj Carson
//This is my own work

#ifndef WEAPON_H
#define WEAPON_H

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
	int getCost()const { return cost; }
	void setCost(int c) { cost = c; }
	int getDamage()const { return damage; }
	void setDamage(int d) { damage = d; }
	string getName()const { return name; }
	void setName(string n) { name = n; }
	string getTier()const { return tier; }
	void setTier(string t) { tier = t; }
	virtual void use() = 0;

};
class pistol : public Weapon
{
public:
	pistol() : Weapon(150, ((rand() % 100) + 50), "Pistol", "Low") {}
	pistol(int c, int d, string n, string t): Weapon(c,d,n,t)
	{
		cost = c;
		damage = d;
		name = n;
		tier = t;

	}
		
	void use() 
	{ 
		
	};


};
class rifle : public Weapon
{
public:
	rifle() : Weapon(300, ((rand() % 115) + 85), "Rifle", "Mid") {}
	rifle(int c, int d, string n, string t) : Weapon(c, d, n, t)
	{
		cost = c;
		damage = d;
		name = n;
		tier = t;

	}
	void use() 
	{ 
	};

};

class rayGun : public Weapon
{
public: 
	rayGun() : Weapon(650, ((rand() % 150) + 135), "RayGun", "High") {}
	rayGun(int c, int d, string n, string t) : Weapon(c, d, n, t)
	{
		cost = c;
		damage = d;
		name = n;
		tier = t;

	}
	void use() 
	{ 
		
	};

};





#endif



