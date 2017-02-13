/*********************************************************************
** Program Filename: Street.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for street class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef STREET_HPP_
#define STREET_HPP_
#include "Space.hpp"


class Street : public Space
{
public:
	Street(std::string id);
	~Street();
	void special (Backpack *bag);
};

#endif /* STREET_HPP_ */
