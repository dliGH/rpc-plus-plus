#pragma once
#include <string>
#include <random>
#include <vector>
#include "Weapon.h"
#include "Armor.h"

class Entity
{
	protected:
		string name;
		int level;
		int maxhp;
		int hp;
		int atk;
		int def;
		Weapon myWeapon;
		Armor myArmor;
	public:
		Entity();
		Entity(string n);
		~Entity();
		string attack(Entity& e);
		string stats();
		string nameline();
		string healthline();
		string getName();
		int getLevel();
		int getMaxHP();
		int getHP();
		int getATK();
		int getDEF();
		int getWeapon();
		int getArmor();
};

