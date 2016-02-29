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
Creature* createCreature(int menuChoice, string givenName);

int main()
{
	//initialize random number generator
	srand((unsigned)time(NULL));

	//initialize variables for program exit, menu choice, # of creatures
	int exitToggle = 0;
	int menuChoice1 = 6;
	int menuChoice2 = 6;
	int creatureCount = 0;
	int battleRoundCount = 0;
	string creatureName1 = "";
	string creatureName2 = "";

	//initialize linked lists for creature lineups
	doubleNode* p1Head = NULL;
	doubleNode* p2Head = NULL;
	doubleNode* p1Dead = NULL;
	doubleNode* p2Dead = NULL;

	bool testSwitch = false;  //used to automatically create creatures during testing
	if (!testSwitch)
	{
		cout << "***** Creature Battle Tournament  *****" << endl;
		cout << endl;
		cout << "Enter the number of Creatures for each player: " << endl;
		cin >> creatureCount;
	}
	//display menu
	while (exitToggle != 1)
	{
		if (!testSwitch)
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
					Creature* tempCreature1 = createCreature(menuChoice1, creatureName1);
					Creature* tempCreature2 = createCreature(menuChoice2, creatureName2);
					addNodeD(p1Head, tempCreature1);	//adds a node to the top of the player 1 linked list
					addNodeD(p2Head, tempCreature2);	//adds a node to the top of the player 2 linked list
				}
			}
		}
		else	//scenario two - create creatures for testing
		{
			Creature* tempCreature1 = createCreature(4, "Blue Men #1");
			Creature* tempCreature2 = createCreature(4, "Blue Men #2");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(3, "Vampire #1");
			tempCreature2 = createCreature(3, "Vampire #2");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(5, "Harry Potter #1");
			tempCreature2 = createCreature(5, "Harry Potter #2");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(5, "Harry Potter #3");
			tempCreature2 = createCreature(5, "Harry Potter #4");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(2, "Barbarian #1");
			tempCreature2 = createCreature(2, "Barbarian #2");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(1, "Medusa #1");
			tempCreature2 = createCreature(1, "Medusa #2");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(4, "Blue Men #3");
			tempCreature2 = createCreature(4, "Blue Men #4");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
			tempCreature1 = createCreature(3, "Vampire #3");
			tempCreature2 = createCreature(3, "Vampire #4");
			addNodeD(p1Head, tempCreature1);
			addNodeD(p2Head, tempCreature2);
		}

		//cout << "Creatures have been created..." << endl;
		if (exitToggle != 1) //enter the battle if user has not chosen 0
		{
			cout << "Player 1 creature lineup" << endl;
			displayD(p1Head);
			cout << endl;
			cout << endl;
			cout << "Player 2 creature lineup" << endl;
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
		while ((p1Head != NULL) && (p2Head != NULL))  //test if live creatures exist for both players
		{
			battleRoundCount += 1;
			cout << "Getting the creatures for battle # " << battleRoundCount << "..." << endl;
			cout << endl;

			bool creatureOneDeath = false;
			bool creatureTwoDeath = false;
			int attackRound = 0;		//attack rounds counter
			int harryDeathsC1 = 0;		//death count for a player 1 Harry Potter
			int harryDeathsC2 = 0;		//death count for a player 2 Harry Potter

			//get the top creature from each linked list for a battle
			Creature* creatureOne = NULL;
			Creature* creatureTwo = NULL;
			creatureOne = p1Head->creaturePointer;
			creatureTwo = p2Head->creaturePointer;
			//cout << "test for stop" << endl;
			cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " will fight for Player One." << endl;
			cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " will fight for Player Two." << endl;
			cout << endl;
			cout << "Press enter to start this battle." << endl;
			cin.get();

			//increment each creatures battles fought counter
			creatureOne->addBattleCount();
			creatureTwo->addBattleCount();

			//battle while loop for two creatures
			while ((creatureOne->getStength() > 0) && (creatureTwo->getStength() > 0))
			{
				attackRound += 1;		//increment attack counter
				cout << "*******************************************" << endl;
				cout << "Creature attack round # " << attackRound << endl;

				//creatureOne attack
				cout << endl;
				int tempDamage = creatureOne->attack();
				int netDamage = creatureTwo->defend(tempDamage, harryDeathsC2);
				if (netDamage == 200)	//test for vampire charm
				{
					cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " has used CHARM!" << endl;
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " was unable to attack." << endl;
					cout << endl;
				}
				else if (tempDamage == 100) //test if Medusa used glare
				{
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " has used GLARE!" << endl;
					if (!((harryDeathsC2 == 0) && (creatureTwo->getStength() == 20)))
						//kill sequence
					{
						creatureTwo->setStrength(0);		//kill creatureTwo except when Harry has been resurrected
					}
					else
					{
						harryDeathsC2 += 1;
						cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << "died but has been resurrected." << endl;
					}
				}
				else
				{
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " caused " << netDamage << " point(s) of damage!" << endl;
					if ((harryDeathsC2 == 0) && (creatureTwo->getStength() == 20))
					{
						harryDeathsC2 += 1;
						cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " died but has been resurrected." << endl;
					}
					else creatureTwo->setStrength(creatureTwo->getStength() - netDamage);
				}

				if (creatureTwo->getStength() <= 0)  //case where creatureTwo dies
				//kill sequence
				{
					creatureTwoDeath = true;
					creatureTwo->setStrength(0);
					cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " has died..." << endl;
				}
				else
				{
					cout << endl;
					//creatureTwo attack
					int tempDamage = creatureTwo->attack();
					int netDamage = creatureOne->defend(tempDamage, harryDeathsC1);
					if (netDamage == 200)	//test for vampire charm
					{
						cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " has used CHARM!" << endl;
						cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " was unable to attack." << endl;
						cout << endl;
					}
					else if (tempDamage == 100) //test if Medusa used glare
					{
						cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " has used GLARE!" << endl;
						if (!((harryDeathsC1 == 0) && (creatureOne->getStength() == 20)))
							//kill sequence
						{
							creatureOne->setStrength(0);		//kill creatureOne except when Harry has been resurrected
						}
						else
						{
							harryDeathsC1 += 1;
							cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " died but has been resurrected." << endl;
						}
					}
					else
					{
						cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " caused " << netDamage << " point(s) of damage!" << endl;
						if ((harryDeathsC1 == 0) && (creatureOne->getStength() == 20))
						{
							harryDeathsC1 += 1;
							cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " died but has been resurrected." << endl;
						}
						else creatureOne->setStrength(creatureOne->getStength() - netDamage);
					}

					if (creatureOne->getStength() <= 0)  //case where creature one dies
					//kill sequence
					{
						creatureOneDeath = true;
						creatureOne->setStrength(0);
						cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " has died..." << endl;
					}
				} //exit point when a creature has died

				cout << endl;
				if (creatureOneDeath == true)
				{
					cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " eliminated " << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << endl;
					creatureTwo->addWinCount();

					//add creatureOne to the dead stack for player 1
					addNodeTop(p1Dead, creatureOne);
					//delete the node for creatureOne on player 1's linked list
					removeFirstNodeD(p1Head);
					//move creatureTwo to the bottom of Player 2's queue
					moveHeadToEnd(p2Head);

					cout << endl;
					cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " had a strength of " << creatureTwo->getStength() << " at the end of the battle." << endl;
					creatureTwo->heal();
					cout << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << " will heal and have a strength of " << creatureTwo->getStength() << " before its next battle." << endl;
					cout << endl;
				}
				if (creatureTwoDeath == true)
				{
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " eliminated " << creatureTwo->getGivenName() << " (" << creatureTwo->getName() << ")" << endl;
					creatureOne->addWinCount();

					//add creatureTwo to the end of the dead stack for player 2
					addNodeTop(p2Dead, creatureTwo);
					//removes the first node on player 2's queue
					removeFirstNodeD(p2Head);
					//move creatureOne to the bottom of Player 1's queue
					moveHeadToEnd(p1Head);

					cout << endl;
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " had a strength of " << creatureOne->getStength() << " at the end of the battle." << endl;
					creatureOne->heal();
					cout << creatureOne->getGivenName() << " (" << creatureOne->getName() << ")" << " will heal and have a strength of " << creatureOne->getStength() << " before its next battle." << endl;
					cout << endl;
				}
				//cout << "Press enter to continue...";
				//cin.get();
			} //end of the two creature battle loop

			//add the number of rounds fought to each creature's prestige 
			creatureOne->addPrestige(attackRound);
			creatureTwo->addPrestige(attackRound);

			if ((p1Head != NULL) && (p2Head != NULL))
			{
				cout << "Both players still have live creatures, on to the next battle..." << endl;
				cout << "Press enter to continue." << endl;

				cin.get();
			}
			else { exitToggle = 1; }
		}
	}

	//end of game/exit while loop
	cout << endl;
	cout << endl;
	if (p1Head != NULL)		//case where Player 1 wins
	{
		cout << "Player One has won the tournament!" << endl;
		cout << endl;
		cout << "Player One ended the tournament with the following creatures still alive:" << endl;
		displayWins(p1Head);
		cout << endl;
		prestigeSort(p1Head);
		cout << endl;
		cout << endl;
	}
	else
	{
		cout << "Player Two has won the tournament!" << endl;
		cout << endl;
		cout << "Player Two ended the tournament with the following creatures still alive:" << endl;
		displayWins(p2Head);
		cout << endl;
		prestigeSort(p2Head);
		cout << endl;
		cout << endl;
	}
	cin.clear();
	cout << "Press enter to continue." << endl;
	cin.get();

	cout << "Player One lost the follwoing creatures in battle (by time since death, top = most recent)" << endl;
	displayWins(p1Dead);
	cout << endl;
	cout << endl;
	cout << "Player Two lost the follwoing creatures in battle (by time since death, top = most recent)" << endl;
	displayWins(p2Dead);
	cout << endl;
	cout << endl;

	//cin.ignore();
	cin.clear();
	cout << "Press enter to exit." << endl;
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
Creature* createCreature(int menuChoice, string creatureName)
{
	switch (menuChoice)
	{
	case 1:	//medusa
	{
		Creature* creatureOut = new Medusa(8, creatureName);
		return creatureOut;
	}
	case 2:	//barbarian
	{
		Creature* creatureOut = new Barbarian(12, creatureName);
		return creatureOut;
	}
	case 3: //vampire
	{
		Creature* creatureOut = new Vampire(18, creatureName);
		return creatureOut;
	}
	case 4:	//blue men
	{
		Creature* creatureOut = new BlueMen(12, creatureName);
		return creatureOut;
	}
	case 5:	//harry potter
	{
		Creature* creatureOut = new HarryPotter(10, creatureName);
		return creatureOut;
	}
	} //end switch for create Creature
}