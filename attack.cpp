//AIDAN GRIEVE -- CS302

//attack.cpp

#include "attack.h"

Attack::Attack()
{
}

Attack::Attack(std::string &an, std::string &ad, std::string &at, 
			   int &pow, int &en_c)
	: attack_name{an}, attack_desc{ad}, attack_text{at}, 
	  power{pow}, en_cost{en_c}
{
}

Attack::~Attack()
{
}

void Attack::display_text()
{
	cout << "Enter the following text to make your attack!" << endl;
	std::cout << attack_text << std::endl;
}

void Attack::display_attack()
{
	std::cout << attack_name << std::endl;
	std::cout << attack_desc << std::endl;
	std::cout << "Power: " << power << "\tEnergy Cost: " << en_cost << 
	std::endl;
}

std::string & Attack::get_text()
{
	return attack_text;
}

int & Attack::get_power()
{
	return power;
}

bool Attack::compare_cost(int &cost)
{
	if(en_cost <= cost)
	{
		return true;
	}
	return false;
}

void Attack::update_cost(int &energy)
{
	energy -= en_cost;
}
