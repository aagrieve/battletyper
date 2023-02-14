//AIDAN GRIEVE -- CS302

//brawler.h
//One of the pieces that can be selected to play with, the Brawler.
//Contains the information required for the piece and constructs the parent with that information.
//Can be used to display the sprite and populate the vector with unique attacks.

#pragma once
#ifndef __BRAWLER_H

#include <iostream>

#include "combatant.h"
#include "attack.h"

using std::cout, std::endl;

class Brawler: public Combatant
{
	public:
		
		//default constructor
		Brawler();

		//copy constructor, source is the Brawler object to be copied
		Brawler(const Brawler &source);

		//constructor, n is the name, sb is the statbonus
		Brawler(char *& n, int &sb);

		//destructor
		~Brawler();

		//operator overload, b is the Brawler object we are assigning
		Brawler & operator=(const Brawler & b);
		
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

#endif //__BRAWLER_H
