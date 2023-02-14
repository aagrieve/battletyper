//AIDAN GRIEVE -- CS302

//brawler.cpp
#include "brawler.h"

Brawler::Brawler()
{
	std::cout << "A brawler has been created using DC!" << std::endl;
}

Brawler::Brawler(const Brawler &source)
	: Combatant(source), name{new char[strlen(source.name) + 1]}, stat_bonus{source.stat_bonus}
{
	strcpy(name, source.name);
}

Brawler::Brawler(char *& n, int &sb)
	: Combatant(n, (apply_hp() + apply_stat_bonus()), apply_en(), fillAttacks()), name{new char [strlen(n) + 1]}, stat_bonus{sb}
{
	//std::cout << "Brawler is being created!" << std::endl;
	strcpy(name, n);
}

Brawler::~Brawler()
{
	//std::cout << "Brawler is being destroyed!" << std::endl;
	delete[] name;
}

Brawler & Brawler::operator=(const Brawler & b)
{
	delete [] name;
	name = nullptr;
	stat_bonus = 0;

	name = new char[strlen(b.name) + 1];
	strcpy(name, b.name);
	stat_bonus = b.stat_bonus;
	return *this;
}

void Brawler::display_sprite()
{
	cout << "  +  ___  +  ^\n"
		 << "   \\/   \\/  { }\n"
		 << "   { u u }  { }\n"
		 << "    [ ~ ]  <===>\n"
		 << "    / H \\   _|\n"
		 << "   /|   |\\_/ \"\n"
		 << "   \\|===|\n"
		 << "    |   |\n"
		 << "    /   /\n"
		 << "   _|  _|\n"
		 << endl;
}

int Brawler::apply_hp()
{
	return 100;
}

int Brawler::apply_en()
{
	return 100;
}

int Brawler::apply_stat_bonus()
{
	return 20;
}

std::vector<Attack> Brawler::fillAttacks()
{
	std::vector<Attack> brawler_atks;
	std::string name;
	std::string desc;
	std::string attack;
	int power;
	int en_c;

	//attack 1
	name   = "Raised Shield";
	desc   = "Your Brawler raises their buckler shield and deflects the oncoming attack.";
	attack = "Your weak attack is no match for my shield!";
	power  = 0;
	en_c   = 10;

	brawler_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 2
	name   = "Stab";
	desc   = "Your Brawler shoves their blade forward, sinking the steel deep into the opponent.";
	attack = "And I thought there was no such thing as a stab problem!";
	power  = 35;
	en_c   = 30;

	brawler_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 3
	name   = "Reckless Attack";
	desc   = "Your Brawler slashes their blade wildly towards their enemy, disregarding the potential risk.";
	attack = "Surprise! I bet you didn't expect an attack as swift as this!!";
	power  = 50;
	en_c   = 40;

	brawler_atks.push_back(Attack(name, desc, attack, power, en_c));

	//attack 4
	name   = "Overhead Strike";
	desc   = "Your Brawler lifts their blade high above their head and swiftly swings it down onto the opponent.";
	attack = "Aha ha ha! I have vanquished a thousand enemies this way!! Nothing can stop my finishing blow!!!";
	power  = 70;
	en_c   = 60;

	brawler_atks.push_back(Attack(name, desc, attack, power, en_c));

	return brawler_atks;
}
