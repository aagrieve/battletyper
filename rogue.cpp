//AIDAN GRIEVE -- CS302

//rogue.cpp
#include "rogue.h"

#define ROGUE_HP 125
#define ROGUE_EN 125

Rogue::Rogue()
{
	std::cout << "A rogue has been created using DC!" << std::endl;
}

Rogue::Rogue(const Rogue &source)
	: Combatant(source), name{new char[strlen(source.name) + 1]}, stat_bonus{source.stat_bonus}
{
	strcpy(name, source.name);
}

Rogue::Rogue(char *& n, int &sb)
	: Combatant(n, (apply_hp() + apply_stat_bonus()), (apply_en() + apply_stat_bonus()), fillAttacks()), name{new char[strlen(n) + 1]}, stat_bonus{sb}
{
	strcpy(name, n);
}

Rogue::~Rogue()
{
	delete[] name;
}

Rogue & Rogue::operator=(const Rogue & r)
{
	delete [] name;
	name = nullptr;
	stat_bonus = 0;

	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	stat_bonus = r.stat_bonus;
	return *this;
}

void Rogue::display_sprite()
{
	cout << "    _____\n"
		 << "   (/   \\)\n"
		 << "  (/ ___ \\)\n"
		 << " ( \\{'_'}/ )\n"
		 << "  | / T \\ |:^:\n"
		 << "  |/|   |\\|<=>\n"
		 << " _/ |___| \\_|\n"
		 << "  | |   | | '\n"
		 << "   \\|   |/\n"
		 << "   _|   |_\n"
		 << endl;
}

int Rogue::apply_hp()
{
	return 100;
}

int Rogue::apply_en()
{
	return 100;
}

int Rogue::apply_stat_bonus()
{
	return 10;
}

std::vector<Attack> Rogue::fillAttacks()
{
	std::vector<Attack> rogue_atks;
	
	std::string name;
	std::string desc;
	std::string attack;
	int power;
	int en_c;

	//attack 1
	name   = "Disappear";
	desc   = "Your Rogue pulls their hood over their head and vanishes from sight. This attack always moves first.";
	attack = "See you never, nerd!";
	power  = 0;
	en_c   = 10;

	rogue_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 2
	name   = "Backstab"; 
	desc   = "Your Rogue sneaks up behind the opponent and sticks a knife into the small of their back.";
	attack = "....May the pain in the small of your back be the last thing you ever feel!";
	power  = 40;
	en_c   = 20;

	rogue_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 3
	name   = "Poisoned Blade";
	desc   = "Your Rogue runs a green liquid across the edge of their blade before slashing at your opponent's stomach.";
	attack = "That wound in your stomach may be the death of you...if it isn't, the Tears of Lys certainly will be!!";
	power  = 70; 
	en_c   = 45;

	rogue_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 4
	name   = "Savage Shank"; 
	desc   = "Your Rogue silently leaps above their opponent and shoves their dagger into the exposed neck of their opponent.";
	attack = "After my Savage Shank - the only noise you'll hear is the trickle of blood hitting the floor! This move shall end you!! Gahahahaa!!!";
	power  = 90; 
	en_c   = 70;

	rogue_atks.push_back(Attack(name, desc, attack, power, en_c));
	
	return rogue_atks;
}
