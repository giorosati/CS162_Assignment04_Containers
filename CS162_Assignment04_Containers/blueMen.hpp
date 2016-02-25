/*********************************************************************
** Program Filename: blueMen.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: BlueMen class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

//includes
#include "creature.hpp"

class BlueMen : public Creature
{
protected:

public:
	//BlueMen();
	BlueMen(int, string);
	~BlueMen();

	/*********************************************************************
	** Function: attack
	** Description: Generates and returns the sum of two random numbers 1-10.
	** Parameters: none
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net attack value
	*********************************************************************/
	int attack();

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
	int defend(int, int);

	string getName();
};

#endif
