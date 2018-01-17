/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for room class derived from 
** space
***********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include "Space.hpp"

class Room :
	public Space
{
public:
	Room(std::string);
	~Room();
	void description(std::string);
	void print_rm_info(std::string file, int,int);
};

#endif

