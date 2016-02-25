/*********************************************************************
** Program Filename: barbarian.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Barbarian class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef BRABARIAN_HPP
#define BRABARIAN_HPP

//includes
#include "creature.hpp"

class Barbarian : public Creature
{
protected:

public:
	//Barbarian();
	Barbarian(int, string);
	~Barbarian();

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
	** Description: Calculates the sum of two random number 1 to 6,
	** The net damage returned is the value of the incoming attack value,
	** less the defense value calculated herein, but not less than 0.
	** Parameters: Opponents "incomming" damage as an int
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net damage sustained by this creature
	*********************************************************************/
	int defend(int,int);

	/*********************************************************************
	** Function: heal
	** Description: Adds 6 to strength, but never sets strength to more
	** than 12. Returns the amount added to strength.
	** Parameters: none
	** Pre-Conditions:	creature strength is not zero
	** Post-Conditions: increases creature strength by 6 up to a max of 12
	*********************************************************************/
	int Barbarian::heal();

	string getName();
};

#endif