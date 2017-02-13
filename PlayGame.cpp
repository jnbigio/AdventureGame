/*********************************************************************
** Program Filename: PlayGame.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that  plays the game
** Input: The user inputs a string for their name, and characters and numbers
** to indicate their choices as they play the game
** Output: Strings indicating to the user their progress throughout the
** game.
*********************************************************************/
#include "Game.hpp"

int main()
{
	std::cout << "Welcome to the \"Child's Play\"!!!!! \n"
			 << "\nIn this game you play as a child who has left "
			 << "\nhis house without their parent's permission."
			 << "\nUnfortunately the child can't find their keys and can't \n"
			 << "really remember if they had their keys with them " << std::endl;

	std::cout << "\n\nIn order to win the game you must make it back to your home in time \n"
			 << "before your parents realize you left. To do this you will navigate around the map \n"
			 << "looking for your keys or items that might help you get into your house. \n"
			 << "Be careful because if the item doesn't work your parents might hear your attempt to get in" << std::endl;

	Game childsPlay;

	std::cout << "\n\nBefore you begin here are the controls " << std::endl;
	std::cout <<  childsPlay.getHelp();

	std::cout << "The game will now begin " << std::endl;

	childsPlay.playGame();



}
