/*********************************************************************
** Program Filename: Item.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Item class
** Input:N/A
** Output: N/A
*********************************************************************/

#include "Item.hpp"

/*********************************************************************
** Function: Item(string, int)
** Description: Constructor for Item class initalizes string, and name
** of item class.
** Parameters: String representing a name, and int representing an id are
** passed in. The id is utilized to identify the items more easily in other
** classes as opposed to having to determine string equivalences. The id
** relationsship is as follows:
** 1 stick
** 2 string
** 3 half coconut
** 6 shovel
** 100 key
** 1000 lock picking kit
** Pre-Conditions: N/A
** Post-Conditions: An Item object is created
*********************************************************************/
Item::Item(std::string name, int id)
{
	this->name = name;
	this ->id = id;

}

/*********************************************************************
** Function: Item destructor
** Description: Destructor for Item class
** Parameters: N/A
** Pre-Conditions: Item object must exist
** Post-Conditions: An Item object is destroyed
*********************************************************************/
Item::~Item()
{
	// TODO Auto-generated destructor stub
}


/*********************************************************************
** Function: setName(string name)
** Description: setter for name member variable
** Parameters: string representing a name
** Pre-Conditions: Item object must exist
** Post-Conditions: Name is set to parameter that was passed in
*********************************************************************/
void Item::setName(std::string name)
{
	this->name = name;
}

/*********************************************************************
** Function: setId(int id)
** Description: setter for id member variable
** Parameters: int representing an id
** Pre-Conditions: Item object must exist
** Post-Conditions: id is set to parameter that was passed in
*********************************************************************/
void Item::setId(int id)
{
	this->id = id;
}

/*********************************************************************
** Function: getName
** Description: getter for name member variable
** Parameters: N/A
** Pre-Conditions: Item object must exist
** Post-Conditions: string representing Name is returned
*********************************************************************/
std::string Item::getName()
{
	return name;
}

/*********************************************************************
** Function: getId
** Description: getter for id member variable
** Parameters: N/A
** Pre-Conditions: Item object must exist
** Post-Conditions: int representing id is returned
*********************************************************************/
int Item::getId()
{
	return id;
}
