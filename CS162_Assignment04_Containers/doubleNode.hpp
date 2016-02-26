/*********************************************************************
** Program Filename: doubleNode.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-24
** Description: double linked node class header file CS161_400 Assignment 4
*********************************************************************/

#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

#include <string>
#include "creature.hpp"

struct doubleNode
{
	Creature* creaturePointer;
	doubleNode* next;
	doubleNode* prev;
};
void displayD(doubleNode* &head);		//displays the list to the console
void displayWins(doubleNode* &head);		//displays list with the # of wins
void addNodeD(doubleNode* &head, Creature* creaturePointer);	//creates a node, adds it to the end of the list
void removeFirstNodeD(doubleNode* &head); //removes the first node  ***NOT WORKING PROPERLY
void moveHeadToEnd(doubleNode* &head);	//moves the head node to the end of the list
void removeNodeD(doubleNode* &head);			//removes the last node
doubleNode* findLastD(doubleNode* &head);

#endif
