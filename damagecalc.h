//AIDAN GRIEVE -- CS302

//damagecalc.h
//Calculates the damage done to enemy combatant based on the speed and user input during each turn.
//Damage is calculated then returned to the game object.

#pragma once
#ifndef __DAMAGECALC_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "attack.h"

class Damage_Calculator
{
	public:
		
		Damage_Calculator();
		Damage_Calculator(int &t, std::string &a_t, std::string &u_i);
		~Damage_Calculator();

		//compares the user input and attack text. If they have all the same characters, return 1. Else return 0;	
		//ai is the attack_text from attack object, ui is the user_input that a player entered
		int compare_strings(std::string &ai, std::string &ui);

		//compare substrs found by compare_word, if they are the same get 1 point, if they have the same characters get another point
		//attack_text_substr is the section of the attack_text found in compare_word, user_input_substr is the section of the user_input
		//found in compare_word
		int compare_word_helper(std::string attack_text_substr, std::string user_input_substr);	

		//search through the strings for inidivudal words based on where the spaces are. Compare individual words using helper function
		//loop through each word then compare the entire strings
		int compare_word();

		//gain extra points based on speed of entry	
		int find_speed_mod();

		//wrapper function that calls the others, calculating the total damage;
		//a is the attack that is being used
		int calculate_damage(Attack & a);
		
	
	private:
		int time;
		std::string attack_text;
		std::string user_input;
		int full_damage;
};

#endif //__DAMAGECALC_H
