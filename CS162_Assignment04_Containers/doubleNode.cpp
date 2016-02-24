/*********************************************************************
** Program Filename: doubleNode.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-24
** Description: double linked node implementation file CS161_400 Assignment 4
*********************************************************************/

//includes
#include "doubleNode.hpp"
#include <cstdlib>
#include <iostream>

//usings
using std::cout;
using std::endl;
using std::cin;


void displayD(doubleNode* &head)
{
	if (head == NULL)
	{
		cout << "There are no items in the list." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		doubleNode* tempNode = head;
		cout << "Creatures in the list Type of creature - Given name: " << endl;
		cout << tempNode->creaturePointer->getName() << " - " << tempNode->creatureName << endl;	//outputs head nodes value
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->creaturePointer->getName() << " - " << tempNode->creatureName << endl;//outputs nodes after head 
		}
		cout << endl;
	}
}

void addNodeD(doubleNode* &head, Creature* creaturePointer, string creatureName)
{
	if (head == NULL)		//case where no nodes exist
	{
		head = new doubleNode;
		head->creaturePointer = creaturePointer;
		head->creatureName = creatureName;
		head->prev = NULL;
		head->next = NULL;
		cout << endl;
	}
	else					//adds a node to the end of the list
	{
		doubleNode* lastNode = findLastD(head);
		lastNode->next = new doubleNode;
		lastNode->next->prev = lastNode;
		lastNode->next->creaturePointer = creaturePointer;
		lastNode->next->creatureName = creatureName;
		lastNode->next->next = NULL;
		cout << endl;
	}
}

void removeNodeD(doubleNode* &head)	//removes the last node, if any
{
	if (head == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		return -99;
		cout << endl;
	}
	else
	{
		doubleNode* lastNode = findLastD(head);	//find the last node
		if (lastNode->prev == NULL) head = NULL;	//if it's the first node, set head to NULL
		if (lastNode->prev != NULL)
		{
			lastNode->prev->next = NULL;	//sets "next" on the second to last node to NULL
		}
		Creature* lastNodeCreaturePointer = lastNode->creaturePointer;
		string lastNodeCreatureName = lastNode->creatureName;
		delete lastNode;					//deletes the last node
	}
	cout << endl;
}


doubleNode* findLastD(doubleNode* &head)
{
	doubleNode* tempNode = head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}