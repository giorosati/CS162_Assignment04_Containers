/*********************************************************************
** Program Filename: harryPotter.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: HarryPotter class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "harryPotter.hpp"

//usings
using std::cout;
using std::endl;

//HarryPotter::HarryPotter()
//{
//	strength = 0;
//}

HarryPotter::HarryPotter(int strengthIn, string givenName)
	: Creature(strengthIn, givenName)
{}

HarryPotter::~HarryPotter()
{
	//cout << "vampire deconstructor has run." << endl;
}

/*********************************************************************
** Function: attack
** Description: Generates and returns the sum of two random numbers 1-6.
** Parameters: none
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net attack value
*********************************************************************/
int HarryPotter::attack()
{
	int roll = (rand() % (6) + 1) + (rand() % (6) + 1);		//sum of two random numbers from 1 to 6
	return roll;
}

/*********************************************************************
** Function: defend
** Description: Calculates the sum of two random generated numbers from 1-6,
** then subtracts this value from the opposing creature's attack value received.
** If this result is greater than or equal to the current value of strength, and
** deathCount is 0, strength is increased to 20.
** If this result is less than the current value of strength, this value
** is returned.
** The net value returned is never less than 0.
** Parameters: Opponents "incomming" damage as an int, death counter as int
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net damage sustained by this creature
*********************************************************************/
int HarryPotter::defend(int damageIn, int deathCount)
{
	int roll = (rand() % (6) + 1) + (rand() % (6) + 1);		//sum of two random numbers from 1 to 6
	if (((damageIn - roll) >= strength) && (deathCount == 0))
	{
		strength = 20;
		return (damageIn - roll);
	}
	else if ((damageIn - roll) < 0) return 0;
	else return (damageIn - roll);
}

string HarryPotter::getName()
{
	return "Harry Potter";
}