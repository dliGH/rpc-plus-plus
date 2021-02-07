#include "Entity.h"
#include "StateMachine.h"

using std::to_string;

/*
The Default Entity
Level 1, low stats
Carries a stick and wears pants
*/

Entity::Entity()
{
	name = "Default";
	level = 1;
	maxhp = 13;
	hp = 13;
	atk = 5;
	def = 5;
	myWeapon = Weapon();
	myArmor = Armor();
}

Entity::Entity(string n) : Entity()
{
	name = n;
}

Entity::~Entity(){}

// Damage calculation formula stolen from Pokemon, directly modifies opponent's HP
string Entity::attack(Entity& e)	
{
	int random = rand() % 3 - 1;	// Damage is plus or minus 1
	int dmg = (2 * level / 5 + 2) * (atk + myWeapon.getDamage()) / (e.def + e.myArmor.getProtection()) + 2 + random;
	e.hp -= dmg;
	if (e.hp < 0)		// Knock out!
		e.hp = 0;
	return name + " attacked " + e.name + " for " + to_string(dmg) + " damage!";
}

/*
Accessor Methods
Some have strings for aesthetic reasons
*/

string Entity::getName() {
	return name;
}

int Entity::getLevel(){
	return level; 
}
int Entity::getMaxHP() {
	return maxhp;
}
int Entity::getHP() {
	return hp;
}
int Entity::getATK() {
	return atk;
}
int Entity::getDEF() {
	return def;
}
int Entity::getWeapon() {
	return myWeapon.getID();
}
int Entity::getArmor() {
	return myArmor.getID();
}

string Entity::stats()
{
	return "Weapon: " + myWeapon.name + "\nArmor: " + myArmor.name + "\n"
		 + "ATK: " + to_string(atk) + "+" + to_string(myWeapon.getDamage()) + "\t"
		 + "DEF: " + to_string(def) + "+" + to_string(myArmor.getProtection());
}

string Entity::nameline()
{
	return name + ": Level " + to_string(level);
}

string Entity::healthline()
{
	return "Health: " + to_string(hp) + "/" + to_string(maxhp);
}