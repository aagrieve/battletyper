//AIDAN GRIEVE -- CS302

//player.h
//Holds the information for each player, and has an pointer to an object of the chosen combatant.
//Used as a pass through from the game to the combatant, but for each unique player.
//Keeps track of the player's name and their chosen combatant.

#pragma once
#ifndef __PLAYER_H

#include <iostream>
#include <cstring>

#include "combatant.h"
#include "wizard.h"
#include "brawler.h"
#include "rogue.h"
#include "turn.h"

using std::cout, std::cin, std::endl;

class Player
{
	public:

		//default constructor
		Player();

		//copy constructor, to_copy is the Player object to be copied
		Player(const Player & to_copy);

		//constructor, n is the name entered by the player, choice is the attack chosen by the players
		Player(char *& n, int &choice);

		//destructor
		~Player();

		//operater overload, p is the player object to be assigned to
		Player& operator=(const Player &p);
	
		//name applies
		void display_name();
		
		//name applies
		void display_player();

		//name applies
		void display_combatant_name();

		//name applies
		void display_combatant_attacks();

		//calls combatant function to remove d hp, d is the damage generated in the other player's turn and returned to game object
		void take_damage(int &d);

		//calls combatant function to remove energy based on what attack is used, choice is the attack chosen by the player
		void use_energy(int &choice);

		//checks if the combatant has enough energy left, calls similar function within combatant object, choice is the attack chosen by the player
		bool enough_energy(int &choice);

		//checks if the combatant is dead, calls similar function within combatant object
		bool is_dead();

		//checks if choice is valid, c is the attack chosen by the player
		bool is_choice(int &c);

		//refills combatant energy
		void regen_en();

		//lets user input a choice
		int make_choice();

		//starts turn creation after choice has been made, choice is the attack chosen by the player, p is the turn portion made by a player taking
		//a turn
		int take_turn(int &choice, Turn_Portion *& p);

	private:
		
		char * name;
		Combatant * combatant;
		int combatant_choice;	

		Combatant * select_choice(int &choice);
};

#endif //__PLAYER_H
