/*********************************************************************
** Program Filename: creature.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-23
** Description: Creature class header file CS162_400 Assignment 4
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

//includes
//#include <cstdlib>
//#include <string>

//usings
using std::string;

class Creature
{
protected:
	int strength;
	int battleCount;
	int winCount;
	int prestige;
	string givenName;

public:
	Creature();						//default constructor
	Creature(int, string);			//constructor w/int for strength
	~Creature();					//deconstructor
	virtual int attack() = 0;		//attack function prototype
	virtual int defend(int,int) = 0;		//defend function prototype
	virtual int heal() = 0;			//heal function prototype
	virtual string getName() = 0;	//displayName function prototype
	int getStength();				//getter for strength
	void setStrength(int);			//setter for strength
	int getWinCount();				//getter for winCount
	void addWinCount();				//adds 1 to winCount
	string getGivenName();			//get given name string
	int getBattleCount();			//returns the creatures battle count
	void addBattleCount();			//adds one to the creatures battle count
	int getPrestige();				//returns the creatures prestige
	void addPrestige(int);			//add prestige amount
};

#endif