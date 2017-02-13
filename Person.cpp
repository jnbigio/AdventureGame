/*********************************************************************
** Program Filename: Home.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Home class
** Input:N/A
** Output: N/A
*********************************************************************/

#include "Person.hpp"

/*********************************************************************
** Function: Person constructor
** Description: Constructor for Person class. Initializes the name
** with what is passed in, creates a new backpack, sets the house pointer
** and tracker pointer to null, and the moveCount to 0.
** Parameters: string representing the name is passed in
** Pre-Conditions: N/A
** Post-Conditions: A Person object is created
*********************************************************************/
Person::Person(std::string name)
{
	this->name = name;
	bag = new Backpack;
	tracker = 0;
	moveCount = 0;
	house = 0;

}

/*********************************************************************
** Function: Person destructor
** Description: Destructor for Person class
** Parameters: N/A
** Pre-Conditions: Person object must exist
** Post-Conditions: A Person object is destroyed
*********************************************************************/
Person::~Person() {
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: setHome()
** Description: setter for home pointer
** Parameters: A space pointer is passed in
** Pre-Conditions: Person object must exist
** Post-Conditions: A space pointer is set with the parameter that was
** passed in
*********************************************************************/
void Person::setHome(Space *h)
{
	house = h;
}

/*********************************************************************
** Function: getHome()
** Description: getter for home pointer
** Parameters: N/A
** Pre-Conditions: Person object must exist
** Post-Conditions: A home pointer is returned
*********************************************************************/
Space* Person::getHome()
{
	return house;
}

/*********************************************************************
** Function: getMoveCount()
** Description: getter for moveCount variable
** Parameters: none
** Pre-Conditions: Person object must exist
** Post-Conditions: The current moveCount is returned as an int
*********************************************************************/
int Person::getMoveCount()
{
	return moveCount;
}

/*********************************************************************
** Function: getName()
** Description: getter for name variable
** Parameters: none
** Pre-Conditions: Person object must exist
** Post-Conditions: The name of the player is returned as a string
*********************************************************************/
std::string Person::getName()
{
	return name;
}

/*********************************************************************
** Function: setName()
** Description: setter for name variable
** Parameters: string representing name
** Pre-Conditions: Person object must exist
** Post-Conditions: The name of the player is set to parameter passed
** in
*********************************************************************/
void Person::setName(std::string name)
{
	this->name = name;
}
/*********************************************************************
** Function: getTracker()
** Description: getter for tracker variable
** Parameters: none
** Pre-Conditions: Person object must exist
** Post-Conditions: A pointer to a space object representing the tracker
** is returned. The tracker represents where the player currently is
** on the map.
*********************************************************************/
Space* Person::getTracker()
{
	return tracker;
}

/*********************************************************************
** Function: setTracker()
** Description: setter for tracker variable
** Parameters: Space pointer
** Pre-Conditions: Person object must exist
** Post-Conditions: A pointer to a space object representing the tracker
** is set with the parameter passed in.
** The tracker represents where the player currently is on the map.
*********************************************************************/
void Person::setTracker(Space *t)
{
	tracker = t;
}

/*********************************************************************
** Function: setTracker()
** Description:
** Parameters: int representing current move
** Pre-Conditions: Person object must exist
** Post-Conditions: The moveCount is incremented by the parameter that
** was passed in.
*********************************************************************/
void Person::incrementMoveCount(int x)
{
	moveCount += x;

}

/*********************************************************************
** Function: getBag()
** Description: getter for backpack object member variable
** Parameters: N/A
** Pre-Conditions: Person object must exist
** Post-Conditions: A pointer to the backpack object of the person is
** returned.
*********************************************************************/
Backpack* Person::getBag()
{
	return bag;
}
