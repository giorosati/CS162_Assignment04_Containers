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
		cout << "Creature  -  Name: " << endl;
		cout << "-----------------------------" << endl;
		cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getGivenName() << endl;	//outputs head nodes data
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getGivenName() << endl;//outputs nodes after head
		}
		cout << endl;
	}
}

void displayWins(doubleNode* &head)
{
	if (head == NULL)
	{
		cout << "None." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		doubleNode* tempNode = head;
		cout << "Creature   - # Wins  -  Name  -   " << endl;
		cout << "--------------------------------------" << endl;
		cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getWinCount() << " - " << tempNode->creaturePointer->getGivenName() << endl;	//outputs head nodes data
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->creaturePointer->getName() << "  -  " << tempNode->creaturePointer->getWinCount() << " - " << tempNode->creaturePointer->getGivenName() << endl;//outputs nodes after head
		}
		cout << endl;
	}
}

void addNodeD(doubleNode* &head, Creature* creaturePointer)
{
	if (head == NULL)		//case where no nodes exist
	{
		head = new doubleNode;
		head->creaturePointer = creaturePointer;
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
		lastNode->next->next = NULL;
		cout << endl;
	}
}

void removeFirstNodeD(doubleNode* &head) //removes the first node, DOES NOT DELETE CREATURE
{
	if (head == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		//return -99;
		cout << endl;
	}
	else
	{
		if (head->next == NULL)		//case where only one node
		{
			doubleNode* tempNode = head;
			head = NULL;
			delete tempNode;
		}
		else
		{
			doubleNode* tempNode = head;
			head = head->next;
			head->prev = NULL;
			delete tempNode;
		}
	}
	cout << endl;
}

void removeNodeD(doubleNode* &head)	//removes the last node, if any
{
	if (head == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		//return -99;
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
		delete lastNode;					//deletes the last node
	}
	cout << endl;
}

void moveHeadToEnd(doubleNode* &head)			//moves the head node to the end of the list
{

	if (head->next == NULL) return;				//do nothing if only one node in the list
	else
	{
		doubleNode* tempNode;
		tempNode = head;						//put head in a temporary node
		doubleNode* lastNode = findLastD(head);	//find the last node
		head = head->next;						//make node #2 head
		head->prev = NULL;
		if (head->next == NULL)					//case where there was only two nodes
		{
			tempNode->prev = head;
			head->next = tempNode;
			head->next->next = NULL;
			cout << endl;
		}
		else
		{
			tempNode->prev = lastNode;
			lastNode->next = tempNode;				//make last node next point to the prior head
			lastNode->next->next = NULL;
			cout << endl;
		}
	}
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