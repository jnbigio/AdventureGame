/*
 * Street.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: josebigio
 */

#include "Street.hpp"
/*********************************************************************
** Function: Home constructor
** Description: Constructor for Space class. Uses the base class constructor
** to initialize all the spaces, the win and lose variables, and the
** id passed in.
** Parameters: string representing the id is passed in
** Pre-Conditions: N/A
** Post-Conditions: A Street object is created
*********************************************************************/
Street::Street(std::string id) : Space(id)
{

}

/*********************************************************************
** Function: Street destructor
** Description: Destructor for Street class
** Parameters: N/A
** Pre-Conditions: Street object must exist
** Post-Conditions: A Street object is destroyed
*********************************************************************/
Street::~Street()
{
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: special
** Description: Function that determines how items can be used in a
** specific space. Function takes in a backpack pointer to determine
** what items the user has. If the backpack is empty user is told
** there are no items to use.  Otherwise the items in the bag are listed
** and the user selects what item they would like to use.
** Parameters: Pointer to backpack object
** Pre-Conditions: Home object must exist
** Post-Conditions: A statement is printed to the screen indicating
** to the user what action if any their item had.
*********************************************************************/
void Street::special(Backpack *bag)
{
if (bag->isEmpty())
{
	std::cout << "The bag is empty, you have no items to use " << std::endl;
}
else
{
	std::cout << "Please enter an item corresponding to the item you would like to use: " << std::endl;
	std::cout << bag->toString();
	int choice;
	std::cin >> choice;

	/*
	 * If the user choice is one of the possible selections the id
	 * of the item is used to determine the action.
	 *
	 * In the street class no item interaction can really happen,
	 * if statements are used to provide more detailed descriptions
	 * that the item didn't work. For, example if the key is used the
	 * user is told there is nothing to dig.
	 *
	 */

	if (choice <= bag->getSize())
	{
		Item *useItem = bag->getItem(choice - 1);

		if (useItem != 0)
		{
			int action = useItem->getId();

			if (action == 100 || action == 1000)
			{
				std::cout << "There are no doors to unlock here " << std::endl;
			}
			else if (action == 6)
			{
				std::cout << "There is nothing to dig here ";
			}
			else
			{
				std::cout << "Nothing happens " << std::endl;
			}

		}
	}
}

}
