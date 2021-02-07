#include "StateMachine.h"

CreditState::CreditState(StateMachine *sm) : GameState(sm) {}

CreditState::~CreditState() {}

void CreditState::enter()
{
	std::cout << "Programmed by Derek Li and Kevin Zhou\n\n";
	std::cout << "Title Screen:\t\"Classy 8-Bit\" by Eric Matyas\n\t\tsoundimage.org\n\n";
	std::cout << "Sound Effects:\tLegend of Zelda Sound Effects\n\t\thttp://noproblo.dayjo.org/ZeldaSounds/\n\n";
	std::cout << "Press Enter to return to menu...\n";
	std::cin.ignore();
	mySM->changestate(StateMachine::MENU_STATE);
}