/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is a text adventure game that has the user playing
** as the main character who is assignemd to stop a time rift from
** destroying the universe. The user is sent to various plants and places
** on each of those planets until the user has either perished alongside
** the rest of the world or everyone is saved.
***********************************************************************/
//Title artwork provided by:
//http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
#include <iostream>
//#include <vld.h>
#include <string>
#include "utility.hpp"
#include "Menu.hpp"
#include "Map.hpp"
#include "GameEngine.hpp"

int main() {
	std::cout << "     ** Game Goal: Close the rift in five days **\n";

	GameEngine space_rift;
	space_rift.intro();
	space_rift.run();
	//space_rift.test();

	return 0;
}
