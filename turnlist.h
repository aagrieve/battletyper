//AIDAN GRIEVE -- CS302

//turnlist.h
//TurnList contains the TurnNode, which is dervied from the Turn class. It is used to assemble a list of Turns. 
//TurnList is a circular linked list of Turn Nodes. Each turn is inserted into a TurnList in the game object after each turn plays out.
//array_TurnList is an array of TurnLists used to hold all the previous games played. A TurnList is inserted into an array_TurnList at the end
//of each game

#pragma once
#ifndef __TURNLIST_H

#include <string>

#include "turn.h"

class TurnNode: public Turn
{
	public:
		
		//default constructor
		TurnNode();

		//constuctor takes in the current turn number and each turn portion from the respective player during the game_loop function
		TurnNode(int &turn_num, Turn_Portion *& p1, Turn_Portion *& p2);

		//destructor
		~TurnNode();

		//set next with new_next node
		void set_next(TurnNode *& new_next);

		//set prev with new_prev node
		void set_prev(TurnNode *& new_prev);

		//get next
		TurnNode *& get_next();

		//get prev
		TurnNode *& get_prev();

		//checks if node has a next node
		bool has_next() const;

		//name applies
		void display_TurnNode();

	private:
		
		TurnNode * next;
		TurnNode * prev;

};

class TurnList
{
	public:

		TurnList();
		~TurnList();

		//check how many nodes there are to determine if node can be found. turn_find is the node we are searching for
		bool compare_node_total(int &turn_find);

		//recursive node entry into the TurnList. new_node is the node we are inserting
		void insert_TurnNode_helper(TurnNode *& new_node);

		//starts the insert process, new node is the node to be inserted
		void insert_TurnNode(TurnNode *& new_node);

		//recursive part of finding a node, curr is the current node in the structure, turn_num is the turn we are looking for
		TurnNode *& find_node_helper(TurnNode *& curr, int &turn_num);

		//starts the find process, turn_num is the node we are searching for
		TurnNode *& find_node(int &turn_num);

		//recursive part of removing all nodes, curr is the current node in the structure
		void remove_all_helper(TurnNode *& curr);

		//starts remove all process
		void remove_all();

		//recursive portion of removing all nodes, curr is the current node in the structure, turn num is the node being searched for 
		void remove_node_helper(TurnNode *& curr, int &turn_num);
		
		//starts remove node process, turn num is the node being searched for
		void remove_node(int &turn_num);

		//recursive portion of displaying each node, curr is the current node in the structure
		void display_TurnList_helper(TurnNode *& curr);

		//starts display process
		void display_TurnList();

	private:

		TurnNode * rear;
		int node_total;
};

class array_TurnList
{
	public:
		
		array_TurnList();
		~array_TurnList();
		
		//init array with nullptr
		void init_array();

		//recursive part of insertion into array, new_rear is the new node for entry, index is the current slot in array
		void insert_helper(TurnList *& new_rear, int &index);

		//starts insert process, new rear is the new node for entry
		void insert(TurnList *& new_rear);

		//removes node at index turn_list_num, turn_list_num is the number of the node removed
		void remove_one(int &turn_list_num);

		//recursive part of remove all, index is the slot in the array
		void remove_all_list_helper(int &index);

		//starts remove all process
		void remove_all_list();

		//returns the list at index turn_list_num
		TurnList *& retrieve(int &turn_list_num);

		//recursive part of display, index is the slot in the array
		void display_helper(int &index);

		//starts display process
		void display();
	
	private:

		TurnList ** rears;
};

#endif //__TURNLIST_H
