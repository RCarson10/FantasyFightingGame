//My name is Gaj Carson
//This is my own work

#ifndef ENEMY_H
#define ENEMY_H


#include <cstring>
#include <utility>
#include <iostream>
#include<ctime>

using namespace std;

class Enemy
{
protected:
	int hp;
	int lvl;
	string name;
	int damage;
	

public:
	Enemy(int h, int l, string n, int d)
	{
		
		hp = h;
		name = n;
		lvl = l;
		damage = d;
	}
	string getName() { return name; }
	void setName(string n) { name = n; }
	int getHp() { return hp; }
	void setHp(int h) { hp = h; }
	int getLvl() { return lvl; }
	void setLvl(int l) { lvl = l; }
	int getDamage() { return damage; }
	void setDamage(int d) { damage = d; }
	bool isHp0() { return hp <= 0; }
	virtual void use() = 0;


};
class CoronaBoss : public Enemy
{
public:
	CoronaBoss(): Enemy(750, 10, "Boss", 0) 
	{
		setDamage((rand() % 200) + 151);
	}

	void use() {};
};
class CoronaSpecial : public Enemy
{
public:
	CoronaSpecial(): Enemy(350, (rand() % 9 + 5), "Special", ((rand() % 150) + 101)) {}
	void use()
	{
		
	};


};
class CoronaGrunt : public Enemy
{
public:
	CoronaGrunt() : Enemy(100, (rand() % 5 + 1), "Grunt", (damage* rand() % 75)+ 50) {}
	void use()
	{

	};
	
	
};






#endif