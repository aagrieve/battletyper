//AIDAN GRIEVE -- CS302

//turn.h
//Turn_Portion is used to keep track of each half of a turn.
//A Turn_Portion is generated when a player takes their turn in the game object
//Two Turn_Portions are assembled into a Turn after each player has taken a turn

#pragma once
#ifndef __TURN_H

#include <iostream>

using std::cout;
using std::endl;

class Turn_Portion
{
	public:
		
		//default constructor
		Turn_Portion();

		//constructor, at is the attack_text, ui is the user_input, dam is the damage done, and sp is the speed
		Turn_Portion(std::string &at, std::string &ui, int &dam, int &sp);

		//destructor
		~Turn_Portion();

		//gets attack text
		std::string & get_a_t();

		//gets user input
		std::string & get_u_i();

		//gets damage
		int & get_damage();

		//gets speed
		int & get_speed();
	
		//name applies
		void display_portion();

	private:
		
		std::string attack_text;
		std::string user_input;
		int damage;
		int speed;
};

class Turn
{
	public:
		
		//default constuctor
		Turn();

		//constructor, t_num is the turn number in the game, p1_turn is the portion of turn from player1, p2_turn is the portion of the
		//turn from player2
		Turn(int &t_num, Turn_Portion *& p1_turn, Turn_Portion *& p2_turn);

		//destructor
		~Turn();
	
		//get turn number	
		int get_turn_num();

		//compare the speed of each turn portion to determine who moves first
		bool determine_order();

		//name applies
		void display_turn();
			
	
	private:
		
		int turn_num;

		Turn_Portion * p1;
		Turn_Portion * p2;	
		
};

#endif //__TURN_H
