#include "StateMachine.h"
#include "Player.h"


GameState::GameState(StateMachine* sm)
{
	mySM = sm;
}

GameState::~GameState(){}

void GameState::exit() 
{
	system("CLS");
}