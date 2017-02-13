/*********************************************************************
** Program Filename: Park.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Park class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef PARK_HPP_
#define PARK_HPP_
#include "Space.hpp"


class Park : public Space
{
private:
	bool hasKey;

public:
	Park(std::string id, bool val);
	~Park();
	void setHasKey(bool );
	void special (Backpack *bag);
};

#endif /* PARK_HPP_ */
