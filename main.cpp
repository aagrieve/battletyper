//AIDAN GRIEVE -- CS302

//main.cpp

#include <iostream>
#include <string>
#include <cstring>

#include "game.h"
#include "turnlist.h"

#define CHOICE(choice) (!(1 <= choice && choice <= 3))

void clear_screen()
{
	for(int i = 0; i < 100; i++)
	{
		std::cout << std::endl;
	}
	return;
}

void display_rules()
{
	std::cout << "Typer Battle Sim:\n"
			  << "This game is inpired by turn-based-rpgs and typing games.\n"
			  << "I attempted to mesh the two together.\n\n"
			  << "How to play:\n\n"
			  << "1. When you start a game, you will select a Combatant to fight with.\n"
			  << "These combatants are different archtypes that can be used to battle.\n\n"
			  << "2. Once both players have selected a Combatant, a turn begins.\n"
			  << "During a turn, each player may select an attack to use on their opponent.\n"
			  << "Each attack has a power level and an energy cost.\n"
			  << "The goal is to bring the opponent to 0 HP before they can do that to you.\n"
			  << "The first attack for every Combatant lowers the amount of damage receieved.\n"
			  << "The remaining attacks do damage based on your typing accuracy.\n\n"
			  << "3. After an attack has been selected, a prompt will be shown, followed by\n"
			  << "a 3 second countdown. Once the countdown ends, you must attempt to type the\n"
			  << "prompt that is shown. Accuracy is part of how damage is calculated, so be\n"
			  << "careful about entering the text correctly. That being said, the length of\n"
			  << "time it takes you to enter an attack will also impact damage and which\n"
			  << "player goes first.\n\n"
			  << "4. After each turn, each combatant regenerates 15 energy points.\n\n"
			  << "5. When the game is complete, a history of each turn may be viewed, along\n"
			  << "with every other game played during the session.\n";
	std::string end_rules;
	std::cin >> end_rules;
	return;
}

void display_game_menu()
{
	std::cout << "Please choose an option from below:"  << std::endl
			  << "1. Start A New Game"                  << std::endl
			  << "2. See Transcript of Previous Games"  << std::endl
			  << "3. View Rules	"						<< std::endl
			  << "4. Quit"                              << std::endl;
	return;
}

void display_combatants()
{
	std::cout << "1. Wizard"  << std::endl
			  << "2. Brawler" << std::endl
			  << "3. Rogue"   << std::endl;
	return;
}

int choose_combatant()
{
	int choice = 0;
	while(CHOICE(choice))
	{
		if(std::cin >> choice)
		{
			if(CHOICE(choice))
			{
				std::cout << "Invalid input. Please choose again." << std::endl;
			}
		}
		else
		{	
			std::cout << "Invalid choice." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	return choice;
}


void run_game(TurnList *& list)
{
	char p1[30] = {};
	char p2[30] = {};
	int p1_choice = 0;
	int p2_choice = 0;
	char * p1name;
	char * p2name;
	Game * game;

	for(int i = 0; i < 20; i++)
	{
		p1[i] = '\0';
		p2[i] = '\0';
	}
	
	//p1 setup
	std::cout << "Player 1, please enter your name: \n";
	std::cin >> p1;
	p1name = new char [strlen(p1) + 1];
	strcpy(p1name, p1);
	std::cout << "Player 1, please choose your combatant: \n";
	display_combatants();
	p1_choice = choose_combatant();

	//p2 setup
	std::cout << "Player 2, please enter your name: \n";
	std::cin >> p2;
	p2name = new char [strlen(p2) + 1];
	strcpy(p2name, p2);
	std::cout << "Player 2, please choose your combatant: \n";
	display_combatants();
	p2_choice = choose_combatant();

	game = new Game(p1name, p2name, p1_choice, p2_choice);

	//game loop
	game->game_loop(list);

	delete[] p1name;
	delete[] p2name;
	delete game;
}

int main()
{
	//clear the screen
	clear_screen();

	bool running = true;
	int choice = 0;
	
	array_TurnList * array_list = new array_TurnList();
	TurnList * list;
	while(running)
	{
		display_game_menu();
		
		if(std::cin >> choice)
		{
			switch(choice)
			{
				case 1:
					clear_screen();
					list = new TurnList();
					run_game(list);
					array_list->insert(list);
					list = nullptr;
					break;
				case 2:
					//print transcript of all previous games
					array_list->display();
					break;
				case 3:
					clear_screen();
					display_rules();
					break;
				case 4:
					running = false;
					clear_screen();
					break;
				default:
					std::cout << "Invalid choice." << std::endl;
					break;
			}
		}
		else
		{
			std::cout << "Invalid choice." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');

		}
		clear_screen();
	}
	delete array_list;
	return 0;
}
