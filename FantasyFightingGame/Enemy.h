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
	string setName(string n) { name = n; }
	int getHp() { return hp; }
	int setHp(int h) { hp = h; }
	int getLvl() { return lvl; }
	int setLvl(int l) { lvl = l; }
	int getDamage() { return damage; }
	int setDamage(int d) { damage = d; }
	bool isHp0() { return hp == 0; }
	virtual void use() = 0;


};
class CoronaBoss : public Enemy
{
public:
	CoronaBoss(int h, int l, string n, int d): Enemy(hp, lvl, name, damage) {}
	void use() {};
};
class CoronaSpecial : public Enemy
{
public:
	CoronaSpecial(int h, int l, string n, int d): Enemy(hp, lvl, name, damage) {}
	void use()
	{
		setHp(rand() % 750 + 500 );
		setDamage(rand() % 250 + 100);
		setLvl(rand() % 9 + 5);
		
	};


};
class CoronaGrunt : public Enemy
{
public:
	CoronaGrunt(int h, int l, string n, int d) : Enemy(hp, lvl, name, damage) {}
	void use()
	{
		setHp(rand() % 500 + 100 );
		setDamage(damage * rand() % 100 + 50);
		setLvl(rand() % 5 + 1);

	};
	
	
};






#endif