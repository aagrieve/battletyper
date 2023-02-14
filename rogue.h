//AIDAN GRIEVE -- CS302

//rogue.h
//One of the pieces that can be selected to play with, the Rogue.
//Contains the information required for the piece and constructs the parent with that information.
//Can be used to display the sprite and populate the vector with unique attacks.

#pragma once
#ifndef __ROGUE_H

#include <iostream>

#include "combatant.h"
#include "attack.h"

using std::cout, std::endl;

class Rogue: public Combatant
{
	public:
		
		//default constructor
		Rogue();
		
		//copy constructor, source is the Rogue object to be copied
		Rogue(const Rogue &source);

		//constructor, n is the name, sb is the stat bonus
		Rogue(char *& n, int &sb);

		//destuctor
		~Rogue();

		//operator overload, r is the Rogue object
		Rogue & operator=(const Rogue & r);

		//name applies	
		void display_sprite();

	private:
		
		char * name;
		int stat_bonus;
		
		//applies hp for constructor
		int apply_hp();

		//applies energy for constructor
		int apply_en();

		//used for bonus based on choice of combatant
		int apply_stat_bonus();	

		//fills the vector in parent with unique attacks
		std::vector<Attack> fillAttacks();
};

#endif //__ROGUE_H
