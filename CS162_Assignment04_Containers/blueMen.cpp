/*********************************************************************
** Program Filename: blueMen.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: BlueMen class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "blueMen.hpp"

//usings
using std::cout;
using std::endl;

BlueMen::BlueMen(int strengthIn, string givenName)
	: Creature(strengthIn, givenName)
{}

BlueMen::~BlueMen()
{
	//cout << "vampire deconstructor has run." << endl;
}

/*********************************************************************
** Function: attack
** Description: Generates and returns the sum of two random numbers 1-10.
** Parameters: none
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net attack value
*********************************************************************/
int BlueMen::attack()
{
	int roll = (rand() % (10) + 1) + (rand() % (10) + 1);		//sum of two random numbers from 1 to 10
	return roll;
}

/*********************************************************************
** Function: defend
** Description: If strength is greater than 8, calculates the sum of three
** random generated numbers from 1-6, then adds 3 for armor, then subtracts
** the value of the opposing creature's attack value.
** If strength is greater than 4 and less than 9, calculates the sum of two
** random generated numbers from 1-6, then adds 3 for armor, then subtracts
** the value of the opposing creature's attack value.
** Description: If strength is less than 5, generates a random number 1-6,
** then adds 3 for defense, then subtracts the value of the opposing
** creature's attack value.
** The net value calculated under one of these three scenatios is returned,
** but no less than 0.
** Parameters: Opponents "incomming" damage as an int
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net damage sustained by this creature
*********************************************************************/
int BlueMen::defend(int damageIn, int x = 0)
{
	int roll = 0;
	if (this->strength < 5)	//when strength is 4 or less, use only one die
	{
		//cout << "only one die used..." << endl;
		roll = (rand() % (6) + 1) + 3;	//random number from 1 to 6, plus 3 for armor
		if ((damageIn - roll) < 0) roll = 0;
	}
	else if ((this->strength > 4) && (this->strength < 9))	//if strength 5 to 8, only two die are used
	{
		//cout << "only two die used..." << endl;
		roll = (rand() % (6) + 1) + (rand() % (6) + 1) + 3;	//sum of two random numbers from 1 to 6, plus 3 for armour
		if ((damageIn - roll) < 0) roll = 0;
	}
	else
	{
		//cout << "three die used..." << endl;
		roll = (rand() % (6) + 1) + (rand() % (6) + 1) + (rand() % (6) + 1) + 3;	//sum of three random numbers from 1 to 6, plus 3 armor
		if ((damageIn - roll) < 0) roll = 0;
	}
	return roll;
}

/*********************************************************************
** Function: heal
** Description: Adds 6 to strength, but never sets strength to more
** than 12. Returns the amount added to strength.
** Parameters: none
** Pre-Conditions:	creature strength is not zero
** Post-Conditions: increases creature strength by 6 up to a max of 12
*********************************************************************/
int BlueMen::heal()
{
	int heal = 0;
	int maxHeal = 12 - strength;
	if (maxHeal <= 6) heal = maxHeal;
	else heal = 6;
	strength = strength + heal;
	return heal;
}

string BlueMen::getName()
{
	return "Blue Men";
}