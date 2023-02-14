//AIDAN GRIEVE -- CS302

//game.cpp
#include "game.h"

Game::Game()
{

}

Game::Game(const Game & g)
	: p1{g.p1}, p2{g.p2}, game_running{g.game_running}
{
}

Game::Game(char *& p1name, char *& p2name, int &p1_choice, int &p2_choice)
	: p1{new Player(p1name, p1_choice)}, p2{new Player(p2name, p2_choice)}, game_running{true}
{

}

Game::~Game()
{
	delete p1;
	delete p2;
}

Game & Game::operator=(const Game &g)
{
	delete p1;
	delete p2;
	p1 = nullptr;
	p2 = nullptr;
	game_running = false;
	
	p1 = g.p1;
	p2 = g.p2;
	game_running = g.game_running;
	return *this;
}

void Game::clear_game()
{
	for(int i = 0; i < 100; i++)
	{
		cout << endl;
	}
	return;
}

bool Game::check_if_p1_dead()
{
	if(p1->is_dead())
	{
		return true;
	}
	return false;
}

bool Game::check_if_p2_dead()
{
	if(p2->is_dead())
	{
		return true;
	}
	return false;
}

void Game::display_game()
{
	p1->display_player();
	std::cout << "\n" << std::endl;	
	p2->display_player();
	return;
}

void Game::energy_regen()
{
	p1->regen_en();
	p2->regen_en();
}

//TurnList & 
void Game::game_loop(TurnList *& list)
{
	clear_game();
	TurnNode * turn;
	int turn_num = 1;
	int p1_choice;
	int p2_choice;
	int p1_damage;
	int p2_damage;
	int def_damage;
	
	cout << "TURN: " << turn_num << endl << endl;
	display_game();
	while(game_running)
	{
		// dont forget to delete these
		Turn_Portion * p1_portion; 
		Turn_Portion * p2_portion;
		cout << endl;
		p1->display_name();
		cout << "  --  make your choice!" << endl;
		p1_choice = p1->make_choice();
		clear_game();
		display_game();
		p1_damage = p1->take_turn(p1_choice, p1_portion);
		
		clear_game();
		display_game();
		
		p2->display_name();
		cout << " make your choice!" << endl;
		p2_choice = p2->make_choice();
		clear_game();
		display_game();
		p2_damage = p2->take_turn(p2_choice, p2_portion);
		
		clear_game();

		turn = new TurnNode(turn_num, p1_portion, p2_portion);

		//check for defending move
		if(p1_choice == 1 && p2_choice == 1)
		{
			p1_damage = 0;
			p2_damage = 0;
			cout << "Both opponents chose to defend themselves... no damage was done." << endl;
		}
		else if(p1_choice == 1)
		{
			p1_damage = 10 - p1_damage;
			def_damage = (p2_damage *p1_damage) / 10;
			if(p1_damage != 0)
			{
				def_damage /= 10;
			}
			p2_damage -= def_damage;
			p1_damage = 0;
		}
		else if(p2_choice == 1)
		{
			p2_damage = 10 - p2_damage;
			def_damage = (p1_damage * p2_damage);
			if(p2_damage != 0)
			{
				def_damage /= 10;
			}
			p1_damage -= def_damage;
			p2_damage = 0;
		}	

		//update hp and energy
		if(turn->determine_order())
		{
			p1->take_damage(p2_damage);
			p1->use_energy(p1_choice);
			
			if(check_if_p1_dead())
			{
				end_game();
				cout << endl << "GAME OVER" << endl;
				p2->display_name();
				cout << " is victorious!" << endl << endl;
			}
			else
			{
				p2->take_damage(p1_damage);
				p2->use_energy(p2_choice);
				
				if(check_if_p2_dead())
				{
					end_game();
					cout << endl << "GAME OVER" << endl;
					p2->display_name();
					cout << " is victorious!" << endl << endl;
				}
			}
		}
		else
		{
			p2->take_damage(p1_damage);			
			p2->use_energy(p2_choice);

			if(check_if_p2_dead())
			{
				end_game();
				p1->display_name();
				cout << " is victorious! The game is over!" << endl;
			}
			else
			{
				p1->take_damage(p2_damage);
				p1->use_energy(p1_choice);

				if(check_if_p1_dead())
				{
					end_game();
					p2->display_name();
					cout << " is victorious! The game is over!" << endl;
				}
			}	
		}

		//add turn to list
		list->insert_TurnNode(turn);
		
		//update and display turn
		if(game_running)
		{
			energy_regen();
			turn_num++;	
			cout << "Turn: " << turn_num << endl;
			display_game();
		}
		else
		{
			cout << "Final board state: " << endl;
			display_game();
			//wait 3 seconds then clear screen
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	//list->display_TurnList();
	return;
}

void Game::end_game()
{
	game_running = false;
	return;
}
