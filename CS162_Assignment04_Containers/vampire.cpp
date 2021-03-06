/*********************************************************************
** Program Filename: vampire.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Vampire class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "vampire.hpp"

//usings
using std::cout;
using std::endl;


Vampire::Vampire(int strengthIn, string givenName)
	: Creature(strengthIn, givenName)
{}

Vampire::~Vampire()
{
	//cout << "vampire deconstructor has run." << endl;
}



/*********************************************************************
** Function: attack
** Description: Generates and returns a random number 1-12 as this 
** creature's attack value.
** Parameters: none
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net attack value
*********************************************************************/
int Vampire::attack()
{
	int roll = (rand() % (12) + 1);		//random number from 1 to 12
	return roll;
}


/*********************************************************************
** Function: defend
** Description: Charm aspect gives a 50% chance that the opponnent does
** not attack when this funcion is called. If charm does not happen,
** defense value is random number 1 to 6, then 1 is added for armour.
** The net damage returned is the value of the incoming attack value,
** less the defense value calculated herein, but not less than 0.
** Parameters: Opponents "incomming" damage as an int
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net damage sustained by this creature
*********************************************************************/
int Vampire::defend(int damageIn, int x = 0)
{
	int charm = (rand() % (2) + 1);		//random number of 1 or 2
	if (charm == 2) return 200;
	else
	{
		int roll = (rand() % (6) + 1) + 1;		//random number from 1 to 6, plus armor value of 1
		if ((damageIn - roll) < 0) return 0;
		else return (damageIn - roll);
	}
}


/*********************************************************************
** Function: heal
** Description: Adds 9 to strength, but never sets strength to more
** than 18. Returns the amount added to strength.
** Parameters: none
** Pre-Conditions:	creature strength is not zero
** Post-Conditions: increases creature strength by 9 up to a max of 18
*********************************************************************/
int Vampire::heal()
{
	int heal = 0;
	int maxHeal = 18 - strength;
	if (maxHeal <= 9) heal = maxHeal;
	else heal = 9;
	strength = strength + heal;
	return heal;
}

string Vampire::getName()
{
	return "Vampire";
}