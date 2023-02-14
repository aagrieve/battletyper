//AIDAN GRIEVE -- CS302

//game.h
//A game object is made for an entire game, where turns occur until the game ends.
//The game object holds both players, and creates a loop where the game can be played until one player's combatant has 0 hp.
//The game object also populates the turn list with each individual turn, which is eventually inserted into an array of lists.
//When a game ends, we return to main and the game object is destroyed.

#include <iostream>
#include <chrono>
#include <thread>

#include "player.h"
#include "damagecalc.h"
#include "turn.h"
#include "turnlist.h"

using std::cout, std::endl;

class Game
{
	public:

		//default constructor
		Game();

		//copy constructor, g is the Game object to be copied
		Game(const Game & g);

		//constructor for game, p1name is name enetered by player 1, p2name is name entered by player 2, p1_choice is the combatant chosen by
		//player 1, p2_choice is the combatant chosen by player 2
		Game(char *& p1name, char *& p2name, int &p1_choice, int &p2_choice);

		//destructor
		~Game();
	
		//operator overload, g is the Game object to be assigned to
		Game & operator=(const Game &g);
		
		//clears the screen	
		void clear_game();

		//name of function applies, calls function within player object
		bool check_if_p1_dead();

		//name of function applies, calls function within player object
		bool check_if_p2_dead();

		//checks energy level, calls function within player object
		bool enough_energy();

		//displays the game
		void display_game();

		//regen energy every turn, calls function within player object
		void energy_regen();

		//runs the game loop over and over until the game ends, list is the list passed in by main that each turn is inserted in to
		void game_loop(TurnList *& list);

		//sets game_running to false
		void end_game();	
	
	private:

		Player * p1;
		Player * p2;
		bool game_running;
		

};
