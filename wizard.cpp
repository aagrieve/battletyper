//AIDAN GRIEVE -- CS302

//wizard.cpp
#include "wizard.h"

Wizard::Wizard()
{
	std::cout << "A wizard has been created using DC!" << std::endl;
}

Wizard::Wizard(const Wizard &source)
	: Combatant(source), name{new char[strlen(source.name) + 1]}, stat_bonus{source.stat_bonus}
{
	strcpy(name, source.name);
}

Wizard::Wizard(char *& n, int &sb)
	: Combatant(n, apply_hp(), (apply_en() + apply_stat_bonus()), fillAttacks()), name{new char[strlen(n) + 1]}, stat_bonus{sb}
{
	//std::cout << "Wizard is being created!" << std::endl;
	strcpy(name, n);
}

Wizard::~Wizard()
{
	//std::cout << "Wizard is being destroyed!" << std::endl;
	delete[] name;
}

Wizard& Wizard::operator=(const Wizard &w)
{
	delete[] name;
	name = nullptr;
	stat_bonus = 0;

	name = new char[strlen(w.name) + 1];
	strcpy(name, w.name);
	stat_bonus = w.stat_bonus;
	return *this;
}

void Wizard::display_sprite()
{
	std::cout << "      /\\\n"
			  << "     /  \\\n"
			  << "   _/____\\_\n"
			  << "    { o o}  @\n"
			  << "     [ -]   |\n"
			  << "     / $\\  /'\n"
			  << "    /|  |\\/\n"
			  << "  _/ |--|\n"
			  << "     /  |\n"
			  << "    /    |\n"
			  << "   |_   |_\n";
}

int Wizard::apply_hp()
{
	return 100;
}

int Wizard::apply_en()
{
	return 150;
}

int Wizard::apply_stat_bonus()
{
	return 20;
}

std::vector<Attack> Wizard::fillAttacks()
{
	std::vector<Attack> wizard_atks;
	std::string name;
	std::string desc;
	std::string attack;
	int power;
	int en_c;

	//spell 1
	name   = "Protective Aura";
	desc   = "A protective aura surrounds your Wizard, mitigating damage from an incoming attack. This attack always goes first.";
	attack = "Protect me from the beast before me!";
	power  = 0;
	en_c   = 10;
	
	wizard_atks.push_back(Attack(name, desc, attack, power, en_c));

	//spell 2
	name   = "Fireball";
	desc   = "A small flaming orb flies out of your Wizard's outstretched fingers, striking the opponent and engulfing them in flame.";
	attack = "Burn, you unfortunate fiend!";
	power  = 20;
	en_c   = 25;

	wizard_atks.push_back(Attack(name, desc, attack, power, en_c));
	
	//spell 3
	name   = "Ice Knife"; 
	desc   = "Your Wizard throws a knife with a shimmering blade of ice at the opponent. On impact it explodes, showering your opponent with sharp shards of ice.";
	attack = "Don't try to catch this, fool! I wouldn't want you to slip!!";
	power  = 40;
	en_c   = 50;

	wizard_atks.push_back(Attack(name, desc, attack, power, en_c));
	
	//spell 4
	name   = "Erupting Earth";
	desc   = "The ground beneath your opponent's feet erupts violently, bludgeoning them with chunks of stone and earth.";
	attack = "Open the mouth of the earth and be consumed! Pull my enemy below and bury them in an ocean of stone!! The light of day shall never grace your eyes again!!!";
	power  = 80;
	en_c   = 100;
	
	wizard_atks.push_back(Attack(name, desc, attack, power, en_c));
	
	return wizard_atks;
}
