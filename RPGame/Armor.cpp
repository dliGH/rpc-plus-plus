#include "Armor.h"


Armor::Armor() : Armor(1000) {}

/*
Like the Item contstructor, takes an int as a parameter representing ID
Armor IDs fall in the range 1000-1999 (hopefully we won't make more than 1000)
Invalid IDs/an ID of 1000 will create default Armor (pants)
*/

Armor::Armor(int i)
{
	id = i;
	switch (i)
	{
	case 1000:
	default:
		id = 1000;
		name = "Sturdy Pants";
		description = "A good sturdy pair of pants.";
		protection = 2;
		break;
	case 1001:
		name = "Breastplate";
		description = "A simple piece of armor that provides decent protection.";
		protection = 5;
		break;
	}
}

Armor::~Armor()
{
}

int Armor::getProtection()
{
	return protection;
}
