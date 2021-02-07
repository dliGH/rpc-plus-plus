#include "StateMachine.h"
#include "Enemy.h"

BattleState::BattleState(StateMachine* sm) : GameState(sm) {}
BattleState::~BattleState(){}

void BattleState::enter() 
{
	Enemy generate(mySM->myPlayer->getLevel());
	battle(generate);
}

void BattleState::exit(){}

void BattleState::battle(Enemy bob)
{
	while (mySM->myPlayer->getHP() > 0 && bob.getHP() > 0)
	{
		std::cout << "\n";
		std::cout << NINTENDO << bob.nameline() << "\n" RESET;
		std::cout << SPOTIFY "   " << bob.healthline() << "\n" RESET;
		std::cout << ZELDABLUE << mySM->myPlayer->nameline() << "\n" RESET;
		std::cout << SPOTIFY "   " << mySM->myPlayer->healthline() << "\n" RESET;
		int choice = -1;
		string choiceline;
		while (true)
		{
			std::cout << "(1) Attack\t(2) Check\t(3) My Stats\nChoose: ";
			std::getline(std::cin, choiceline);
			try { choice = std::stoi(choiceline); }
			catch (std::exception ex) { choice = -1; }
			if (choice == 1)
			{
				Sleep(500);
				std::cout << ">" << mySM->myPlayer->attack(bob) << "\n";
				Sleep(500);
				if (bob.getHP() == 0) break;
				std::cout << ">" << bob.attack(*mySM->myPlayer) << "\n";
				Sleep(500);
				break;
			}
			else if (choice == 2)
			{
				std::cout << PLUM << bob.enemyinfo() << "\n" << RESET;
				Sleep(500);
				break;
			}
			else if (choice == 3)
			{
				std::cout << PLUM << mySM->myPlayer->stats() << "\n" << RESET;
				Sleep(500);
				break;
			}
			std::cout << SPONGEBOB "Invalid input!\n" RESET;
		}
	}
	if (mySM->myPlayer->getHP() > 0) 
	{ 
		std::cout << GOLD "Victory!\n\n" RESET; 
		std::cout << "Press Enter to continue...";
		std::cin.ignore();
	}
	else { 
		std::cout << RED "Defeat :(\n\n" RESET; 
		std::cout << "Press Enter to continue...";
		std::cin.ignore();
	}
	//mySM->myPlayer->restore();
	mySM->changestate(StateMachine::INTERMEDIATE_STATE);
}