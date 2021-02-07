#include "StateMachine.h"
#include <time.h>

#pragma comment(lib, "winmm.lib")

CreateState::CreateState(StateMachine* sm) : GameState(sm) {}
CreateState::~CreateState(){}

void CreateState::enter()
{
	std::string name = "";
	while (true)
	{
		//choose name, write to file
		std::cout << "What's your name?\n"
			<< ">";
		getline(std::cin, name);
		//Remove all leading spaces
		for (int i = 0; i < name.length(); i++)
		{
			if (!isspace(name[i]))
				break;
			name = name.substr((_int64)i + 1);
			i--;
		}
		if (!name.empty() && name.find_first_of("<>:\"/\\|?*") == std::string::npos)
			break;
		//Error if no name or invalid characters given
		PlaySound(TEXT("music//error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		std::cout << SPONGEBOB "Invalid input!\n" RESET;
		std::cout << "Press Enter to try again...";
		std::cin.ignore();
		system("CLS");
	}

	//assign to player
	Player hero(name);
	mySM->myPlayer = &hero;

	//Weird sketchy stuff trying to get a timestamp
	time_t rawtime;
	time(&rawtime);
	char* t = new char[26]; 
	ctime_s(t, 26, &rawtime);
	std::string stamp = "";
	for (int i = 0; i < 25; i++)
	{
		// Colons and slashes are no-no's
		if (t[i] != ':' && t[i] != '\n')
			stamp += t[i];
	}
	//std::cout << ".\\saves\\" + name + "[" + stamp + "].txt";

	//writing to file
	std::ofstream outfile(".\\saves\\" + name + "[" + stamp + "].txt");
	//std::ofstream outfile("saveFile.txt");
	//putting in the variables
	outfile << mySM->myPlayer->savefile();
	outfile.close();

	// Big brain
	// Add the filename to a list of all saves
	std::ofstream list(".\\saves\\saveslist.txt", std::ios::app);
	list << name << "[";
	for (int i = 0; i < 24; i++)
		list << t[i];
	list << "]\n";
	list.close();

	//making sure we remember which file we are in.
	mySM->saveFile = ".\\saves\\" + name + "[" + stamp + "].txt";

	//go into intermediate state
	mySM->changestate(StateMachine::INTERMEDIATE_STATE);
}

void CreateState::exit()
{

}