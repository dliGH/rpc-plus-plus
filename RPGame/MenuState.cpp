#include "StateMachine.h"

// Linking the required Windows libraries to play sound
#pragma comment(lib, "winmm.lib")

/*
What the Heck Does This Mean?
MenuState constructor calls the superclass constructor with the same parameter
*/
MenuState::MenuState(StateMachine* sm) : GameState(sm) {}

MenuState::~MenuState()
{
}

void MenuState::enter()
{
	PlaySound(TEXT("music//title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	int choice = 22;
	bool choosing = true;
	std::string choiceline = "22";
	while (choosing)
	{
		std::cout << GOLD
			"________   ________      ____\n"
			"`MMMMMMMb. `MMMMMMMb.   6MMMMb /\n"
			" MM    `Mb  MM    `Mb  8P    YM\n"
			" MM     MM  MM     MM 6M      Y\n"
			" MM     MM  MM     MM MM           M       M\n"
			" MM    .M9  MM    .M9 MM           M       M\n"
			" MMMMMMM9'  MMMMMMM9' MM           M       M\n"
			" MM  \\M\\    MM        MM        MMMMMMM MMMMMMM\n"
			" MM   \\M\\   MM        YM      6    M       M\n"
			" MM    \\M\\  MM         8b    d9    M       M\n"
			"_MM_   _\\M\\_MM_         YMMMM9     M       M\n" RESET;
		// http://patorjk.com/software/taag/#p=display&f=Georgi16&t=RPC%2B%2B
		std::cout << "(1) New Game\n(2) Load Game\n(3) Credits\n(4) Exit\n"
				  << ">";
		getline(std::cin, choiceline);
		try { choice = stoi(choiceline); }
		catch (std::exception ex) { choice = -1; }
		choosing = false;		// We're done here
		if (choice == 1)
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			mySM->changestate(StateMachine::CREATE_STATE);
		}
		else if (choice == 2)
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			mySM->changestate(StateMachine::LOAD_STATE);
		}
		else if (choice == 3)
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			mySM->changestate(StateMachine::CREDIT_STATE);
		}
		else if (choice == 4) 
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
		}
		else
		{
			choosing = true;	// Never mind
			PlaySound(TEXT("music//error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << SPONGEBOB "Invalid input!\n" RESET;
			std::cout << "Press Enter to try again...\n";
			std::cin.ignore();
			system("CLS");
			PlaySound(TEXT("music//title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
	}
	PlaySound(NULL, NULL, SND_ASYNC);
}

void MenuState::exit(){}

