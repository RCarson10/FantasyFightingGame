//My name is Gaj Carson
//This is my own work

#ifndef PLAYER_H
#define PLAYER_H
#include "Asset.h"
#include "Armor.h"
#include "Weapon.h"
#include <cstring>
#include <utility>
#include <iostream>
#include <ctime>
#include<fstream>
#include <vector>

using namespace std;

[Serialiazble]
class Player 
{
private: 
	int hp;
	int lvl;
	int money;
	string name;
	Weapon* uWeapon;
	Armor* uArmor;
	vector<Asset*> Gear;
public:
	Player(int h, int l, int m, string n)
	{
		hp = h;
		name = n;
		money = m;
		lvl = l; 
		srand(time(NULL));	
	}
	string getName() { return name;  }
	string setName(string n) { name = n; }
	int getHp() { return hp; }
	int setHp(int h) { hp = h; }
	int getLvl() { return lvl; }
	int setLvl(int l) { lvl = l; }
	int getMoney() { return money; }
	int setMoney(int m) { money = m; }
	bool isHp0() { return hp == 0; }
	Armor* getArmor(){ return uArmor; }
	Armor* setArmor(Armor* a) { uArmor = a; }
	Weapon* getWeapon() { return uWeapon; }
	Weapon* setWeapon(Weapon* w) { uWeapon = w; }
	string playerSheet()
	{
		cout << "Player Name: " << name << endl;
		cout << "Player HP: " << hp << endl;
		cout << "Player Money: " << money << endl;
		cout << "Player Level: " << lvl << endl;
		cout << "Current weapon: " << uWeapon->getName() << endl;
		cout << "Current armor: " << uArmor->getName() << endl;
		
	}


};









#endif
