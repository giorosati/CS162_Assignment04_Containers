/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: main.cpp file for CS162_400 Assignment 4
*********************************************************************/

//includes
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "doubleNode.hpp"
#include "creature.hpp"
#include "medusa.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;
using std::srand;
using std::rand;
using std::string;

//function prototypes
void displayMenu();
Creature* createCreature(int menuChoice);

int main()
{
	//initialize random number generator
	srand((unsigned)time(NULL));

	//initialize variables for program exit, menu choice, # of creatures
	int exitToggle = 0;
	int menuChoice1 = 6;
	int menuChoice2 = 6;
	int creatureCount = 0;
	string creatureName1 = "";
	string creatureName2 = "";

	//initialize linked lists for creature lineups
	doubleNode* p1Head = NULL;
	doubleNode* p2Head = NULL;
	doubleNode* p1Dead = NULL;
	doubleNode* p2Dead = NULL;

	//initialize variables for two creatures   *********DO NOT USE
	//Creature* creatureOne = NULL;
	//Creature* creatureTwo = NULL;

	cout << "***** Creature Battle Tournament  *****" << endl;
	cout << endl;
	cout << "Enter the number of Creatures for each player: " << endl;
	cin >> creatureCount;

	//display menu
	while (exitToggle != 1)
	{
		//get user selection for Creature #1
		cout << "You will now pick " << creatureCount << " creature(s) for Player 1 and Player 2." << endl;
		cout << "You will pick a creature for Player 1, then a creature for Player 2, then" << endl;
		cout << "another creature for Player 1, then for Player 2, and so on until all creatures" << endl;
		cout << "have been chosen." << endl;

		for (int i = 0; i < creatureCount; i++)
		{
			//display menu function
			displayMenu();

			//get Player One creature
			cout << "Enter your choice for Player 1's creature # " << i + 1 << ": ";
			cin >> menuChoice1;
			cout << "Enter a name for this creature: ";
			cin.ignore();
			getline(cin, creatureName1);
			cout << endl;
			if (menuChoice1 == 0) { exitToggle = 1; }
			if (exitToggle != 1)
			{
				//get Player 2 creature
				cout << "Enter your choice for Player 2's creature # " << i + 1 << ": ";
				cin >> menuChoice2;
				cout << "Enter a name for this creature: ";
				cin.ignore();
				getline(cin, creatureName2);
				cout << endl;
				if (menuChoice2 == 0) { exitToggle = 1; }
			}
			if (exitToggle != 1) //create the creatures
			{
				Creature* tempCreature1 = createCreature(menuChoice1);
				Creature* tempCreature2 = createCreature(menuChoice2);
				addNodeD(p1Head, tempCreature1, creatureName1);
				addNodeD(p2Head, tempCreature2, creatureName2);
			}
		}
		cout << "Creatures have been created..." << endl;
		if (exitToggle != 1) //enter the battle if user has not chosen 0
		{
			cout << "Player 1 ceature lineup" << endl;
			displayD(p1Head);
			cout << endl;
			cout << endl;
			cout << "Player 2 ceature lineup" << endl;
			displayD(p2Head);
			cout << endl;
			cout << endl;

			cout << "*******************************************" << endl;
			cout << endl;
			cout << "The tournament begins...press enter." << endl;
			cout << endl;
			cin.clear();
			cin.get();
		}

		//start tournament loop
		while ((p1Head != NULL) && (p2Head != NULL))  //test if there are live creatures for each player
		{
			int attackRound = 0;		//attack rounds counter
			int harryDeathsC1 = 0;		//death count for a Creature One Harry Potter
			int harryDeathsC2 = 0;		//death count for a Creature Two Harry Potter

			//get the next available creature from each stack
			Creature* creatureOne = p1Head->creaturePointer;
			Creature* creatureTwo = p2Head->creaturePointer;
			cout << "test for stop" << endl;
			//attack loop
			while ((creatureOne->getStength() > 0) && (creatureTwo->getStength() > 0))
			{
				attackRound += 1;		//increment attack counter
				cout << "*******************************************" << endl;
				cout << "Battle round # " << attackRound << endl;

				//creatureOne attack
				cout << endl;
				int tempDamage = creatureOne->attack();
				int netDamage = creatureTwo->defend(tempDamage, harryDeathsC2);
				if (netDamage == 200)	//test for vampire charm
				{
					cout << "Vampire (Creature 2) has used CHARM!" << endl;
					cout << creatureOne->getName() << " (Creature 1) was unable to attack." << endl;
					cout << endl;
				}
				else if (tempDamage == 100) //test if Medusa used glare
				{
					cout << "Medusa (Creature 1) has used GLARE!" << endl;
					if (!((harryDeathsC2 == 0) && (creatureTwo->getStength() == 20)))
					{
						creatureTwo->setStrength(0);		//kill opponent except when Harry has been resurrected
					}
					else
					{
						harryDeathsC2 += 1;
						cout << "Harry Potter (Creature 2) died but has been resurrected." << endl;
					}
				}
				else
				{
					cout << creatureOne->getName() << " (Creature 1) caused " << netDamage << " point(s) of damage!" << endl;
					if ((harryDeathsC2 == 0) && (creatureTwo->getStength() == 20))
					{
						harryDeathsC2 += 1;
						cout << "Harry Potter (Creature 2) died but has been resurrected." << endl;
					}
					else creatureTwo->setStrength(creatureTwo->getStength() - netDamage);
				}

				if (creatureTwo->getStength() <= 0)  //case where creatureTwo dies
				{
					creatureTwo->setStrength(0);
					cout << creatureTwo->getName() << " (Creature 2) has died..." << endl;
				}
				else
				{
					cout << endl;
					//creatureTwo attack
					int tempDamage = creatureTwo->attack();
					int netDamage = creatureOne->defend(tempDamage, harryDeathsC1);
					if (netDamage == 200)	//test for vampire charm
					{
						cout << "Vampire (Creature 1) has used CHARM!" << endl;
						cout << creatureTwo->getName() << " (Creature 2) was unable to attack." << endl;
						cout << endl;
					}
					else if (tempDamage == 100) //test if Medusa used glare
					{
						cout << "Medusa (Creature 2) has used GLARE!" << endl;
						if (!((harryDeathsC1 == 0) && (creatureOne->getStength() == 20)))
						{
							creatureOne->setStrength(0);		//kill opponent except when Harry has been resurrected
						}
						else
						{
							harryDeathsC1 += 1;
							cout << "Harry Potter (Creature 1) died but has been resurrected." << endl;
						}
					}
					else
					{
						cout << creatureTwo->getName() << " (Creature 2) caused " << netDamage << " point(s) of damage!" << endl;
						if ((harryDeathsC1 == 0) && (creatureOne->getStength() == 20))
						{
							harryDeathsC1 += 1;
							cout << "Harry Potter (Creature 1) died but has been resurrected." << endl;
						}
						else creatureOne->setStrength(creatureOne->getStength() - netDamage);
					}

					if (creatureOne->getStength() <= 0)  //case where creature one dies
					{
						creatureOne->setStrength(0);
						cout << creatureOne->getName() << " (Creature 1) has died..." << endl;
					}
				}
				cout << endl;
				cout << creatureOne->getName() << " (Creature 1) strength is now: " << creatureOne->getStength() << endl;
				cout << creatureTwo->getName() << " (Creature 2) strength is now: " << creatureTwo->getStength() << endl;
				cout << endl;
				cout << "Battle round " << attackRound << " has ended." << endl;
				cout << "*******************************************" << endl;
				cout << endl;
				cout << "Press enter to continue...";
				cin.get();
			}
		}

		//end of game/exit while loop
		cout << endl;
		cout << endl;
		if (exitToggle != 1)
		{
			cout << "This battle is over...press enter to return to the menu";
			cout << endl;
			cout << endl;
		}

		//cin.ignore();
		cin.clear();
		cin.get();

		cout << endl;
		cout << endl;
		cout << "Goodbye...";
		cout << "*******************************************" << endl;
		cout << "********************************" << endl;
		cout << "***********************" << endl;
		cout << "**************" << endl;
		cout << "*****" << endl;
		return 0;
	}
}
//display menu function
void displayMenu()
{
	cout << endl;
	cout << endl;
	cout << "********************************************" << endl;
	cout << "*                                           " << endl;
	cout << "*   1 for Medusa                            " << endl;
	cout << "*   2 for Barbarian                         " << endl;
	cout << "*   3 for Vampire                           " << endl;
	cout << "*   4 for Blue Men                          " << endl;
	cout << "*   5 for Harry Potter                      " << endl;
	cout << "*             OR                            " << endl;
	cout << "*   0 to exit the program                   " << endl;
	cout << "*                                           " << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << endl;
}

//create Creature switch
Creature* createCreature(int menuChoice)
{
	switch (menuChoice)
	{
	case 1:	//medusa
	{
		Creature* creatureOut = new Medusa(8);
		return creatureOut;
	}
	case 2:	//barbarian
	{
		Creature* creatureOut = new Barbarian(12);
		return creatureOut;
	}
	case 3: //vampire
	{
		Creature* creatureOut = new Vampire(18);
		return creatureOut;
	}
	case 4:	//blue men
	{
		Creature* creatureOut = new BlueMen(12);
		return creatureOut;
	}
	case 5:	//harry potter
	{
		Creature* creatureOut = new HarryPotter(10);
		return creatureOut;
	}
	} //end switch for create Creature
}