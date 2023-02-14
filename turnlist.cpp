//AIDAN GRIEVE -- CS302

//turnlist.cpp
#include "turnlist.h"

//TURNNODE
TurnNode::TurnNode()
{
}

TurnNode::TurnNode(int &turn_num, Turn_Portion *& p1, Turn_Portion *& p2)
	: Turn(turn_num, p1, p2), next{nullptr}, prev{nullptr}
{

}

TurnNode::~TurnNode()
{
	next = nullptr;
}

void TurnNode::set_next(TurnNode *& new_next)
{
	next = new_next;
}

void TurnNode::set_prev(TurnNode *& new_prev)
{
	prev = new_prev;
}

TurnNode *& TurnNode::get_next()
{
	return next;
}

TurnNode *& TurnNode::get_prev()
{
	return prev;
}

bool TurnNode::has_next() const
{
	if(next != nullptr)
	{
		return true;
	}
	return false;
}

void TurnNode::display_TurnNode()
{
	Turn::display_turn();
}

//TURNLIST

TurnList::TurnList()
	: rear{nullptr}, node_total{0}
{
}

TurnList::~TurnList()
{
	remove_all();
	delete rear;
}

bool TurnList::compare_node_total(int &turn_find)
{
	if(node_total >= turn_find)
	{
		return true;
	}
	return false;
}

void TurnList::insert_TurnNode_helper(TurnNode *& new_node)
{
	if(rear == nullptr)
	{
		rear = new_node;
		rear->set_next(rear);
		rear->set_prev(rear);
		node_total++;
		return;
	}
	else
	{
		if(rear->get_prev() == rear)
		{
			rear->set_next(new_node);
			rear->set_prev(new_node);
			new_node->set_next(rear);
			new_node->set_prev(rear);
			node_total++;
			return;
		}
		else
		{
			rear->get_prev()->set_next(new_node);
			new_node->set_prev(rear->get_prev());
			new_node->set_next(rear);
			rear->set_prev(new_node);
			node_total++;
			return;
		}	
	}
}

void TurnList::insert_TurnNode(TurnNode *& new_node)
{
	if(new_node == nullptr)
	{
		return;
	}
	insert_TurnNode_helper(new_node);
}

TurnNode *& TurnList::find_node_helper(TurnNode *& curr, int &turn_num)
{
	if(curr->get_turn_num() == turn_num)
	{
		return curr;
	}
	return find_node_helper(curr->get_next(), turn_num);
}

TurnNode *& TurnList::find_node(int &turn_num)
{
	if(turn_num == 1)
	{
		return rear;
	}
	return find_node_helper(rear->get_next(), turn_num);
}

void TurnList::remove_all_helper(TurnNode *& curr)
{
	if(curr == rear)
	{
		return;
	}
	else
	{
		TurnNode * temp = curr;
		curr = curr->get_next();
		delete temp;
	}
	remove_all_helper(curr);
	return;
}

void TurnList::remove_all()
{
	if(rear->get_next() != rear)
	{
		remove_all_helper(rear->get_next());
	}
	remove_all_helper(rear);
	return;
}

void TurnList::remove_node_helper(TurnNode *& curr, int &turn_num)
{
	if(curr == rear)
	{
		if(rear->get_turn_num() == turn_num)
		{
			TurnNode * temp = rear;
			rear = nullptr;
			delete temp;
		}
		return;
	}
	if(curr->get_turn_num() == turn_num)
	{
		TurnNode * temp = curr;
		curr->get_prev()->set_next(curr->get_next());
		curr->get_next()->set_prev(curr->get_prev());
		curr = curr->get_next();
		delete temp;
		return;
	}
	remove_node_helper(curr->get_next(), turn_num);
	return;
}


void TurnList::remove_node(int &turn_num)
{
	if(rear == nullptr)
	{
		return;
	}
	if(rear->get_next() != rear && rear->get_next() != nullptr)
	{
		remove_node_helper(rear->get_next(), turn_num);
	}
	else
	{
		remove_node_helper(rear, turn_num);
	}
	return;
}

void TurnList::display_TurnList_helper(TurnNode *& curr)
{
	if(curr == rear)
	{
		return;
	}
	curr->display_turn();
	display_TurnList_helper(curr->get_next());
}

void TurnList::display_TurnList()
{
	std::cout << " --- TURN BY TURN --- " << std::endl;
	if(rear == nullptr)
	{
		return;
	}
	rear->display_turn();
	display_TurnList_helper(rear->get_next());
	return;
}

//array_TurnList

array_TurnList::array_TurnList()
	: rears{new TurnList*[20]}
{
	init_array();
}

array_TurnList::~array_TurnList()
{
	remove_all_list();
	delete[] rears;
}

void array_TurnList::init_array()
{
	for(int i = 0; i < 20; i++)
	{
		rears[i] = nullptr;
	}
}

void array_TurnList::insert_helper(TurnList *& new_list, int &index)
{
	if(index == 20)
	{
		return;
	}
	if(rears[index] == nullptr)
	{
		rears[index] = new_list;
		return;
	}
	index++;
	return insert_helper(new_list, index);
}

void array_TurnList::insert(TurnList *& new_list)
{
	int index = 0;
	insert_helper(new_list, index);
	return;
}

void array_TurnList::remove_one(int &turn_list_num)
{
	TurnList * temp = rears[turn_list_num];
	rears[turn_list_num] = nullptr;
	delete temp;
	return;
}

void array_TurnList::remove_all_list_helper(int &index)
{
	if(index == 20)
	{
		return;
	}
	if(rears[index] != nullptr)
	{
		TurnList * temp = rears[index];
		rears[index] = nullptr;
		delete temp;
	}
	index++;
	return remove_all_list_helper(index);
}

void array_TurnList::remove_all_list()
{
	int index = 0;
	remove_all_list_helper(index);
	return;
}

TurnList *& array_TurnList::retrieve(int &turn_list_num)
{
	return rears[turn_list_num];
}

void array_TurnList::display_helper(int &index)
{
	if(index == 20)
	{
		return;
	}
	if(rears[index] != nullptr)
	{
		std::cout << " --- GAME " << index << " --- " << endl;
		rears[index]->display_TurnList();
	}
	index++;
	return display_helper(index);
}

void array_TurnList::display()
{
	int index = 0;
	if(rears == nullptr)
	{
		std::cout << "No games have been played quite yet. Why don't you give it a try?" << std::endl;
		return;
	}
	std::cout << "All Games Played Since Launch" << endl << endl;	
	display_helper(index);
	std::string keep_open;
	std::cin >> keep_open;
	return;
}
