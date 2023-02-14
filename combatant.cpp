//AIDAN GRIEVE -- CS302

//combatant.cpp
#include "combatant.h"
#include "wizard.h"
#include "brawler.h"
#include "rogue.h"

Combatant::Combatant()
	: hitpoints{0}, energy{0}, total_energy{0}
{
}

Combatant::Combatant(const Combatant &source)
	: comb_name{new char[strlen(source.comb_name) + 1]}, hitpoints{source.hitpoints}, energy{source.energy}, total_energy{source.total_energy},
	  attack_list{source.attack_list}
{
	strcpy(comb_name, source.comb_name);
}

Combatant::Combatant(char *& n, int hp, int en, std::vector<Attack> a_L)
	: comb_name{new char[strlen(n) + 1]}, hitpoints{hp}, energy{en}, total_energy{en}, attack_list{a_L}
{
	//std::cout << "Combatant is being created!" << std::endl;
	strcpy(comb_name, n);
}

Combatant::~Combatant()
{
	//std::cout << "Combatant is being destroyed!" << std::endl;
	delete[] comb_name;	
}

Combatant& Combatant::operator=(const Combatant &c)
{
	delete[] comb_name;
	comb_name = nullptr;
	hitpoints = 0;
	energy = 0;
	attack_list.clear();
	
	comb_name = new char[strlen(c.comb_name) + 1];
	strcpy(comb_name, c.comb_name);
	hitpoints = c.hitpoints;
	energy = c.energy;
	attack_list = c.attack_list;
	return *this;
}

void Combatant::clear()
{
	for(int i = 0; i < 100; i++)
	{
		std::cout << std::endl;
	}
}

int Combatant::use_attack(int &atk_choice, Turn_Portion *& p)
{
	std::string user_input;
	Damage_Calculator * turn_calc;
	int damage;

	//setup timer
	using Clock = std::chrono::high_resolution_clock;
	
	//output attack text
	display_attack_text(atk_choice);
	
	cout << endl << "Please start typing in..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "3..." << endl;		
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "2..." << endl;		
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "1..." << endl;		
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "GO!!!" << endl;
	
	//start timer
	auto start = Clock::now();

	//input answer
	std::getline(std::cin>>std::ws, user_input);
	//stop timer
	auto stop = Clock::now();

	//get time duration
	auto mseconds = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
	//maybe go to seconds??? idk
	//float seconds = ((float)mseconds) / 100;

	//call calculator with attack_text, user_input, and time
	turn_calc = new Damage_Calculator((int&)mseconds, attack_list.at(atk_choice - 1).get_text(), user_input);
	
	damage = turn_calc->calculate_damage(attack_list.at(atk_choice-1));
	delete turn_calc;
	
	//create turnportion for return
	p = new Turn_Portion(attack_list.at(atk_choice - 1).get_text(), user_input, damage, (int&)mseconds);

	return damage;
}

bool Combatant::is_dead()
{
	if(hitpoints <= 0)
	{
		return true;
	}
	return false;
}

void Combatant::regen(int val)
{
	energy += val;
	if(energy > total_energy)
	{
		energy = total_energy;
	}
	return;
}

bool Combatant::enough_en(int &choice)
{
	return attack_list.at(choice - 1).compare_cost(energy);
}

void Combatant::display_comb_name()
{
	cout << comb_name << endl;
	return;
}

void Combatant::display_stats()
{
	cout << "HP: " << hitpoints << "\tENRGY: " << energy << endl;
}

void Combatant::update_hp(int &damage)
{
	hitpoints -= damage;
	if(hitpoints < 0)
	{
		hitpoints = 0;
	}
	return;
}

void Combatant::update_energy(int &choice)
{
	attack_list.at(choice - 1).update_cost(energy);
}

void Combatant::display_attack_list()
{
	int index = 1;
	for(auto i : attack_list)
	{
		cout << "Attack " << index << ":" << endl;
		i.display_attack();
		cout << endl;
		index++;
	}
}

void Combatant::display_attack_text(int &choice)
{
	auto i = attack_list.at(choice - 1);
	i.display_text();
}
