#ifndef PLAYER_H
#define PLAYER_H

#include "Armor.h"
#include "Weapon.h"
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

class Player
{
private: 
	int hp;
	int lvl;
	int money;
	string name;
	Weapon uWeapon;
	Armor uArmor;

public:
	Player(int h, int l, int m, string n)
	{
		hp = h;
		name = n;
		money = m;
		lvl = l; 
	}
	string getName() { return name;  }
	string setName(string n) { name = n; }
	int getHp() { return hp; }
	int setHp(int h) { hp = h; }
	int getLvl() { return lvl; }
	int setLvl(int l) { lvl = l; }
	int getMoney() { return money; }
	int setMoney(int m) { money = m; }


};









#endif
