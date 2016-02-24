/*********************************************************************
** Program Filename: harryPotter.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: HarryPotter class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

//includes
#include "creature.hpp"

class HarryPotter : public Creature
{
protected:

public:
	//HarryPotter();
	HarryPotter(int);
	~HarryPotter();

	/*********************************************************************
	** Function: attack
	** Description: Generates and returns the sum of two random numbers 1-6.
	** Parameters: none
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net attack value
	*********************************************************************/
	int attack();

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
	int defend(int, int);

	string getName();
};

#endif