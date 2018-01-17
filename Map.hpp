/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for the map class
***********************************************************************/
#include "Space.hpp"
#include "enums.hpp"
#include "Inventory.hpp"
#include <vector>

class Map
{
private:
	//bools for if planet has been visited, so they cant go back
	bool visited_U;
	bool visited_Z;
	bool visited_C;
	bool visited_O;
	bool visited_R;

	//cosmic body pointers for vector map
	Space *ulnar;
	Space *zuria;
	Space *rift;
	Space *ceta;
	Space *oots;

	//vector represents the map of the Procyon sytem
	std::vector<Space* > cbodies;

	Inventory inventory;

public:
	Map();
	~Map();
	void load_map();
	//these are the control function for each cosmic area
	bool move_on_U();
	bool move_on_Z();
	bool move_on_C();
	bool move_on_O();
	bool move_on_R();
	bool govHQ_actions();
	bool amr_actions();
	bool rift_actions();
	bool bar_actions();
	bool ootLab_actions();
	bool sscs_actions();

	//test
	void testing();

};

