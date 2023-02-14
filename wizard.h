//AIDAN GRIEVE -- CS302

//wizard.h
//One of the pieces that can be selected to play with, the Wizard.
//Contains the information required for the piece and constructs the parent with that information.
//Can be used to display the sprite and populate the vector with unique attacks.

#pragma once
#ifndef __WIZARD_H

#include <iostream>
#include <vector>
#include <typeinfo>

#include "combatant.h"
#include "attack.h"

class Wizard: public Combatant
{
	public:
		
		//default constructor
		Wizard();

		//copy constructor, source is the Wizard object to be copied
		Wizard(const Wizard &source);

		//constructor, n is the name, sb is the stat bonus
		Wizard(char *& n, int &sb);

		//destructor
		~Wizard();

		//operator overload, w is the Wizard object to be assigned
		Wizard & operator=(const Wizard &w);
		
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

#endif //__WIZARD_H
