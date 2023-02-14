//AIDAN GRIEVE -- CS302

//player.cpp
#include "player.h"

Player::Player()
{
}

Player::Player(const Player & to_copy)
	: name{new char [strlen(to_copy.name) + 1]}, combatant{to_copy.combatant}, combatant_choice{to_copy.combatant_choice}
{
	strcpy(name, to_copy.name);	
}

Player::Player(char *& n, int &choice)
	: name{new char[strlen(n) + 1]},
	  combatant{select_choice(choice)}, combatant_choice{choice}
{
	strcpy(name, n);
}

Player::~Player()
{
	delete[] name;
	delete combatant;
}

Player& Player::operator=(const Player &p)
{
	delete[] name;
	name = nullptr;
	combatant = nullptr;
	combatant_choice = 0;

	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	combatant = p.combatant;
	combatant_choice = p.combatant_choice;
	return *this;
}

void Player::display_name()
{
	cout << name;
	return;
}

void Player::display_player()
{
	cout << "Player: ";
	display_name();
	cout << endl << "Combatant: ";
	display_combatant_name();
	combatant->display_stats();
	cout << endl;
	switch(combatant_choice)
	{
		case 1:
			((Wizard*)combatant)->display_sprite();
			break;
		case 2:
			((Brawler*)combatant)->display_sprite();
			break;
		case 3:
			((Rogue*)combatant)->display_sprite();
			break;
		default:
			cout << "Uh-oh, no combatant_choice in Player :(" << std::endl;
			break;
	}
	return;
}

void Player::display_combatant_name()
{
	combatant->display_comb_name();
}

void Player::display_combatant_attacks()
{
	combatant->display_attack_list();
}

void Player::take_damage(int &d)
{
	combatant->update_hp(d);
}

void Player::use_energy(int &choice)
{
	combatant->update_energy(choice);
}

bool Player::enough_energy(int &choice)
{
	return combatant->enough_en(choice);
}

bool Player::is_dead()
{
	return combatant->is_dead();
}

bool Player::is_choice(int &c)
{
	if(c >= 1 && c <= 4)
	{
		return true;
	}
	return false;
}

void Player::regen_en()
{
	combatant->regen(15);
}

int Player::make_choice()
{
	int choice = 0;
		
	combatant->display_attack_list();

	while(!is_choice(choice))
	{
		cout << "Please choose an attack: ";
		if(cin >> choice)
		{
			if(!is_choice(choice))
			{
				cout << "You have selected a non-existant attack. Choose again." << endl;
			}
			if(!enough_energy(choice))
			{
				cout << "Not enough energy left to use that attack. Choose again." << endl;
				choice = 0;
			}
		}
		else
		{
			std::cout << "Invalid choice. Enter a number." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	return choice;
}

int Player::take_turn(int &choice, Turn_Portion *& p)
{
	return combatant->use_attack(choice, p);
}

Combatant * Player::select_choice(int &choice)
{
	int sbtest = 3;
	Combatant * temp;
	char * name;
	if(choice == 1)
	{
		name = new char[strlen("Wizard") + 1];
		strcpy(name, "Wizard");
		temp = new Wizard(name, sbtest);
		delete[] name;
		return temp;
	}
	if(choice == 2)
	{	
		name = new char[strlen("Brawler") + 1];
		strcpy(name, "Brawler");
		temp = new Brawler(name, sbtest);
		delete[] name;
		return temp;
	}	
	if(choice == 3)
	{	
		name = new char[strlen("Rogue") + 1];
		strcpy(name, "Rogue");
		temp = new Rogue(name, sbtest);
		delete[] name;
		return temp;
	}	
	return nullptr;
}

