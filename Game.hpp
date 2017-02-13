/*********************************************************************
** Program Filename: Game.hpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description: Header file that provides class specification for Game class
** Input:N/A
** Output: N/A
*********************************************************************/

#ifndef GAME_HPP_
#define GAME_HPP_
#include "Person.hpp"
#include "Space.hpp"
#include "Park.hpp"
#include "Home.hpp"
#include "Street.hpp"
#include <string>
#include <iostream>

class Game {

private:
Person *player;
std::string help;

public:
	Game();
	~Game();
	bool validateMove(Space * s);
	void addItem();
	void dropItem();
	void move(char x);
	void action();
	void playGame();
	std::string getHelp();


};

#endif /* GAME_HPP_ */
