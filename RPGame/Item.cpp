#include "Item.h"

// Delegated Constructor: empty constructor calls Item(int i) with i==0
Item::Item() : Item(0) {}

/*
Item constructor takes an int as its parameter to represent ID, and
initializes accordingly. Invalid IDs/an ID of 0 will create a default Item.
Generic Item IDs fall in the range 0-999
*/

Item::Item(int i)
{
	id = i;
	switch (i)
	{
	case 0:
	default:
		id = 0;
		name = "Default Teapot";
		description = "Wonderful for brewing the piping hot tea you're about to spill.";
		break;
	case 1:
		name = "Potion";
		description = "A delicious healing tonic.";
		break;
	}
}

Item::~Item()
{
}

int Item::getID()
{
	return id;
}

string Item::toString(){
	return name + "\n" + description;
}