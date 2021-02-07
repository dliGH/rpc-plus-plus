#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
	string description;
public:
	Enemy();
	Enemy(int playerLvl);
	~Enemy();
	string enemyinfo();
};

