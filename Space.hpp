/*********************************************************************
** Program Filename: Space.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Space class
** Input:N/A
** Output: N/A
*********************************************************************/


#ifndef SPACE_HPP_
#define SPACE_HPP_
#include "Item.hpp"
#include <vector>
#include <iostream>
#include "Backpack.hpp"


class Space {

protected:
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	std::vector<Item*> items;
	std::string id;
	bool win;
	bool lose;

public:
	Space(std::string id);
	virtual ~Space();
	void virtual special(Backpack *) = 0;
	std::string toString();
	std::string getId();
	Item *pickup();
	std::string listItems();
	int itemsSize();
	void drop(Item *);
	bool getWin();
	bool getLose();
	Space* getRight();
	void setRight(Space*);
	Space* getLeft();
	void setLeft(Space*);
	Space* getUp();
	void setUp(Space*);
	Space* getDown();
	void setDown(Space*);
};

#endif /* SPACE_HPP_ */
