// RPGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Kevin Zhou & Derek Li

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <ctime>
#include <windows.h>
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "StateMachine.h"

// ANSI codes
#define RESET "\x1B[0m";
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define NINTENDO "\x1B[38;2;230;0;18m"
#define SPOTIFY "\x1B[38;2;30;215;96m"
#define WALMART "\x1B[38;2;0;114;206m"
#define SPONGEBOB "\x1B[38;2;247;235;98m"
#define GOLD "\x1B[38;2;212;175;55m"
#define ZELDABLUE "\x1B[38;2;56;182;241m"
#define PLUM "\x1B[38;2;221;160;221m"

using std::cout;
using std::cin;

#pragma comment(lib, "winmm.lib")

class testGame
{
private:
	Player myPlayer;
	//StateMachine mySM;
public:
	testGame(Player& p)
		//StateMachine& sm)
	{
		myPlayer = p;
		//mySM = sm;
		//sm.start();
	}

	void battle()
	{
		battle(Enemy());	// Battle with a default enemy
	}
	void battle(Enemy bob)
	{
		while (myPlayer.getHP() > 0 && bob.getHP() > 0)
		{
			cout << "\n";
			cout << NINTENDO << bob.nameline() << "\n" RESET;
			cout << SPOTIFY "   " << bob.healthline() << "\n" RESET;
			cout << ZELDABLUE << myPlayer.nameline() << "\n" RESET;
			cout << SPOTIFY "   " << myPlayer.healthline() << "\n" RESET;
			int choice = -1;
			string choiceline;
			while(true)
			{
				cout << "(1) Attack\t(2) Check\t(3) My Stats\nChoose: ";
				getline(cin, choiceline);
				try { choice = stoi(choiceline); }
				catch (std::exception ex) { choice = -1; }
				if (choice == 1)
				{
					Sleep(500);
					cout << ">" << myPlayer.attack(bob) << "\n";
					Sleep(500);
					if (bob.getHP() == 0) break;
					cout << ">" << bob.attack(myPlayer) << "\n";
					Sleep(500);
					break;
				}
				else if (choice == 2)
				{
					cout << PLUM << bob.enemyinfo() << "\n" << RESET;
					Sleep(500);
					break;
				}
				else if (choice == 3)
				{
					cout << PLUM << myPlayer.stats() << "\n" << RESET;
					Sleep(500);
					break;
				}
				cout << SPONGEBOB "Invalid input!\n" RESET;
			}
		}
		if (myPlayer.getHP() > 0) { cout << GOLD "Victory!\n\n" RESET; }
		else { cout << RED "Defeat :(\n\n" RESET; }
		myPlayer.restore();
	}
};

int main()
{
	//PlaySound(TEXT("music//pacman.wav"), NULL, SND_FILENAME);
	StateMachine ourSM;
	ourSM.start();
	cout << "Goodbye!\n";
	/*

	// Map testing, confirming nonexistent keys have default values
	std::map<int, int> test;
	test[1]++;
	cout << test[1] << "\n";
	cout << test[0] << "\n";

	srand(time(0));
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	cout << GOLD
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
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::chrono::duration<int> time_elapsed = std::chrono::duration_cast<std::chrono::duration<int>>(end - start);

	//cout << time_elapsed.count() << "\n";

	Player hero;
	testGame quest(hero);
	int choice = 22;
	string choiceline = "22";
	while (choice != 0)
	{
		cout << "(1) Battle\n"
			 << "(0) Exit\n"
			 << "Enter your choice: ";
		getline(cin, choiceline);
		try { choice = stoi(choiceline); }
		catch (std::exception ex) { choice = -1; }
		if (choice == 1)
			quest.battle();
		else if (choice != 0)
			cout << SPONGEBOB "Invalid input!\n" RESET;
	}
	cout << "Goodbye!\n";
	
	*/
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
