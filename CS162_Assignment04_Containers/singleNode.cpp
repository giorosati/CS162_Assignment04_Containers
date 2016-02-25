/*********************************************************************
** Program Filename: singleNode.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-24
** Description: single linked node implementation file CS161_400 Assignment 4
*********************************************************************/

//includes
#include "singleNode.hpp"
#include <cstdlib>
#include <iostream>

//usings
using std::cout;
using std::endl;
using std::cin;

void displayS(singleNode * &shead)
{
	if (shead == NULL)
	{
		cout << "There are no items in the list." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		singleNode* tempNode = shead;
		cout << "Creature  -  Name: " << endl;
		cout << "-----------------------------" << endl;
		cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getGivenName() << endl;	//outputs head nodes data
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getGivenName() << endl;//outputs nodes after head 
		}
	}
}


void addNodeS(singleNode* &shead, Creature* creaturePointer)	//creates a node, adds it to the end of the list
{
	if (shead == NULL)		//case where no nodes exist
	{
		shead = new singleNode;
		shead->creaturePointer = creaturePointer;
		shead->next = NULL;
		cout << endl;
	}
	else					//adds a node to the end of the list
	{
		singleNode* lastNode = findLastS(shead);
		lastNode->next = new singleNode;
		lastNode->next->creaturePointer = creaturePointer;
		lastNode->next->next = NULL;
		cout << endl;
	}
}


void removeNodeS(singleNode* &shead)				//removes the last node
{
	if (shead == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		//return -999;
		cout << endl;
	}
	else
	{
		singleNode* tempNode = shead;
		if (tempNode->next == NULL)	//case where only one node exists
		{
			shead = NULL;
			delete tempNode;
		}
		else if (tempNode->next->next == NULL)	//case where only two nodes exits
		{
			tempNode->next = NULL;
			delete tempNode->next;
		}
		else
		{
			{
				while (tempNode->next->next != NULL)
					tempNode = tempNode->next;
			}
			tempNode->next = NULL;
			delete tempNode->next;
		}
	}
	cout << endl;
}


singleNode* findLastS(singleNode* &head)		//returns pointer to last node
{
	singleNode* tempNode = head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}
