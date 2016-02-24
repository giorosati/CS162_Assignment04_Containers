/*********************************************************************
** Program Filename: mainTest.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: main.cpp file for testing CS162_400 Assignment 4
*********************************************************************/

//includes
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
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

	//initialize variables for program exit and menu choice
	int exitToggle = 1;

	//initialize variables for two creatures
	Creature* creatureOne = NULL;
	Creature* creatureTwo = NULL;

	cout << "*****  Creature Battle Game  *****" << endl;
	cout << endl;

	//display menu
	while (exitToggle != 0)
	{
		//test section, have each creature battle each other type, indluding itself
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				creatureOne = createCreature(i);
				creatureTwo = createCreature(j);

				cout << "Creature One is " << creatureOne->getName() << endl;
				cout << "Creature Two is " << creatureTwo->getName() << endl;
				cout << endl;
				cout << "*******************************************" << endl;
				cout << endl;
				cout << "The battle begins...press enter." << endl;
				cout << endl;
				/*cin.ignore();
				cin.get();*/

				int attackRound = 0;		//attack rounds counter
				int harryDeathsC1 = 0;		//death count for a Creature One Harry Potter
				int harryDeathsC2 = 0;		//death count for a Creature Two Harry Potter

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
					//cout << "Press enter to continue...";
					//cin.get();
				}

				//end of game/exit while loop
				cout << endl;
				cout << endl;
				cout << "End of " << creatureOne->getName() << " vs. " << creatureTwo->getName() << endl;
				cout << "*******************************************" << endl;
				cout << "*******************************************" << endl;
				cout << "*******************************************" << endl;
				cout << endl;
				cout << endl;
				//cin.ignore();
				//cin.clear();
				cout << "Press enter to continue...";
				cin.get();
				if ((i == 5) && (j == 5)) exitToggle = 0;
			}
		}
		cin.ignore();
		cin.clear();
		cin.get();
	}	//end of while loop
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
	cout << "You will choose two Creatures for a battle." << endl;
	cout << "Please choose a type of Creature to do battle." << endl;
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