#include "Enemy.h"

/*
The Default Enemy
A default Entity except it's named Skeleton instead of Default
*/
Enemy::Enemy()
{
	name = "Skeleton";
	description = "Spooky scary skeleton.";
}

Enemy::Enemy(int playerLVL)
{
	//generate array of enemies -> randomly generate something based on current EXP value --> go into battle
	//varying names, attack, defense, exp, item drop

	
	//somehow implement percent chance of dropping? nvm no time for now
	//bool itemDrop;

	//use and vector and randomly generate an enemy name
	std::vector<std::string> enemies;
	enemies.push_back("Slime");
	enemies.push_back("Skeleton");
	enemies.push_back("Ogre");
	enemies.push_back("Giant");
	enemies.push_back("Goblin");

	//enemy descriptions
	std::vector<std::string> enemyDesc;
	enemyDesc.push_back("Squish.");
	enemyDesc.push_back("Spooky scary skeleton.");
	enemyDesc.push_back("It looks like it wants to eat you.");
	enemyDesc.push_back("An absolute unit.");
	enemyDesc.push_back("Always looking for the cash money.");

	int randInt = (rand() % enemies.size());
	name = enemies.at(randInt);
	description = enemyDesc.at(randInt);

	//randomly generate HP, attack, defense, level with accordance to player level and assigning values
	
	hp = (200 + rand() % 32) * playerLVL / 100 + playerLVL + 10;
	atk = (200 + rand() % 32) * playerLVL / 100 + 5;
	def = (200 + rand() % 32) * playerLVL / 100 + 5;
}

Enemy::~Enemy(){}

std::string Enemy::enemyinfo()
{
	return description + "\n" + stats();
}