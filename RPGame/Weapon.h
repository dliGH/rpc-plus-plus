#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
	int damage;
public:
	Weapon();
	Weapon(int i);
	~Weapon();
	int getDamage();
};

