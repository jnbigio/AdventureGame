/*********************************************************************
** Program Filename: Home.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Home class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef HOME_HPP_
#define HOME_HPP_
#include "Space.hpp"


class Home : public Space
{
public:
	Home(std::string name);
	~Home();
	void special (Backpack *);
};

#endif /* HOME_HPP_ */
