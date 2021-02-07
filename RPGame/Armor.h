#pragma once
#include "item.h"

class Armor : public Item
{
private:
	int protection;
public:
	Armor();
	Armor(int i);
	~Armor();
	int getProtection();
};