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


using namespace std;

class Player 
{
private: 
	int hp;
	int lvl;
	int money;
	string name;
	Weapon* uWeapon;
	Armor* uArmor;
	
public:
	Player(int h = 100, int l = 1 , int m = 0, string n = "Player")
	{
		hp = h;
		name = n;
		money = m;
		lvl = l; 
		srand(time(NULL));
		uWeapon = new pistol();
		uArmor = new hazmatSuit();
	}
	Player(const Player& p) 
	{
		hp = p.hp;
		name = p.name;
		money = p.money;
		lvl = p.lvl;
		
		if (p.getWeapon()->getName() == "Pistol")
		{
			uWeapon = new pistol(p.getWeapon()->getCost(), p.getWeapon()->getDamage(), p.getWeapon()->getName(), p.getWeapon()->getTier());
		}

		if (p.getWeapon()->getName() == "Rifle")
		{
			uWeapon = new rifle(p.getWeapon()->getCost(), p.getWeapon()->getDamage(), p.getWeapon()->getName(), p.getWeapon()->getTier());
		}

		if (p.getWeapon()->getName() == "RayGun")
		{
			uWeapon = new pistol(p.getWeapon()->getCost(), p.getWeapon()->getDamage(), p.getWeapon()->getName(), p.getWeapon()->getTier());
		}

		if (p.getArmor()->getName() == "HAZMATSUIT")
		{
			uArmor = new hazmatSuit(p.getArmor()->getCost(), p.getArmor()->getDefense(), p.getArmor()->getName(), p.getArmor()->getTier());
		}
		if (p.getArmor()->getName() == "KNIGHTARMOR")
		{
			uArmor = new knightArmor(p.getArmor()->getCost(), p.getArmor()->getDefense(), p.getArmor()->getName(), p.getArmor()->getTier());
		}
		if (p.getArmor()->getName() == "MECHSUIT")
		{
			uArmor = new mechSuit(p.getArmor()->getCost(), p.getArmor()->getDefense(), p.getArmor()->getName(), p.getArmor()->getTier());
		}
	}
	string getName() { return name;  }
	void setName(string n) { name = n; }
	int getHp() { return hp; }
	void setHp(int h) { hp = h; }
	int getLvl() { return lvl; }
	void setLvl(int l) { lvl = l; }
	int getMoney() { return money; }
	void setMoney(int m) { money = m; }
	bool isHp0() { return hp <= 0; }
	Armor* getArmor()const{ return uArmor; }
	void setArmor(Armor* a) { uArmor = a; }
	Weapon* getWeapon()const { return uWeapon; }
	void setWeapon(Weapon* w) { uWeapon = w; }
	void playerSheet()
	{
		cout << "Player Name: " << getName() << endl;
		cout << "Player HP: " << getHp() << endl;
		cout << "Player Money: " << getMoney() << endl;
		cout << "Player Level: " << getLvl() << endl;
		if(uWeapon != nullptr)
		cout << "Current weapon: " << uWeapon->getName() << endl;
		if(uArmor != nullptr)
		cout << "Current armor: " << uArmor->getName() << endl;
		
	}


};









#endif
