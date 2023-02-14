//AIDAN GRIEVE -- CS302

//damagecalc.cpp

#include "damagecalc.h"

Damage_Calculator::Damage_Calculator()
{
}

Damage_Calculator::Damage_Calculator(int &t, std::string &a_t, std::string &u_i)
	: time{t}, attack_text{a_t}, user_input{u_i}, full_damage{0}
{
}

Damage_Calculator::~Damage_Calculator()
{
}

//counts number of characters the two strings share
int Damage_Calculator::compare_strings(std::string &ai, std::string &ui)
{
	std::string temp_AT = ai;
	std::string temp_UI = ui;
	std::sort(temp_AT.begin(), temp_AT.end());
	std::sort(temp_UI.begin(), temp_UI.end());
	
	std::string total_intersection;

	std::set_intersection(temp_AT.begin(), temp_AT.end(), temp_UI.begin(), temp_UI.end(), std::back_inserter(total_intersection));
	
	if(total_intersection.size() == temp_AT.size())
	{
		return 1;
	}
	return 0;
}

int Damage_Calculator::compare_word_helper(std::string attack_text_substr, std::string user_input_substr)
{
	int total = 0;
	if(user_input_substr.compare(attack_text_substr) == 0)
	{
		total++;
	}
	total += compare_strings(attack_text_substr, user_input_substr);
	//compare differences
	return total;
}

int Damage_Calculator::compare_word()
{
	int curr_window_beg = 0;
	int curr_window_end = 0;
	int success = 0;	
	std::string who_we_searchin;
	int difference;
	int multiplier;

	if(user_input.size() <= attack_text.size())
	{
		who_we_searchin = user_input;
	}
	else
	{
		who_we_searchin = attack_text;
	}

	//could make this better
	for(auto& i: who_we_searchin)
	{
		if(isspace(i) != 0)
		{
			difference = curr_window_end - curr_window_beg;
			success += compare_word_helper(attack_text.substr(curr_window_beg, difference), 
										 user_input.substr(curr_window_beg, difference));
			curr_window_end++;
			curr_window_beg = curr_window_end;
			full_damage++;
		}
		else if(i == attack_text.back())
		{	
			success += compare_word_helper(attack_text.substr(curr_window_beg, attack_text.back()), 
										 user_input.substr(curr_window_beg, user_input.back()));
		}
		else
		{
			curr_window_end++;
		}
	}
	multiplier = compare_word_helper(attack_text, user_input);
	if(multiplier != 0)
	{
		success *= multiplier;
	}

	return success;
	// for testing
	//return 30;
}

int Damage_Calculator::find_speed_mod()
{
	bool track = true;
	int count = 0;
	int temp_speed = time;
	while(track)
	{
		if(temp_speed < 10)
		{
			track = false;
		}
		else
		{
			temp_speed /= 10;
			count++;
		}
	}
	
	return count;
}

int Damage_Calculator::calculate_damage(Attack & a)
{
	//temp for testing
	//return 30;
	int CW;
	int attack_power;
	int damage_dealt;
	int speed_mod;
	int speed_metric;
	float percent;
	int new_value;

	CW = compare_word();
	full_damage = (4 * (full_damage + 1));
	attack_power = a.get_power();
	if(attack_power == 0)
	{
		percent = (float)CW / (float)full_damage;
		percent *= 10;
		new_value = (int)percent;
		return new_value;	
	}
	damage_dealt = (((float)CW) / ((float)full_damage)) * attack_power;
	speed_mod = find_speed_mod();
	speed_metric = 0;
	if(attack_power <= 45)
	{
		speed_metric = 4000;
	}
	else if(attack_power <= 70)
	{
		speed_metric = 7000;
	}
	else
	{
		speed_metric = 9000;
	}
	if(time < speed_metric)
	{
		damage_dealt += speed_mod;
	}	
	return damage_dealt;
}
