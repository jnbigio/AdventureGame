/*********************************************************************
** Program Filename: Home.cpp
** Author:Jose Bigio
** Date: December 5th, 2015
** Description:File that provides class Implementation for Home class
** Input:N/A
** Output: N/A
*********************************************************************/

#include "Game.hpp"


/*********************************************************************
** Function: Game constructor
** Description: Constructor for Game class. Creates 8 spaces, and links the
** 8 spaces to create a map. The spaces are initialized with corresponding names.
** 4 Items are created, and placed in their corresponding spaces. The player object
** is initialized, and the name of the player is set to the name that the player
** has specified.
** Pre-Conditions: N/A
** Post-Conditions: A Game object is created
*********************************************************************/
Game::Game()
{

help = "a left \ns down \nw up \nd right \n";
help += "x drop item \nz use item \no observe space \n";
help +=	 "p pick up item \nh help \n";

Space *street1 = new Street("street1");
Space *street2 = new Street("street2");
Space *street3 = new Street("street3");
Space *street4 = new Street("street4");
Space *street5 = new Street("street5");

Space *park1 = new Park("park1", true);
Space *park2 = new Park("park2", false);

Space *home = new Home("home");

street1->setRight(street2);
street1->setDown(park1);

park1->setUp(street1);
park1->setDown(street3);
park1->setRight(park2);


street3->setUp(park1);
street3->setRight(street4);

street2->setLeft(street1);
street2->setDown(park2);

park2->setLeft(park1);
park2->setDown(street4);
park2->setUp(street2);
park2->setRight(street5);

street4->setLeft(street3);
street4->setUp(park2);

street5->setLeft(park2);
street5->setRight(home);

home->setLeft(street5);

Item *string = new Item("string", 2);
Item *stick = new Item("stick", 1);
Item *coconut = new Item("half a coconut", 3);
Item *lockPickKit = new Item("lockPickKit", 1000);

street1->drop(stick);
street2->drop(coconut);
street3->drop(lockPickKit);
street4->drop(string);

std::string name;
std::cout << "Please enter a name for your character: ";
std::cin >> name;

player = new Person("Bob");
player->setName(name);
player->setHome(home);
player->setTracker(park2);

}

/*********************************************************************
** Function: Game destructor
** Description: Destructor for Game class
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: A Game object is destroyed
*********************************************************************/
Game::~Game()
{
	// TODO Auto-generated destructor stub
}


/*********************************************************************
** Function: addItem
** Description: Function adds an item to the players bag. In order for
** an item to be added the current space the player is in, must have items
** to pick, and the player must have space in their bag to add items.
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: The item the user has specified is added to their
** bag.
*********************************************************************/
void Game::addItem()
{
	if ( ( player->getBag()->hasSpace() ) && player->getTracker()->itemsSize() > 0 )
	{
		player->getBag()->addItem(player->getTracker()->pickup());
	}
	else if ( !( player->getBag()->hasSpace() ) )
	{
		std::cout << "The bag is full " << std::endl;
	}
	else
	{
		std::cout << "There are no items to pick up" << std::endl;
	}

}

/*********************************************************************
** Function: dropItem
** Description: Function drops an item from the players bag. In order for
** an item to be dropped the player must have items in their bag.
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: The item the user has specified to drop
** is added to the space they were in.
*********************************************************************/
void Game::dropItem()
{
	if ( !( player->getBag()->isEmpty() ) )
	{
		player->getTracker()->drop(player->getBag()->removeItem());
	}
	else
	{
		std::cout << "There are no items to drop " << std::endl;
	}
}

/*********************************************************************
** Function: move
** Description: Function allows the player to specify what direction
** they would like to move in. If the direction points to a null pointer
** it is indicated to the user that they can't go in that direction.
** Parameters: A character representing the direction the user wants to
** go in.
** Pre-Conditions: Game object must exist
** Post-Conditions: If the direction the user wants to go in is valid, the
** user is sent to that direction, their tracker is updated to the new position
** information about where they are is printed, and the move count is incremented.
*********************************************************************/
void Game::move(char x)
{

	switch(x)
	{
	case 'a':
		{
			if (validateMove(player->getTracker()->getLeft()) )
			{
				player->setTracker(player->getTracker()->getLeft());
				std::cout << "You are now in "  << player->getTracker()->getId() << std::endl;
				player->incrementMoveCount(1);
			}
			else std::cout << "There is nothing in that direction " << std::endl;
		}
		break;


	case 'w':
		{
			if (validateMove(player->getTracker()->getUp()) )
			{
				player->setTracker(player->getTracker()->getUp());
				std::cout << "You are now in "  << player->getTracker()->getId() << std::endl;
				player->incrementMoveCount(1);
			}
			else std::cout << "There is nothing in that direction " << std::endl;
		}
		break;

	case 'd':
		{
			if (validateMove(player->getTracker()->getRight()) )
			{
			player->setTracker(player->getTracker()->getRight());
			std::cout << "You are now in "  << player->getTracker()->getId() << std::endl;
			player->incrementMoveCount(1);
			}
			else std::cout << "There is nothing in that direction " << std::endl;
		}
		break;

	case 's':
		{
			if (validateMove(player->getTracker()->getDown()) )
			{
				player->setTracker(player->getTracker()->getDown());
				std::cout << "You are now in "  << player->getTracker()->getId() << std::endl;
				player->incrementMoveCount(1);
			}
			else std::cout << "There is nothing in that direction " << std::endl;
		}
		break;




	}
}

/*********************************************************************
** Function: validateMove
** Description: Function takes in a space pointer, and if the space
** pointer isn't null returns true otherwise returns false
** Parameters: Space pointer
** Pre-Conditions: Game object must exist
** Post-Conditions: Returns a bool value indicating whether space pointer
** is null.
*********************************************************************/
bool Game::validateMove(Space *s)
{
	if (s != 0)
	{
		return true;
	}
	else
		return false;
}

/*********************************************************************
** Function: action
** Description: Function that provides a menu to the user to indicate
** what action they want to do.
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: The action the user has selected is performed
*********************************************************************/
void Game::action()
{
	char playerAction;
	std::cin >> playerAction;

	switch(playerAction)
	{
		case 'w':
		case 'a':
		case 's':
		case 'd': move(playerAction);
		break;

		case 'h' : std::cout << help;
			break;
		case 'o' : std::cout << player->getTracker()->toString();
			break;
		case 'p' : addItem();
			break;
		case 'x' : dropItem();
			break;
		case 'z' : player->getTracker()->special(player->getBag());
			break;
	}
}

/*********************************************************************
** Function: getHelp()
** Description:Function returns string that represents the controls
** of the game.
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: The string of help is returned.
*********************************************************************/
std::string Game::getHelp()
{
	return help;

}

/*********************************************************************
** Function: playGame
** Description:Function executes the game. The function takes user input to
** perform selected action. As long as the user has lost the game, won the game
** or run out of moves then the user can continue to input actions.
** Parameters: N/A
** Pre-Conditions: Game object must exist
** Post-Conditions: The item the user has specified to drop
** is added to the space they were in.
*********************************************************************/
void Game::playGame()
{
	while (player->getMoveCount() <= 30 && ! (player->getHome()->getWin() ) && !( player->getHome()->getLose() ) )
	{
		action();

	}


	if (player->getHome()->getWin())
	{
		std::cout << "\n\nCongrats again for winning the game!!!";
	}
	else if (player->getMoveCount() > 30)
	{
		std::cout << "Sorry  " << player->getName() << " you ran out of moves" << std::endl;
	}


	std::cout <<"\nThank you for playing " << player->getName() << std::endl;

}
