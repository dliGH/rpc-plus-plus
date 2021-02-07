#include "StateMachine.h"
#include <vector>

#pragma comment(lib, "winmm.lib")

LoadState::LoadState(StateMachine* sm) : GameState(sm) {}

LoadState::~LoadState() {}

// Displays all of the saves using saveslist.txt and lets player select one
void LoadState::enter()
{
	std::ifstream infile(".\\saves\\saveslist.txt");
	// If there wasn't a list, quickly create an empty one
	if (!infile.is_open())
	{
		std::ofstream create(".\\saves\\saveslist.txt");
		create.close();
	}
	std::vector<std::string> savefiles;
	std::string save;
	int i = 1;
	while (getline(infile, save))
	{
		savefiles.push_back(save);
		i++;
	}
	// No saves were found
	if (i == 1)
	{
		std::cout << "No files found!\n";
		std::cout << "Press Enter to return to menu...\n";
		std::cin.ignore();
		mySM->changestate(StateMachine::MENU_STATE);
		return;
	}

	int choice = -1;
	std::string choiceline = "-1";
	bool choosing = true;
	while (choosing)
	{
		for (int i = 0; i < savefiles.size(); i++)
		{
			std::cout << "(" << (i + 1) << ") ";
			std::cout << savefiles[i] << std::endl;
		}
		std::cout << "Choose a file: ";
		getline(std::cin, choiceline);
		try { choice = std::stoi(choiceline); }
		catch (std::exception ex) { choice = -1; }
		
		// Checking if in bounds
		// The _int64 cast is so the compiler doesn't warn me about overflows
		if ((_int64)choice - 1 < 0 || (_int64)choice - 1 > (_int64)savefiles.size())
		{
			PlaySound(TEXT("music//error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << SPONGEBOB "Invalid input!\n" RESET;
			std::cout << "Press Enter to try again...";
			std::cin.ignore();
		}
		else
		{
			PlaySound(TEXT("music//select.wav"), NULL, SND_FILENAME);
			// Add everything but the colons
			std::string filename = ".\\saves\\";
			for (unsigned i = 0; i < savefiles[(_int64)choice - 1].length(); i++)
				if (savefiles[(_int64)choice - 1].at(i) != ':')
					filename += savefiles[(_int64)choice - 1].at(i);
			filename += ".txt";
			std::ifstream infile(filename);

			//loading in character
			//idea: parse each line in the file into a struct and then use the struct to initialize all the variables
			//or use an array of structs?? <-- this is what was done. Might not be the most efficient but it seemed to work
			//moved struct called data into player.. wait first try statemachine?... ok nvm player? YES IT BUILT
			Player::data d[9];
			std::string line;
			int counter = 0;

			while (std::getline(infile, line)) {
				if (counter == 0) {
					d[counter].s = line;
				}
				else {
					d[counter].i = std::stoi(line);
				}
				counter++;
			}
			//somehow remember which state it was in... or only allow saving in intermediate? < -- big brain
			//still need a way to get that value back to overwrite though
			mySM->saveFile = filename;

			infile.close();
			choosing = false;

			//construct player with that array
			Player hero(d);
			std::cout << hero.savefile();
			mySM->myPlayer = &hero;
			//only allow saving in intermediate
			mySM->changestate(StateMachine::INTERMEDIATE_STATE);
		}
		system("CLS");
	}
}
