/*********************************************************************
** Program Filename: vampire.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Vampire class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

//includes
#include "creature.hpp"

class Vampire : public Creature
{
protected:

public:
	//Vampire();
	Vampire(int);
	~Vampire();

	/*********************************************************************
	** Function: attack
	** Description: Generates and returns a random number 1-12 as this
	** creature's attack value.
	** Parameters: none
	** Pre-Conditions:	random number seed using time is called in main.cpp
	** Post-Conditions: returns the net attack value
	*********************************************************************/
	int attack();

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
	int defend(int,int);

	string getName();
};

#endif