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
	Enemy* Boss = new CoronaBoss(1000, 10, "Boss", rand() % 500 + 150);
	int health, level, money;
	string name;
	Player uPlayer(health, level, money, name);
	int result;
	do
	 {
		
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
		else if (result == 0)//Read in a serialized file
		{
			cout << "Please enter in the name of the file you want to load" << endl;
			ifstream fin("input.in");
			if (!fin)
			{
				cout << "FIle not found ... exiting.";
				exit(2);
			}
			int health, level, money;
			string name;
			Weapon* usrWeapon;
			Armor* usrArmor;
			while (fin >> health >> level >> money >> name)
			{
				Player uPlayer(health, level, money, name);
			}
		}
		else
			cout << "Please enter a 1 or 0" << endl;
		
		

	}while (uPlayer.isHp0() == false || CoronaBoss->isHp0()== false);
	

	return 0;
}
void userInput(int n)
{
	string r;
	cout << "Select 0 to go to the store, 1 to go to the Quarantine Zone, and 3 to save your player " << endl;
	cin >> r;

}
string playerSheet()
{
	cout << 
}