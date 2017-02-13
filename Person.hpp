/*********************************************************************
** Program Filename: Person.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Person class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
#include "Space.hpp"
#include "Home.hpp"
#include "Backpack.hpp"

class Person
{

private:
std::string name;
Space *tracker;
Space* house;
int moveCount;
Backpack *bag;

public:
	Person(std::string name);
	~Person();
	void incrementMoveCount(int x);
	void setHome(Space *);
	std::string getName();
	void setName(std::string name);
	Space* getHome();
	int getMoveCount();
	Space* getTracker();
	void setTracker(Space *);
	Backpack* getBag();


};

#endif /* PERSON_HPP_ */
