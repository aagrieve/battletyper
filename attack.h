//AIDAN GRIEVE -- CS302

//attack.h
//Attack object holds the information for each attack that a combatant can use
//can be used to compare energy cost and update the energy of a combatant

#pragma once
#ifndef __ATTACK_H

#include <iostream>
#include <string>

using std::cout, std::endl;

class Attack
{
	public:
		
		//default constructor		
		Attack();

		//constructor, an is the name of the attack, ad is the description of the attack, at is the text that is to be entered, 
		//the pow is the power of the attack, en_c is the energy cost of the attack. This creates an attack object from the chosen
		//combatant
		Attack(std::string &an, std::string &ad, std::string &at,
			   int &pow, int &en_c);
		
		//destructor
		~Attack();

		//name applies
		void display_text();

		//name applies
		void display_attack();

		//gets attack text
		std::string & get_text();

		//gets power
		int & get_power();

		//compares the cost of the attack a player is attempting to use to their remaining energy, cost is how much the attack
		//will require
		bool compare_cost(int &cost);

		//updates combatant energy based on the cost of an attack, energy is the amount to remove based on attack cost
		void update_cost(int &energy);
		
	private:

		std::string attack_name;
		std::string attack_desc;
		std::string attack_text;
		int power;
		int en_cost;
};

#endif //__ATTACK_H
