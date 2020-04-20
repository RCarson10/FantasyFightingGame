//My name is Gaj Carson
//This is my own work

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
void savePlayer(Player u);
void userInput(Player u);
Player store(Player u);
Player quarantineZone(Player u, CoronaBoss Boss);

int main()
{
	CoronaBoss boss;//Initializing Boss and player so i can set the condition for the loop
	Enemy* Boss = &boss;
	int health, level, money;
	string name;
	Player uPlayer;
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
	
	ifstream fin("input.in");
	if (!fin)
	{
		cout << "File not found ... exiting.";
		exit(2);
	}
	int health, level, money;
	string name;
	while (fin >> health >> level >> money >> name)
	{
		uPlayer.setHp(health);
		uPlayer.setLvl(level);
		uPlayer.setMoney(money);
		uPlayer.setName(name);
		
		Weapon* wp;
		char ch;
		fin >> ch;
		if (ch != 'x')//read in weapon
		{
			
			fin.putback(ch);
			int damage, cost;
			string  name, tier;
			fin >> damage >> cost >> name >> tier;
			if (name == "Pistol")
			{
				wp = new pistol();
				wp->setCost(cost);
				wp->setDamage(damage);
				wp->setName(name);
				wp->setTier(tier);
				uPlayer.setWeapon(wp);

			}
			else if (name == "Rifle")//rifle
			{
				wp = new rifle();
				wp->setCost(cost);
				wp->setDamage(damage);
				wp->setName(name);
				wp->setTier(tier);
				uPlayer.setWeapon(wp);

			}
			else
			{
				wp = new rayGun();
				wp->setCost(cost);
				wp->setDamage(damage);
				wp->setName(name);
				wp->setTier(tier);
				uPlayer.setWeapon(wp);
			}
			//rayGun
		}
		else uPlayer.setWeapon(nullptr);
		Armor* ar;
		fin >> ch;
		if (ch != 'x')//read in armor
		{
			
			fin.putback(ch);
			int defense, cost;
			string  name, tier;
			fin >> defense >> cost >> name >> tier;
			if (name == "HAZMATSUIT")
			{
				ar = new hazmatSuit();
				ar->setCost(cost);
				ar->setDefense(defense);
				ar->setName(name);
				ar->setTier(tier);
				uPlayer.setArmor(ar);
			}
			else if (name == "KNIGHTARMOR")
			{
				ar = new knightArmor();
				ar->setCost(cost);
				ar->setDefense(defense);
				ar->setName(name);
				ar->setTier(tier);
				uPlayer.setArmor(ar);
			}
			else
			{
				ar = new mechSuit();
				ar->setCost(cost);
				ar->setDefense(defense);
				ar->setName(name);
				ar->setTier(tier);

			}
		}
		
		else uPlayer.setArmor(nullptr);
	}
}
else
	cout << "Please enter a 1 or 0" << endl;
