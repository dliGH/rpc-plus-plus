#include "Player.h"

/*
The Default Player
Same stats as the Default Entity, plus
One Experience, empty inventory, a sword, and basic armor
*/

Player::Player()
{
	name = "Hero";
	exp = 1;
	inventory = std::map<int, int>();
	myWeapon = Weapon(2001);
	myArmor = Armor(1001);
}

Player::Player(string playerName) : Entity(playerName)
{
	exp = 1;
	inventory = std::map<int, int>();
	myWeapon = Weapon(2001);
	myArmor = Armor(1001);
}

//need a constructor that takes an array for loading
Player::Player(data d[9]){
	name = d[0].s;
	level = d[1].i;
	maxhp = d[2].i;
	hp = d[3].i;
	atk = d[4].i;
	def = d[5].i;
	myWeapon = Weapon(d[6].i);
	myArmor = Armor(d[7].i);
	exp = d[8].i;
}


Player::~Player()
{
}

void Player::restore()
{
	hp = maxhp;
}

void Player::restore(int r)
{
	hp += r;
	if(hp > maxhp)
		hp = maxhp;
}

/*
Inventory Management
The inventory is a map, where keys correspond to Item IDs and values
represent how many the Player is carrying
*/
void Player::obtain(int i)
{
	inventory[i]++;
	if (inventory[i] > 999)
		inventory[i] = 999;
}

void Player::use(int i)
{
	if (inventory[i] <= 0)
		inventory[i] = 0;
	else
	{
		inventory[i]--;
		// Regular items, pretty much potions
		if (i > 0 && i < 1000)
		{
			if (i == 1) restore(15);
			else if (i == 2) restore(25);
			else if (i == 3) restore(50);
			else if (i == 4) restore(100);
		}
		// Equip Armor
		else if (i >= 1000 && i < 2000)
		{
			obtain(myArmor.getID());
			myArmor = Armor(i);
		}
		// Equip Weapon
		else if (i >= 2000 && i < 3000)
		{
			obtain(myWeapon.getID());
			myWeapon = Weapon(i);
		}
	}
}

void Player::gainXP(int x)
{
	exp += x;
	if (exp > 1000000)
		exp = 1000000;
	int i = 1;
	// Pokemon formula: Total exp = Level cubed
	while (exp >= i * i * i)
		i++;
	for (int k = level; k <= i; k++)
		levelup();
}

std::string Player::levelup()
{
	level++;
	maxhp = 3 * level + 10;
	atk = 2 * level + 5;
	def = 2 * level + 5;
	return "Reached level " + std::to_string(level) + "!\n";
}

string Player::savefile()
{
	return
		name + "\n" +
		std::to_string(level) + "\n" +
		std::to_string(maxhp) + "\n" + 
		std::to_string(hp) + "\n" + 
		std::to_string(atk) + "\n" + 
		std::to_string(def) + "\n" + 
		std::to_string(myWeapon.getID()) + "\n" + 
		std::to_string(myArmor.getID()) + "\n" + 
		std::to_string(exp) +"\n";
	
	//for reference, name, level, maxhp, hp, atk, def. Weapon, Armor
}

//for more appealing profile

string Player::profile()
{
	return
		"NAME:  " + name + "\n" +
		"LVL:   " + std::to_string(level) + "\n" +
		"HP:    " + std::to_string(hp) + "/" + std::to_string(maxhp) + "\n" + 
		"ATK:   " + std::to_string(atk) + "\n" + 
		"DEF:   " + std::to_string(def) + "\n" + 
		"EXP:   " + std::to_string(exp) +"\n";
}


