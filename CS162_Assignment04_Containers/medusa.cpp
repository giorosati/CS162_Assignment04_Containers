/*********************************************************************
** Program Filename: medusa.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Medusa class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "medusa.hpp"

//usings
using std::cout;
using std::endl;

//Medusa::Medusa()
//{
//	strength = 0;
//}

Medusa::Medusa(int strengthIn, string givenName)
	: Creature(strengthIn, givenName)
{}

Medusa::~Medusa()
{
	//cout << "medusa deconstructor has run." << endl;
}

/*********************************************************************
** Function: attack
** Description: Generates and returns the sum of two random numbers 1-6,
** but if the sum is 12, function returns 100 used as a switch in main.
** Parameters: none
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net attack value or 200
*********************************************************************/
int Medusa::attack()
{
	int roll = (rand() % (6) + 1) + (rand() % (6) + 1);		//sum of two random numbers from 1 to 6
	if (roll == 12) return 100;		//set attack at 100 to use as a switch in main
	else return roll;
}

/*********************************************************************
** Function: defend
** Description: Calculates a random number 1 to 6, then adds 3 for armor.
** The net damage returned is the value of the incoming attack value,
** less the defense value calculated herein, but not less than 0.
** Parameters: Opponents "incomming" damage as an int
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net damage sustained by this creature
*********************************************************************/
int Medusa::defend(int damageIn, int x = 0)
{
	int roll = (rand() % (6) + 1) + 3;		//random number from 1 to 6 plus armor value of 3
	if ((damageIn - roll) < 0) return 0;
	else return (damageIn - roll);
}

/*********************************************************************
** Function: heal
** Description: Adds 4 to strength, but never sets strength to more
** than 8. Returns the amount added to strength.
** Parameters: none
** Pre-Conditions:	creature strength is not zero
** Post-Conditions: increases creature strength by 4 up to a max of 8
*********************************************************************/
int Medusa::heal()
{
	int heal = 0;
	int maxHeal = 8 - strength;
	if (maxHeal <= 4) heal = maxHeal;
	else heal = 4;
	strength = strength + heal;
	return heal;
}


string Medusa::getName()
{
	return "Medusa";
}