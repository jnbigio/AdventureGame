/*********************************************************************
** Program Filename: Item.hpp
** Author:Jose Bigio
** Date:September 29th 2015
** Description:Header file that provides class specification for Item class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef ITEM_HPP_
#define ITEM_HPP_
#include <string>

class Item {

private:
	std::string name;
	int id;

public:
	Item(std::string name, int id);
	~Item();
	void setName(std::string name);
	void setId(int id);
	std::string getName();
	int getId();
};

#endif /* ITEM_HPP_ */
