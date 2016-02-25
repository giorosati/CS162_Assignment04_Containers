/*********************************************************************
** Program Filename: medusa.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Medusa class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

//includes
#include "creature.hpp"

class Medusa : public Creature
{
protected:

public:
	//Medusa();
	Medusa(int, string);
	~Medusa();

	/*********************************************************************
	** Function: attack
	** Description: Generates and returns the sum of two random numbers 1-6,
	** but if the sum is 12, function returns 100 used as a switch in main.
	** Parameters: none
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net attack value or 200
	*********************************************************************/
	int attack();

	/*********************************************************************
	** Function: defend
	** Description: Calculates a random number 1 to 6, then adds 3 for armor.
	** The net damage returned is the value of the incoming attack value,
	** less the defense value calculated herein, but not less than 0.
	** Parameters: Opponents "incomming" damage as an int
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net damage sustained by this creature
	*********************************************************************/
	int defend(int,int);

	string getName();
};

#endif