do{
	int input;
	cout << "Enter 1 if you want to view your character sheet.  " << endl;
	cin >> input;
	if (input == 1)
	{
		uPlayer.playerSheet();
		userInput(uPlayer);
	}
	userInput(uPlayer);

	
		
		

}while (uPlayer.isHp0() == false || Boss->isHp0()== false);
	

	return 0;
}
void userInput(Player u)//Using three numbers and calling the functions based on their choice
{
	int r;
	cout << "Select 0 to go to the store, 1 to go to the Quarantine Zone, 2 to save your player, ";
	cout << " or 3 to view your character sheet." << endl;
	cin >> r;
	if (r == 0)
	{
		store(u);
	}
	else if (r == 1) 
	{
		CoronaBoss boss;
		Enemy* Boss = &boss;
		quarantineZone(u,boss);
	}

	else if (r == 2)
	{ 
		savePlayer(u);
		exit(20);
	}
	else if (r == 3)
	{
		u.playerSheet();
		userInput(u);
	}
	else
		cout << "Please enter a 1 or 0" << endl;
}
Player store(Player u)//The store will have armor available depending on their level.
{
	cout << "Welcome to the store" << endl;
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
	
	
	
	if(u.getLvl() <= 3)//Must meet requirements of each weapon or armor
	{
		cout << "Enter 1 to buy hazmat, 2 for pistol " << endl;
		cout << H->getName() << " " << H->getCost() << " " << H->getTier() << endl;
		cout << P->getName() << " " << P->getCost() << " " << P->getTier() << endl;
	}
	 if (u.getLvl() >= 7)
	{
		cout << "Enter 3 to buy knightSuit, 4 for rifle " << endl;
		cout << K->getName() << " " << K->getCost() << " " << K->getTier() << endl;
		cout << R->getName() << " " << R->getCost() << " " << R->getTier() << " " << endl;

	}
	if(u.getLvl() >= 9)
	{
		cout << "Enter 5 to buy mechSuit, 6 for rayGun " << endl;
		cout << M->getName() << " " << M->getCost() << " " << M->getTier() << endl;
		cout << rG->getName() << " " << rG->getCost() << " " << rG->getTier() << endl;
		

	}
	cout << "What would you like to buy?";
	cin >> purchase;
	if (purchase == 1)
	{
		if (u.getMoney() - H->getCost() < 0)//Verifying if they have enough money
		{
			cout << "You do not have enough cash"<< endl;
		}
		else
		{
			u.setMoney(u.getMoney() - H->getCost());
			u.setArmor(H);
		}
		userInput(u);
	}
	else if (purchase == 2)
	{
		if (u.getMoney() - P->getCost() < 0)
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney() - P->getCost());
			u.setWeapon(P);
		}
		userInput(u);
	}
	else if (purchase == 3)
	{
		if(u.getMoney() - K->getCost() < 0)
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney() - K->getCost());
			u.setArmor(K);
		}
		userInput(u);
	}
	else if (purchase == 4)
	{
		if (u.getMoney() - R->getCost() < 0)
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney() - R->getCost());
			u.setWeapon(R);
		}
		userInput(u);
	}
	else if (purchase == 5)
	{
		if (u.getMoney() - M->getCost() < 0)
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney() - M->getCost());
			u.setArmor(M);
		}
		userInput(u);
	}
	else if (purchase == 6)
	{
		if (u.getMoney() - rG->getCost() < 0)
		{
			cout << "You do not have enough cash" << endl;
		}
		else
		{
			u.setMoney(u.getMoney() - rG->getCost());
			u.setWeapon(rG);
		}
		userInput(u);
	}
	else
	userInput(u);
	return u;
}
void savePlayer(Player u)//Player will exit the game after saving 
{
	string file;
	ofstream userfile("input.in");
	userfile << u.getHp() << " " << u.getLvl() << " " << u.getMoney() << " " << u.getName() << endl;
	//see if there is a weapon 
	
	if (u.getWeapon() != nullptr)
	{
		userfile << u.getWeapon()->getDamage() << " " << u.getWeapon()->getCost() << " "
			<< u.getWeapon()->getName() << " " << u.getWeapon()->getTier() << endl;
	}
	else
		userfile << "x" << endl;
	if (u.getArmor() != nullptr)
	{
		userfile << u.getArmor()->getDefense() << " " << u.getArmor()->getCost() << " "
			<< u.getArmor()->getName() << " " << u.getArmor()->getTier() << endl;

	}
	else
		userfile << "x" << endl;
	userfile.close();
	
}
Player quarantineZone(Player u, CoronaBoss c)//Player will have the option to keep fighting after they win or lose
{
	cout << "Welcome to the Quarantine Zone" << endl;
	if (u.getLvl() < 5)
	{
		CoronaGrunt g;
		Enemy* grunt = &g;
		grunt->getLvl();
		while (u.isHp0() == false && grunt->isHp0() == false)
		{
			grunt->setHp(grunt->getHp() - u.getWeapon()->getDamage());
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - grunt->getDamage());
			
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
		while (u.isHp0() == false && special->isHp0() == false)
		{
			special->setHp(special->getHp() - u.getWeapon()->getDamage());
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - special->getDamage());
			
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
		
		Enemy* BOSS = &c;
	
		while (u.isHp0() == false && BOSS->isHp0() == false)
		{
			BOSS->setHp(BOSS->getHp() - u.getWeapon()->getDamage());
			u.setHp((u.getHp() + u.getArmor()->getDefense()) - BOSS->getDamage());
			
		}
		if (u.isHp0() == true)
		{
			cout << "YOU LOSE" << endl;
			u.setHp(100);
			userInput(u);
		}
		else //After they beat the boss they win the game
		{
			cout << "YOU WIN" << endl;
			cout << "CONGRAGULATIONS!!!, YOU BEAT THE BOSS" << endl;
			u.setHp(100);
			u.setMoney(u.getMoney() + 1000);
			u.setLvl(u.getLvl() + 10);
			userInput(u);
		}
	}
	return u;
}