#ifndef ENEMY_H
#define ENEMY_H


#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

class Enemy
{
private:
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
	int getdamage() { return damage; }
	int setdamage(int d) { damage = d; }
	bool isHp0() { return hp == 0; }
	virtual void use() = 0;


};
class CoronaBoss
{
public:
	CoronaBoss()
		use() void;
	use() void;
};
class CoronaSpecial
{
public:
	CoronaSpecial()
		use()  void;
	use() void;
};
class CoronaGrunt
{
public:
	CoronaGrunt()
		use() void;
	use()void; 
};






#endif