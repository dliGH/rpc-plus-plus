#pragma once
#include "Entity.h"
#include <map>
#include "Item.h"

class Player : public Entity
{
private:
	int exp;
	std::map<int, int> inventory;
public:
	struct data {
		int i;
		std::string s;
	};
	//default player constructor
	Player();
	//player for new game
	Player(string playerName);
	//player for loading game
	Player(data d[9]);
	~Player();
	void restore();
	void restore(int r);
	void obtain(int i);
	void use(int i);
	string savefile();
	string profile();
	void gainXP(int x);
	string levelup();
};

