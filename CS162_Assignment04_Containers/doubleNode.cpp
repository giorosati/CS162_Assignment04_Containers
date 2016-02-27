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
#include <vector>

//usings
using std::cout;
using std::endl;
using std::cin;
using std::vector;


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
		cout << "Name (Creature Type)" << endl;
		cout << "-------------------------------------" << endl;
		cout << tempNode->creaturePointer->getGivenName() << " (" << tempNode->creaturePointer->getName() << ")" << endl;	//outputs head nodes data
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->creaturePointer->getGivenName() << " (" << tempNode->creaturePointer->getName() << ")" << endl;	//outputs nodes after head
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
		cout << "Fights(Rounds) - Wins - Name (Creature Type)" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "  " << tempNode->creaturePointer->getBattleCount() << "(" << tempNode->creaturePointer->getPrestige() << ")" << "         -  " << tempNode->creaturePointer->getWinCount() << "   - " << tempNode->creaturePointer->getGivenName() << " (" << tempNode->creaturePointer->getName() << ")" << endl;	//outputs head nodes data
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << "  " << tempNode->creaturePointer->getBattleCount() << "(" << tempNode->creaturePointer->getPrestige() << ")" << "         -  " << tempNode->creaturePointer->getWinCount() << "   - " << tempNode->creaturePointer->getGivenName() << " (" << tempNode->creaturePointer->getName() << ")" << endl;	//outputs nodes after head
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

void addNodeTop(doubleNode* &head, Creature* creaturePointerIn)	//creates a node, adds it to the top of the list
{
	if (head == NULL)		//case where no nodes exist
	{
		head = new doubleNode;
		head->creaturePointer = creaturePointerIn;
		head->prev = NULL;
		head->next = NULL;
		cout << endl;
	}
	else					//adds a node to the beginning of the list
	{
		doubleNode* newNode = new doubleNode;
		newNode->creaturePointer = head->creaturePointer;  //move head data to the new node
		newNode->prev = head;
		newNode->next = head->next;
		head->creaturePointer = creaturePointerIn;
		head->next = newNode;
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

void prestigeSort(doubleNode* &head)		//sort list based on wins and prestige
{
	cout << "***********  AWARDS  ******************************" << endl;
	cout << endl;
	if (head == NULL)	//test if the list is empty
	{
		cout << "No Creatures qualify for a medal!" << endl;
		//return -99
		cout << endl;
	}
	else if (head->next == NULL)	//if only one creature is in the list
	{
		cout << "Gold Medal goes to the sole surviving creature:" << endl;
		cout << endl;
		cout << "Fights(Rounds) - Wins - Name (Creature Type)" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "  " << head->creaturePointer->getBattleCount() << "(" << head->creaturePointer->getPrestige() << ")" << "         -  " << head->creaturePointer->getWinCount() << "   - " << head->creaturePointer->getGivenName() << " (" << head->creaturePointer->getName() << ")" << endl;
		cout << endl;
	}
	else
	{
		//place the values into a vector
		doubleNode* tempNode = head;
		Creature* cPointer;
		vector<Creature*> creatures; //create a vector to store the creature pointers
		int temp;
		bool swap;
		do
		{
			while (tempNode != NULL)	//get all creatures in the list
			{
				cPointer = tempNode->creaturePointer;
				creatures.push_back(cPointer);
				tempNode = tempNode->next;
			}
			swap = false;
			int count = 0;
			for (unsigned count = 0; count < creatures.size() - 1; count++)
			{
				if (creatures[count]->getPrestige() < creatures[count + 1]->getPrestige())
				{
					cPointer = creatures[count];
					creatures[count] = creatures[count + 1];
					creatures[count + 1] = cPointer;
					swap = true;
				}
			}
		} while (swap);
		cout << " ***** Gold Medal awarded to " << creatures[0]->getGivenName() << " (" << creatures[0]->getName() << ") " << "who fought " << creatures[0]->getPrestige() << " round(s) in " << creatures[0]->getBattleCount() << " battle(s)." << endl;
		cout << "   *** Silver Medal awarded to " << creatures[1]->getGivenName() << " (" << creatures[1]->getName() << ") " << "who fought " << creatures[1]->getPrestige() << " round(s) in " << creatures[1]->getBattleCount() << " battle(s)." << endl;
		if (creatures.size() > 2)
		{
			cout << "     * Bronze Medal awarded to " << creatures[2]->getGivenName() << " (" << creatures[2]->getName() << ") " << "who fought " << creatures[2]->getPrestige() << " round(s) in " << creatures[2]->getBattleCount() << " battle(s)." << endl;
		}
		else
		{
			cout << "Only two creatuers survived so a Bronze medal was not awarded." << endl;
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