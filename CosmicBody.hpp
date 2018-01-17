/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for cosmic body derived 
** class
***********************************************************************/
#include "Space.hpp"
#include "Room.hpp"
#include "enums.hpp"

#ifndef COSMICBODY_HPP
#define COSMICBODY_HPP

class CosmicBody :
	public Space
{
private:
	C_Bod id; //the id variable for cosmic body

	Space *xtra_rm1;
	Space *xtra_rm2;

	//vectors to store the map of rooms
	std::vector<Space*> rooms_U;
	std::vector<Space*> rooms_Z;
	std::vector<Space*> rooms_C;
	std::vector<Space*> rooms_O;

public:
	CosmicBody(std::string,C_Bod);
	~CosmicBody();
	void description(std::string);
	void load_map_U();
	void load_map_Z();
	void load_map_C();
	void load_map_O();
	void clean_up(std::vector<Space*> &);
	void print_rm_info(std::string, int map_loc, int rm);
};

#endif



