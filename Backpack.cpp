/*********************************************************************
** Program Filename: Backpack.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class implemenation for Backpack class
** Input:N/A
** Output: For certain functions statements are printed indicating what
** is going on in the program
*********************************************************************/

#include "Backpack.hpp"
#include <iostream>
#include <sstream>

/*********************************************************************
** Function: Backpack constructor
** Description: Constructor for Backpack class. Sets the mergeNum to 0.
** The mergeNum is a variable that is used to help determine when the
** string shovel, and coconut items can be joined to create a shovel.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: A Backpack object is created
*********************************************************************/
Backpack::Backpack()
{
	mergeNum = 0;
	capacity = 3;

}

/*********************************************************************
** Function: Backpack destructor
** Description: Destructor for Backpack class
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: An Backpack object is destroyed
*********************************************************************/
Backpack::~Backpack()
{
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: merge
** Description: Function that checks the mergeNum to determine if the
** string, coconut, and stick items can combine to create a shovel. The
** mergeNum represents the current sum of the items in the bag.This sum is
** updated every time an item is added or when an item is removed.
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: If the mergeNum equals 6. Then the first item in the
** backpack is transformed into a shovel, and the remaining two items in
** the backpack are removed.
*********************************************************************/
void Backpack::merge()
{
	if (mergeNum == 6)
	{
		bag[0]->setId(6);
		bag[0]->setName("Shovel");

		bag.erase(bag.begin()+1, bag.begin() + bag.size() );

		std::cout << "The shovel, coconut shell, and string have combined in your bag into a shovel!!!" << std::endl;
		std::cout << "The shovel only takes up one space in your backpack " << std::endl;
	}
}


/*********************************************************************
** Function: hasSpace
** Description: Function that determines if backpack has space
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: If the backpack has less than 3 items the function returns
** true otherwise the function returns false
** ********************************************************************/
bool Backpack::hasSpace()
{
	if (bag.size() < capacity)
	{
		return true;
	}

	return false;

}

/*********************************************************************
** Function: isEmpty
** Description: Function that determines if backpack is completely Empty
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: If the backpack has no items function returns
** true otherwise the function returns false
** ********************************************************************/
bool Backpack::isEmpty()
{
	if (bag.size() == 0)
	{
		return true;
	}
	else return false;
}

/*********************************************************************
** Function: getSize
** Description: Function that determines how many items are in bag
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: Returns an int that represents the number of items
** in the bag
** ********************************************************************/
int Backpack::getSize()
{
	return bag.size();
}

/*********************************************************************
** Function: getItem(int i)
** Description: Function that takes in an integer, and uses this
** integer as an index to return an item that is stored in the vector.
** Parameters: an int
** Pre-Conditions: Backpack object must exist
** Post-Conditions: Returns an item pointer. If the index is greater than
** the number of items in the vector an error is returned.
** ********************************************************************/
Item* Backpack::getItem(int i)
{
	if ( i < bag.size())
	{
		return bag[i];
	}
	else return 0;
}

/*********************************************************************
** Function: addItem(Item *add)
** Description: Function that takes in an item pointer, and adds the item
** to the bag if the backpack has space. The function also checks whether the
** item passed in is a null pointer to ensure that null pointers aren't added
** to the bag.
** Parameters: an Item pointer
** Pre-Conditions: Backpack object must exist
** Post-Conditions: Item that was passed in is added to the bag if the item
** wasn't null, and if the bag had capacity
** ********************************************************************/
void Backpack::addItem(Item *add)
{

	if (!hasSpace())
	{
		std::cout << "The bag is full " << std::endl;
	}
	else if (add == 0)
	{
		std::cout << "Nothing was added to the bag " << std::endl;
	}
	else
	{
		bag.push_back(add);
		std::cout << add->getName() << " was successfully added to the bag " << std::endl;

		mergeNum += add->getId();
		merge();
	}




}


/*********************************************************************
** Function: removeItem()
** Description: Function removes an item that the user specifies from the
** backpack if the backpack has items to remove
** Parameters: an Item pointer
** Pre-Conditions: Backpack object must exist
** Post-Conditions: Item that was passed in is added to the bag if the item
** wasn't null, and if the bag had capacity
** ********************************************************************/
Item* Backpack::removeItem()
{
	if (bag.size() == 0)
	{
		std::cout << "There is nothing to remove " << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Please enter the number corresponding to the item you want to remove " << std::endl;
		std::cout << this->toString();
		std::cout << bag.size() + 1 << ". Don't remove any items " << std::endl;
		int choice;
		std::cin >> choice;

		if (choice <= bag.size())
		{
			Item *remove = bag[choice-1];
			mergeNum -= remove->getId();
			bag.erase(bag.begin() + ( choice-1 ) );
			std::cout << "The item was successfully removed from your bag " << std::endl;
			return remove;
		}
		else
			return 0;
	}
}

/*********************************************************************
** Function: toString()
** Description: Function that returns a string representing all the items
** in the backpack.
** Parameters: N/A
** Pre-Conditions: Backpack object must exist
** Post-Conditions: String that indicates what items are in the back pack
** is returned.
** ********************************************************************/
std::string Backpack::toString()
{
	std::string contents = "";
	int i;
	std::stringstream tempString;
	for (i = 0; i < bag.size(); i++)
	{
		int num = i + 1;
		tempString << num  << ". " <<  bag[i]->getName() << "\n";
	}
	contents +=  tempString.str();


	return contents;

}
