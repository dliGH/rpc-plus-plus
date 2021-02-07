#include "StateMachine.h"

// High key stolen from Derek's Graphics project
// The StateMachine has a vector of pointers to States, and
// Each GameState has a pointer to the StateMachine
StateMachine::StateMachine()
{
	currentstate = MENU_STATE;
	stateslist.push_back(new MenuState(this));
	stateslist.push_back(new CreateState(this));
	stateslist.push_back(new LoadState(this));
	stateslist.push_back(new CreditState(this));
	stateslist.push_back(new IntermediateState(this));
	stateslist.push_back(new BattleState(this));
	myPlayer = &Player();

	//seeding in constructor so nothing weird
	srand (time(NULL));
}

/*
Once the StateMachine is done it deletes everything in the list
Because we clean up after ourselves
*/
StateMachine::~StateMachine()
{
	for (int i = 0; i < stateslist.size(); i++)
		delete stateslist[i];
}

// Changes between states, parameter should be taken from StateMachine constants
void StateMachine::changestate(int s)
{
	// Only valid States allowed
	if (s < 0 || s >= stateslist.size()) {
		return;
	}

	stateslist[currentstate]->exit();	// Apparently pointers use arrows instead of dots
	stateslist[s]->enter();
	currentstate = s;
}

// Start the game
void StateMachine::start()
{
	stateslist[MENU_STATE]->enter();
}