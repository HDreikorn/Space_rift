/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for CosmicBody class
***********************************************************************/
#include "CosmicBody.hpp"
#include "utility.hpp"

CosmicBody::CosmicBody(std::string n, C_Bod cbod_id): Space(n), id(cbod_id),
xtra_rm1(NULL), xtra_rm2(NULL) 
{
	if (id == C_Bod::ULNAR)  
	{
		load_map_U();
	}
	if (id == C_Bod::ZURIA)
	{
		load_map_Z();
	}
	if (id == C_Bod::CETA) 
	{
		load_map_C();
	}
	if (id == C_Bod::OOTS)
	{
		load_map_O(); 
	}

}

//destructor deletes all the contexts of the vectors
CosmicBody::~CosmicBody()
{	
	clean_up(rooms_Z);
	clean_up(rooms_U);
	clean_up(rooms_C);
	clean_up(rooms_O);
}

//this function give the description of the cosmic body
//upon arrival
void CosmicBody::description(std::string file)
{
	std::cout << get_name() << ":\n";
	readFile(file);
}

//load map will load all of the room of a cbody
//then store them in a vector to represent a map
//there is one for each planet

//ulnar
void CosmicBody::load_map_U()
{
	N = new Room("Government HQ (lobby)");
	S = new Room("AMR Lab (outside)");
	E = new Room("Spaceship");
	W = new Room("Fence");
	xtra_rm1 = new Room("Gaul's office");
	xtra_rm2 = new Room("AMR Lab (inside)");

	//creating back representation in vector
	rooms_U.push_back(N); //0
	rooms_U.push_back(xtra_rm1); //1
	rooms_U.push_back(S); //2
	rooms_U.push_back(xtra_rm2); //3
	rooms_U.push_back(E); //4
	rooms_U.push_back(W); //5
}
//zuria
void CosmicBody::load_map_Z()
{
	N = new Room("SSCS Lab (entrance)");
	S = new Room("Spaceship");
	E = new Room("Fence");
	W = new Room("Fence");
	xtra_rm1 = new Room("SSCS Lab (inside)");

	//creating back representation in vector
	rooms_Z.push_back(N); //0
	rooms_Z.push_back(xtra_rm1); //1
	rooms_Z.push_back(S); //2
	rooms_Z.push_back(E); //3
	rooms_Z.push_back(W); //4
}
//ceta
void CosmicBody::load_map_C()
{
	N = new Room("Chatsubo (bar)");
	xtra_rm1 = new Room("Hacktivist HQ");
	S = new Room("Ship");
	E = new Room("Market Place");
	W = new Room("Alley Way (Dead end)");

	//creating map representation in vector
	rooms_C.push_back(N); //0
	rooms_C.push_back(S); //1
	rooms_C.push_back(E); //2
	rooms_C.push_back(W); //3
	rooms_C.push_back(xtra_rm1); //4
}
//oots
void CosmicBody::load_map_O()
{
	N = new Room("Barren Lot");
	S = new Room("Spaceship");
	E = new Room("Abandoned Lab");
	W = new Room("Barren Street");

	//creating back representation in vector
	rooms_O.push_back(N); //0
	rooms_O.push_back(S); //1
	rooms_O.push_back(E); //2
	rooms_O.push_back(W); //3
}

void CosmicBody::clean_up(std::vector<Space*> &vec)
{
	for (unsigned i = 0; i < vec.size(); i++) {
		delete vec[i];
	}
}

void CosmicBody::print_rm_info(std::string file, int map_loc, int rm)
{
	if (map_loc == 0) { //ulnar
		std::cout << rooms_U[rm]->get_name() << ":\n";
	}
	if (map_loc == 1) { //zuria
		std::cout << rooms_Z[rm]->get_name() << ":\n";
	}
	if (map_loc == 2) { //ceta
		std::cout << rooms_C[rm]->get_name() << ":\n";
	}
	if (map_loc == 3) { //oots
		std::cout << rooms_O[rm]->get_name() << ":\n";
	}
	readFile(file);
}