/*********************************************************************
** Program Filename: barbarian.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Barbarian class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "barbarian.hpp"

//usings
using std::cout;
using std::endl;

//Barbarian::Barbarian()
//{
//	strength = 12;
//}

Barbarian::Barbarian(int strengthIn)
	: Creature(strengthIn)
{}

Barbarian::~Barbarian()
{
	//cout << "medusa deconstructor has run." << endl;
}

/*********************************************************************
** Function: attack
** Description: Generates and returns the sum of two random numbers 1-6.
** Parameters: none
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net attack value
*********************************************************************/
int Barbarian::attack()
{
	int roll = (rand() % (6) + 1) + (rand() % (6) + 1);		//sum of two random numbers from 1 to 6
	return roll;
}

/*********************************************************************
** Function: defend
** Description: Calculates the sum of two random number 1 to 6,
** The net damage returned is the value of the incoming attack value,
** less the defense value calculated herein, but not less than 0.
** Parameters: Opponents "incomming" damage as an int
** Pre-Conditions:	random number seed using time is called in main.cpp
** Post-Conditions: returns the net damage sustained by this creature
*********************************************************************/
int Barbarian::defend(int damageIn, int x = 0)
{
	int roll = (rand() % (6) + 1) + (rand() % (6) + 1);		//sum of two random numbers from 1 to 6
	if ((damageIn - roll) < 0) return 0;
	else return (damageIn - roll);
}

string Barbarian::getName()
{
	return "Barbarian";
}