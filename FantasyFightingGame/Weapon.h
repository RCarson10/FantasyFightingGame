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
	int getCost() { return cost; }
	void setCost(int c) { cost = c; }
	int getDamage() { return damage; }
	void setDamage(int d) { damage = d; }
	string getName() { return name; }
	void setName(string n) { name = n; }
	string getTier() { return tier; }
	void setTier(string t) { tier = t; }
	virtual void use() = 0;

};
class pistol : public Weapon
{
public:
	pistol() : Weapon(cost, damage, name, tier) {}
		
	void use() 
	{ 
		setDamage(rand() % 100 + 50) ;
		setCost(150);
		setName("Pistol");
		setTier("Low");
	};


};
class rifle : public Weapon
{
public:
	rifle() : Weapon(cost, damage, name, tier) {}

	void use() 
	{ 
		setDamage(rand() % 115 + 85); 
		setCost(300);
		setName("Rifle");
		setTier("Mid");
	};

};

class rayGun : public Weapon
{
public: 
	rayGun() : Weapon(cost, damage, name, tier) {}

	void use() 
	{ 
		setDamage(rand() % 150 + 135); 
		setCost(650);
		setName("RayGun");
		setTier("High");
	};

};





#endif



