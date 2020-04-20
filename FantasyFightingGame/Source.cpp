#include <iostream>
#include<cstring>
#include "Enemy.h"
#include "Armor.h"
#include "Player.h"
#include "Weapon.h"
#include <fstream>
#include <utility>
#include <ctime>

using namespace std;

int main()
{
	CoronaBoss boss;
	Enemy* Boss = &boss;
	int health, level, money;
	string name;
	Player uPlayer(health, level, money, name);
	int result;
		
cout << "Select 1 for new character or 0 to load one in" << endl;
cin >> result;
if (result == 1) //Introduction for new players
{
	string uName;
	cout << "What is your name?" << endl;
	cin >> uName;
	uPlayer.setName(uName);
	uPlayer.setHp(100);
	uPlayer.setMoney(0);
	uPlayer.setLvl(1);
	cout << "Welcome to the Fight against Despair!" << endl;
	cout << "In this game you will level up and gain money by figthing in the arena " << endl;
	cout << "You can buy weapons and armor at the store whenever you wish" << endl;
	cout << "You win buy defeating the boss at lvl 10, you may save your character or view your";
	cout << " character sheet at any time." << endl;
}
else if (result == 0)//Read in a previous player file
{
	cout << "Please enter in the name of the file you want to load" << endl;
	ifstream fin("input.in");
	if (!fin)
	{
		cout << "File not found ... exiting.";
		exit(2);
	}
	int health, level, money;
	Weapon* W;
	Armor* A;
	string name;
	while (fin >> health >> level >> money >> name)
	{
		Player uPlayer(health, level, money, name);
	}
}
else
	cout << "Please enter a 1 or 0" << endl;
do{
	int input;
	cout << "Enter 1 if you want to view your character sheet.  " << endl;
	if (input == 1)
	{
		uPlayer.playerSheet();
	}
	userInput(uPlayer);

	
		
		

}while (uPlayer.isHp0() == false || Boss->isHp0()== false);
	

	return 0;
}
void userInput(Player u)
{
	int r;
	cout << "Select 0 to go to the store, 1 to go to the Quarantine Zone, and 2 to save your player. " << endl;
	cin >> r;
	if (r == 0)
	{
		store(u);
	}
	else if (r == 1) 
	{

	}

	else if (r == 2)
	{
		savePlayer(u);
	}
	else
		cout << "Please enter a 1 or 0" << endl;
}
Player store(Player u)//The store will have armor available depending on their level.
{
	int purchase; 
	hazmatSuit h;
	Armor* H = &h;
	pistol p;
	Weapon* P = &p;
	
	knightArmor k;
	Armor* K = &k;
	rifle r;
	Weapon* R = &r;

	mechSuit m;
	Armor* M = &m;
	rayGun rg;
	Weapon* rG = &rg;
	
	cout << "What would you like to buy?";
	
	if(u.getLvl() >= 5)//Must meet requirements of each weapon or armor
	{
		cout << " Enter 1 to buy hazmat, 2 for pistol " << endl;
		cout << K->getName() << K->getCost() << K->getTier() << endl;
		cout << R->getName() << R->getCost() << R->getTier() << endl;

	}
	else if (u.getLvl() >= 8)
	{
		cout << " Enter 3 to buy knightSuit, 4 for rifle " << endl;
		cout << M->getName() << M->getCost() << M->getTier() << endl;
		cout << rG->getName() << rG->getCost() << rG->getTier() << endl;

	}
	else
	{
		cout << " Enter 5 to buy mechSuit, 6 for rayGun " << endl;
		cout << H->getName() << H->getCost() << H->getTier() << endl;
		cout << P->getName() << P->getCost() << P->getTier() << endl;

	}
	if (purchase == 1)
	{
		if (u.setMoney(u.getMoney - H->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash"<< endl;
		}
		else
		{
			u.setMoney(u.getMoney - H->getCost());
			u.setArmor(H);
		}
		userInput(u);
	}
	else if (purchase == 2)
	{
		if (u.setMoney(u.getMoney - P->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney - P->getCost());
			u.setWeapon(P);
		}
		userInput(u);
	}
	else if (purchase == 3)
	{
		if (u.setMoney(u.getMoney - K->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney - K->getCost());
			u.setArmor(K);
		}
		userInput(u);
	}
	else if (purchase == 4)
	{
		if (u.setMoney(u.getMoney - R->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney - R->getCost());
			u.setWeapon(R);
		}
		userInput(u);
	}
	else if (purchase == 5)
	{
		if (u.setMoney(u.getMoney - M->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney - M->getCost());
			u.setArmor(M);
		}
		userInput(u);
	}
	else if (purchase == 6)
	{
		if (u.setMoney(u.getMoney - rG->getCost()) < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney - rG->getCost());
			u.setWeapon(rG);
		}
		userInput(u);
	}
	else
	userInput(u);
}
void savePlayer(Player u)
{
	string file;
	ofstream userfile;
	cout << "What file would you like to save to?" << endl;
	cin >> file;
	userfile.open(file);
	userfile.write((char*)&u, sizeof(u));	
	userfile.close();
	
	exit(0);
}
Player quarantineZone(Player u)
{
	if (u.getLvl() < 5)
	{
		CoronaGrunt g;
		Enemy* grunt = &g;
		grunt->getLvl();
		while (u.isHp0() == false || grunt->isHp0() == false)
		{
			grunt->setHp(grunt->getHp - u.getWeapon()->getDamage);
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - grunt->getDamage);
		}
		if (u.isHp0() == true)
		{
			cout << "YOU LOSE" << endl;
			u.setHp(100);
			userInput(u);
		}
		else
		{
			cout << "YOU WIN" << endl;
			u.setHp(100);
			u.setMoney(u.getMoney() + 50);
			u.setLvl(u.getLvl() + 1);
			userInput(u);
		}
	}
	if (u.getLvl() <= 9 && u.getLvl() >= 5 )
	{
		CoronaSpecial s;
		Enemy* special = &s;
		special->getLvl();
		while (u.isHp0() == false || special->isHp0() == false)
		{
			special->setHp(special->getHp - u.getWeapon()->getDamage);
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - special->getDamage);
		}
		if (u.isHp0() == true)
		{
			cout << "YOU LOSE" << endl;
			u.setHp(100);
			userInput(u);
		}
		else
		{
			cout << "YOU WIN" << endl;
			u.setHp(100);
			u.setMoney(u.getMoney() + 150);
			u.setLvl(u.getLvl() + 2);
			userInput(u);
		}
	}
	if (u.getLvl() == 10)
	{
		CoronaBoss b;
		Enemy* BOSS = &b;
		BOSS->setHp(1000);
		BOSS->setDamage(rand() % 350 + 200);
		BOSS->setLvl(10);
		while (u.isHp0() == false || BOSS->isHp0() == false)
		{
			BOSS->setHp(BOSS->getHp - u.getWeapon()->getDamage);
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - BOSS->getDamage);
		}
		if (u.isHp0() == true)
		{
			cout << "YOU LOSE" << endl;
			u.setHp(100);
			userInput(u);
		}
		else
		{
			cout << "YOU WIN" << endl;
			u.setHp(100);
			u.setMoney(u.getMoney() + 1000);
			u.setLvl(u.getLvl() + 10);
			userInput(u);
		}
	}
}