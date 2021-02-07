#include "StateMachine.h"

#pragma comment(lib, "winmm.lib")

//intermediate state used for selecting actions
//e.g battle, inventory, quest, etc.

IntermediateState::IntermediateState(StateMachine* sm) : GameState(sm) {}

IntermediateState::~IntermediateState()
{
}

void IntermediateState::enter()
{
	int choice = 22;
	std::string choiceline = "22";
	// Same as the selector in MenuState
	bool choosing = true;
	while (choosing)
	{
		//arbitrary options for now 12/5/19
		std::cout << "(1) Profile\n(2) Inventory\n(3) Quest\n(4) Save\n(5) Exit\n"
			<< ">";
		getline(std::cin, choiceline);
		try { choice = stoi(choiceline); }
		catch (std::exception ex) { choice = -1; }
		choosing = false;
		if (choice == 1)
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			//making a toString for player bc simplify.. wait we wrote one: savefile!!
			//doesn't show weapon or armor yet though
			std::cout<<mySM->myPlayer->profile();
			//somehow need to pause here
			std::cout << "Press Enter to continue...";
			std::cin.ignore();
			
			//clear screen + making sure it doesn't autoexit
			system("CLS");
			choosing = true;
		}
		else if (choice == 2) 
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			std::cout << "Not currently implemented.\nPress Enter to continue...";
			choosing = true;
			std::cin.ignore();
			system("CLS");
		}
		else if (choice == 3) 
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			mySM->changestate(StateMachine::BATTLE_STATE);
		}
		else if (choice == 4)
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			//need to overwrite current save file
			//easiest might be to create new file and delete the old one? jk ofstream will do stuff for us
			//writing to file
			std::ofstream outfile(mySM->saveFile);

			//putting in the variables
			outfile << mySM->myPlayer->savefile();
			outfile.close();

			std::cout << "Saving.....\nPress Enter to continue...";
			std::cin.ignore();

			//clear screen + making sure it doesn't autoexit
			system("CLS");
			choosing = true;
		}
		else if (choice == 5)
		{
			//this is exit
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
		}
		else
		{
			choosing = true;
			PlaySound(TEXT("music//error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << SPONGEBOB "Invalid input!\n" RESET;
			std::cout << "Press Enter to try again...";
			std::cin.ignore();
			system("CLS");
		}
	}
}

void IntermediateState::exit()
{
}

