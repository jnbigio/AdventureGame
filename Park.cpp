/*********************************************************************
** Program Filename: Home.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Home class
** Input:N/A
** Output: N/A
*********************************************************************/
#include "Park.hpp"

/*********************************************************************
** Function: Park constructor
** Description: Constructor for Park class. Uses the base class constructor
** to initialize all the spaces, the win and lose variables, and the
** id passed in. hasKey is also intialized to false.
** Parameters: string representing the id is passed in
** Pre-Conditions: N/A
** Post-Conditions: A Park object is created
*********************************************************************/
Park::Park(std::string id, bool val) : Space(id)
{
	hasKey = val;

}

/*********************************************************************
** Function: Park destructor
** Description: Destructor for Park class
** Parameters: N/A
** Pre-Conditions: Park object must exist
** Post-Conditions: A Park object is destroyed
*********************************************************************/
Park::~Park()
{
	// TODO Auto-generated destructor stub
}


/*********************************************************************
** Function: setHasKey
** Description: sets the value of whether the park has key buried
** in the sandbox. This value is used in the special class that determines
** item interaction in a space
** Parameters: bool value representing if the key is in the space
** Pre-Conditions: Park object must exist
** Post-Conditions: The value of hasKey is updated to the parameter passed
** in
*********************************************************************/
void Park::setHasKey(bool val)
{
	hasKey = val;
}

/*********************************************************************
** Function: special
** Description: Function that determines how items can be used in a
** specific space. Function takes in a backpack pointer to determine
** what items the user has. If the backpack is empty user is told
** there are no items to use.  Otherwise the items in the bag are listed
** and the user selects what item they would like to use.
** Parameters: Pointer to backpack object
** Pre-Conditions: Park object must exist
** Post-Conditions: A statement is printed to the screen indicating
** to the user what action if any their item had.
*********************************************************************/
void Park::special(Backpack * bag)
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
		 * Only the shovel item makes an impact in this space. If
		 * the hasKey value is set to true then this means there is
		 * a key in the sandbox.  When the user utilizes the shovel
		 * item a key item will be created. The item will then be added
		 * to the space. This means that even if an item is found the user
		 * must then take the action to pick the item up.
		 */


		if (choice <= bag->getSize())
		{
			Item *useItem = bag->getItem(choice - 1);

			if (useItem != 0)
			{
				int action = useItem->getId();

				if ( action == 6 && !hasKey)
				{
					std::cout << "You dig in the sandbox and find nothing " << std::endl;
				}
				else if (action == 6 && this->hasKey)
				{
					std::cout << "You dig in the sandbox and find a key!!!";
					Item *key = new Item("Key", 100);
					drop(key);
				}
				else
				{
					std::cout << "Nothing happens " << std::endl;
				}
			}
		}
	}

}
