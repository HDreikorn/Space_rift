/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for room class
***********************************************************************/
#include "Room.hpp"



Room::Room(std::string n): Space(n)
{
}


Room::~Room()
{
}

//this function give the description of the cosmic body
//upon arrival
void Room::description(std::string file)
{
	std::cout << get_name() << ":\n";
}

void Room::print_rm_info(std::string file, int map_loc, int)
{

}
