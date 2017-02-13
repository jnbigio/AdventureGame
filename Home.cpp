/*********************************************************************
** Program Filename: Home.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Home class
** Input:N/A
** Output: N/A
*********************************************************************/
#include "Home.hpp"
#include <cstdlib>	//Include cstdlib for the random function
#include <ctime>	//Include ctime to provide time as the seed for the random number


/*********************************************************************
** Function: Home constructor
** Description: Constructor for Home class. Uses the base class constructor
** to initialize all the spaces, the win and lose variables, and the
** id passed in.
** Parameters: string representing the id is passed in
** Pre-Conditions: N/A
** Post-Conditions: A Home object is created
*********************************************************************/
Home::Home(std::string id) : Space(id)
{
	// TODO Auto-generated constructor stub

}


/*********************************************************************
** Function: Home destructor
** Description: Destructor for Home class
** Parameters: N/A
** Pre-Conditions: Home object must exist
** Post-Conditions: A Home object is destroyed
*********************************************************************/
Home::~Home() {
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
void Home::special(Backpack *bag)
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
	 * If the user selects an item from within the list then the item id is
	 * used to determine what impact the item will have. To win the game
	 * the user must have a key which is item id 100. In this case the
	 * win variable is set to true, and the user is told they won.
	 *
	 * The user also has a chance to win with a lock picking kit. This
	 * doesn't always succeed, so a random number is used to provide
	 * success only 25% of the time. If the user is successful they win
	 * and win is set to true. If the user is unsuccessful they lose the
	 * game because their parents notice them
	 *
	 * If the user tries to use the shovel they are told that digging under
	 * their home is too risky. With all other items nothing happens
	 *
	 */


	if (choice <= bag->getSize())
	{
		Item *useItem = bag->getItem(choice - 1);

		if (useItem != 0)
		{
			int action = useItem->getId();

			if (action == 100)
			{
				std::cout << "You unlock your door and make it home safely without anyone noticing " << std::endl;
				std::cout << "Congrats you have won " << std::endl;
				win = true;
			}
			else if (action == 6)
			{
				std::cout << "Digging under your home is way too risky and probably very obvious " << std::endl;
			}
			else if (action == 1000)
			{
				srand(time(0));	//Set the seed for the random number generator

				int breakingIn = rand() % 100 + 1;
				if (breakingIn <= 25 )
				{
					std::cout << "You manage to pick the lock, and make it back without anyone noticing " << std::endl;
					std::cout << "Congrats you have won " << std::endl;
					win = true;
				}
				else
				{
					std::cout << "You fail at picking the lock your parents catch you! " << std::endl;
					std::cout << "Sorry you have lost";
					lose = true;
				}

			}
			else
			{
				std::cout << "Nothing happens " << std::endl;
			}

		}
	}
}
}
