/*********************************************************************
** Program Filename: Space.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Space class
** Input:N/A
** Output: N/A
*********************************************************************/

#include "Space.hpp"
#include <sstream>

/*********************************************************************
** Function: Space constructor
** Description: Constructor for Space class
** Parameters: string representing what type of space is being created
** Pre-Conditions: N/A
** Post-Conditions: A Space object is created with the id field initialized
** all space pointers set to null, and win and lose bools set to false.
*********************************************************************/
Space::Space(std::string id)
{
	this->id = id;
	left = 0;
	right = 0;
	down = 0;
	up = 0;
	win = false;
	lose = false;

}

/*********************************************************************
** Function: Space destructor
** Description: Destructor for Space class
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space object is destroyed
*********************************************************************/
Space::~Space()
{
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: toString
** Description: Function that details what items exist in the space, and
** provide other details about the space.
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A string containing the details of the space is returned
*********************************************************************/
std::string Space::toString()
{
	std::string description = "This is " + getId() + "\n";
	description += listItems();

	/*
	 * If the space is of the home type
	 * then the win information in the home is used
	 * to determine if the door is locked or unlocked
	 */

	if ( this->id.compare("home") == 0)
	{
		if (this->win)
		{
			description += "The house is unlocked \n";
		}
		else description += "The house is locked \n";
	}

	return description;
}

/*********************************************************************
** Function: listItems
** Description: Function that details what items exist in the space
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A string containing the details of the items in the
** space is returned
*********************************************************************/
std::string Space::listItems()
{
	std::string contents = "";

	if ( items.size() == 0)
	{
		contents += "There are no items here \n";
	}
	else
	{
		contents += "Here are a list of items that can be found here \n";
		std::stringstream tempString;

		for (int i = 0; i < items.size(); i++)
		{
			int num = (i + 1);
			tempString << num;
			tempString << ". ";
			tempString << items[i]->getName() << "\n";

		}
		contents += tempString.str();
	}
	return contents;
}



/*********************************************************************
** Function: getId
** Description: Function that returns the id of the space
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A string representing the id of the space is returned
*********************************************************************/
std::string Space::getId()
{
return id;
}

/*********************************************************************
** Function: pickup
** Description: Function that allows items to be picked up from space.
** Function first determines if there are any items to pick up. If there
** are items to pick up the user is prompted with a list of items that
** can be picked up. The user enters the corresponding number to pick the
** item they want up. If the number they select is greater than the number
** of items listed than no item is picked up. If they do select an item
** then the item they select is removed from the space.
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: An item pointer is removed from the space item vector
** and returned by the function. In cases where no items are present or
** the user didn't want an item a null pointer is returned.
*********************************************************************/
Item* Space::pickup()
{
	if (items.size() == 0)
	{
		std::cout << "There are no items to pick up " << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Please enter the number corresponding to the item you want to pickup: " << std::endl;
		std::cout << listItems();
		std::cout << items.size() + 1 << ". Don't remove any items \n" << std::endl;
		int choice;
		std::cin >> choice;

		if (choice <= items.size())
		{
			Item *pickup = items[choice - 1];
			items.erase(items.begin() + (choice - 1) );
			return pickup;
		}
		else return 0;
	}

}

/*********************************************************************
** Function: drop()
** Description: Function that takes in an item pointer and adds this
** pointer to the vector holding items in the space. The function
** checks to ensure that the pointer is not null before adding it
** to the vector of the space.
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: The object passed in is added to the vector that holds
** items provided the item passed in wasn't a null pointer
*********************************************************************/
void Space::drop(Item *drop)
{
	if (drop != 0)
	{
		items.push_back(drop);
	}


}

/*********************************************************************
** Function: itemsSize()
** Description: Function that returns the number of items in the space
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: An int representing the number of items in space is
** returned
*********************************************************************/
int Space::itemsSize()
{
	return items.size();
}

/*********************************************************************
** Function: getWin()
** Description: Function that returns bool variable of win
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A bool representing the value of win is returned
*********************************************************************/
bool Space::getWin()
{
return win;
}

/*********************************************************************
** Function: getLose()
** Description: Function that returns bool variable of lose
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A bool representing the value of lose is returned
*********************************************************************/
bool Space::getLose()
{
	return lose;
}

/*********************************************************************
** Function: getRight()
** Description: Function that returns Space pointer of right
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value to the right
** pointer is returned
*********************************************************************/
Space* Space::getRight()
{
return right;
}

/*********************************************************************
** Function: setRight()
** Description: Function that sets Space pointer of right
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value to the right
** is set with passed in parameter
*********************************************************************/
void Space::setRight(Space* r)
{
 right = r;
}

/*********************************************************************
** Function: getLeft()
** Description: Function that returns Space pointer of left
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value to the left
** pointer is returned
*********************************************************************/
Space* Space::getLeft()
{
return left;
}

/*********************************************************************
** Function: setLeft()
** Description: Function that sets Space pointer of left
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value to the left
** is set with passed in parameter
*********************************************************************/
void Space::setLeft(Space* l)
{
left = l;
}

/*********************************************************************
** Function: getUp()
** Description: Function that returns Space pointer of up
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value of the up
** pointer is returned
*********************************************************************/
Space* Space::getUp()
{
return up;
}

/*********************************************************************
** Function: setUp()
** Description: Function that sets Space pointer of up
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value up
** is set with passed in parameter
*********************************************************************/
void Space::setUp(Space* u)
{
up = u;
}

/*********************************************************************
** Function: getDown()
** Description: Function that returns Space pointer of down
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value of the down
** pointer is returned
*********************************************************************/
Space* Space::getDown()
{
return down;
}

/*********************************************************************
** Function: setUp()
** Description: Function that sets Space pointer of down
** Parameters: N/A
** Pre-Conditions: Space object must exist
** Post-Conditions: A Space pointer representing the value down
** is set with passed in parameter
*********************************************************************/
void Space::setDown(Space* d)
{
down = d;
}
