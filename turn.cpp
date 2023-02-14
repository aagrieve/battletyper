//AIDAN GRIEVE -- CS302

//turn.cpp
#include "turn.h"
//Turn_Portion

Turn_Portion::Turn_Portion()
{
}

Turn_Portion::Turn_Portion(std::string &at, std::string &ui, int &dam, int &sp)
	: attack_text{at}, user_input{ui}, damage{dam}, speed{sp}
{
}

Turn_Portion::~Turn_Portion()
{
}

std::string & Turn_Portion::get_a_t()
{
	return attack_text;
}

std::string & Turn_Portion::get_u_i()
{
	return user_input;
}

int & Turn_Portion::get_damage()
{
	return damage;
}

int & Turn_Portion::get_speed()
{
	return speed;
}

void Turn_Portion::display_portion()
{
	cout << "The attack they used: " << endl
		 << attack_text << endl
		 << "The text they entered: " << endl
		 << user_input << endl
		 << "The damage done by their attack: " << damage << endl
		 << "with a speed of: " << speed
		 << endl << endl;
	return;
}

//Turn

Turn::Turn()
{
}

Turn::Turn(int &t_num, Turn_Portion *& p1_turn, Turn_Portion *& p2_turn)
	: turn_num{t_num}, p1{p1_turn}, p2{p2_turn} 
{
}

Turn::~Turn()
{
	delete p1;
	delete p2;
}

int Turn::get_turn_num()
{
	return turn_num;
}

//could make slightly better
bool Turn::determine_order()
{
	if(p1->get_speed() >= p2->get_speed())
	{
		return true;
	}
	return false;
}

void Turn::display_turn()
{
	cout << "Turn Number: " << turn_num << endl << endl;
	if(determine_order())
	{
		cout << "Player 1 typed faster, and thus goes first!" << endl;
		p1->display_portion();
		cout << "Type faster next time Player 2!" << endl;
		p2->display_portion();
	}
	else
	{
		cout << "Player 2 typed faster, and thus goes first!" << endl;
		p2->display_portion();
		cout << "Type faster next time Player 1!" << endl;
		p1->display_portion();

	}
	return;
}
