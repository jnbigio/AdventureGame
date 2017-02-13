/*********************************************************************
** Program Filename: Backpack.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Backpack class
** Input:N/A
** Output: N/A
*********************************************************************/
#ifndef BACKPACK_HPP_
#define BACKPACK_HPP_
#include <vector>
#include "Item.hpp"

class Backpack
{
private:
std::vector<Item *> bag;
int capacity;
int mergeNum;
void merge();

public:
	Backpack();
	~Backpack();
	bool hasSpace();
	bool isEmpty();
	int getSize();
	Item* getItem(int i);
	void addItem(Item *);
	Item* removeItem();
	std::string toString();
};

#endif /* BACKPACK_HPP_ */
