/*********************************************************************
** Program Filename: creature.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Creature class implementation file CS162_400 Assignment 4
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "creature.hpp"

//usings
using std::cout;
using std::endl;

Creature::Creature()
{
}

Creature::Creature(int strengthIn, string givenName)
{
	this->strength = strengthIn;
	this->givenName = givenName;
}

Creature::~Creature()
{
	//cout << "creature deconstructor has run" << endl;
}

int Creature::getStength()
{
	return strength;
}

void Creature::setStrength(int strengthIn)
{
	strength = strengthIn;
}
string Creature::getGivenName()  //get given name string
{
	return givenName;
}