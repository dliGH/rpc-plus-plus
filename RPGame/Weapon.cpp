#include "Weapon.h"

Weapon::Weapon() : Weapon(2000) {}

/*
Like the Item contstructor, takes an int as a parameter representing ID
Weapon IDs fall in the range 2000-2999 (hopefully we won't make more than 1000)
Invalid IDs/an ID of 2000 will create a default Weapon (a stick)
*/

Weapon::Weapon(int i)
{
	switch (i)
	{
	case 2000:
	default:
		id = 2000;
		name = "Stick";
		description = "It's a stick.";
		damage = 2;
		break;
	case 2001:
		id = i;
		name = "Sword";
		description = "A simple but effective blade.";
		damage = 5;
		break;
	}
}

Weapon::~Weapon()
{
}

int Weapon::getDamage()
{
	return damage;
}
