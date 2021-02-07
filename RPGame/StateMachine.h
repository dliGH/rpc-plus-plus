#pragma once
//bunch of including stuff here so that we don't need redundancy for the states
#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>  
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>
#include "Player.h"

#define RESET "\x1B[0m";
#define RED "\x1B[31m";
#define GOLD "\x1B[38;2;212;175;55m"
#define SPONGEBOB "\x1B[38;2;247;235;98m"
#define NINTENDO "\x1B[38;2;230;0;18m"
#define SPOTIFY "\x1B[38;2;30;215;96m"
#define ZELDABLUE "\x1B[38;2;56;182;241m"
#define PLUM "\x1B[38;2;221;160;221m"

/*
Forward declarations so everyone knows that everyone else exists
*/
class StateMachine;
class GameState;
class MenuState;
class CreateState;
class LoadState;
class CreditState;
class IntermediateState;
class BattleState;

class StateMachine
{
private:
	std::vector<GameState*> stateslist;
	int currentstate;
public:
	static const int MENU_STATE = 0;
	static const int CREATE_STATE = 1;
	static const int LOAD_STATE = 2;
	static const int CREDIT_STATE = 3;
	static const int INTERMEDIATE_STATE = 4;
	static const int BATTLE_STATE = 5;
	StateMachine();
	~StateMachine();
	void changestate(int s);
	void start();
	Player *myPlayer;
	string saveFile;
};

/*
Parent Class for all states
They all contain a pointer back to their StateMachine
virtual is C++'s version of abstract
*/
class GameState
{
protected:
	StateMachine* mySM;
public:
	GameState() = delete;		// Down with the empty constructor
	GameState(StateMachine* sm);
	virtual ~GameState() = 0;
	virtual void enter() = 0;
	void exit();
};

class MenuState : public GameState
{
public:
	MenuState(StateMachine* sm);
	~MenuState();
	void enter();
	void exit();
};

class IntermediateState : public GameState
{
public:
	IntermediateState(StateMachine* sm);
	~IntermediateState();
	void enter();
	void exit();
};

class BattleState : public GameState
{
public:
	BattleState(StateMachine* sm);
	~BattleState();
	void enter();
	void exit();
	void battle(class Enemy bob);
};

class CreateState : public GameState
{
public:
	CreateState(StateMachine* sm);
	~CreateState();
	void enter();
	void exit();
};

class LoadState : public GameState
{
public:
	LoadState(StateMachine* sm);
	~LoadState();
	void enter();
	void exit();
};

class CreditState : public GameState
{
public:
	CreditState(StateMachine* sm);
	~CreditState();
	void enter();
	void exit();
};
