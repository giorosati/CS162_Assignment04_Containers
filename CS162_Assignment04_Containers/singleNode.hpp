/*********************************************************************
** Program Filename: singleNode.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-24
** Description: single linked node class header file CS161_400 Assignment 4
*********************************************************************/

#ifndef SINGLENODE_HPP
#define SINGLENODE_HPP

#include <string>
#include "creature.hpp"

struct singleNode
{
	Creature* creaturePointer;
	singleNode* next;
};
void displayS(singleNode* &shead);			//displays the list to the console
void addNodeS(singleNode* &shead, Creature* creaturePointer);	//creates a node, adds it to the end of the list
void removeNodeS(singleNode* &shead);				//removes the last node and returns its data
singleNode* findLastS(singleNode* &shead);	//returns pointer to last node

#endif
