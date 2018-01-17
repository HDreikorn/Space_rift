/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for abstract space class
***********************************************************************/
#include "CosmicBody.hpp"
#include "Room.hpp"
#include "Map.hpp"
#include "utility.hpp"
#include "Menu.hpp"


Map::Map(): visited_U(false), visited_Z(false), visited_C(false),
visited_O(false), visited_R(false) {

	ulnar = new CosmicBody("Ulnar", C_Bod::ULNAR);

	zuria = new CosmicBody("Zuria", C_Bod::ZURIA);

	ceta = new CosmicBody("Ceta Station", C_Bod::CETA);

	oots = new CosmicBody("Oots", C_Bod::OOTS);

	rift = new CosmicBody("Rift", C_Bod::RIFT);
}


Map::~Map() {
	for (unsigned i = 0; i < cbodies.size(); i++) {
		delete cbodies[i];
	}
	cbodies.clear();
}

//this function loads the cosmic bods into a vector
//that will represent a map
void Map::load_map() {
	cbodies.push_back(ulnar); //0
	cbodies.push_back(zuria); //1
	cbodies.push_back(ceta); //2
	cbodies.push_back(oots); //3
	cbodies.push_back(rift); //4
}

//move_on_% fxns will control the possible moves for landing
//on particular cosmic body

//for ulnar
bool Map::move_on_U() {
	if (visited_Z) {
		readFile("nothing_left.txt");
		return false;
	}
	else {
		//make sure building are only visted once
		bool vis_HQ = false;
		bool vis_AMR = false;

		cbodies[0]->description("ulnar.txt");
		bool game_end = false;

		//leave when ship direction is selected
		//otherwise keep choosing direction
		bool leave = false;
		int direction;

		while (!leave) {
			direction = menuOptions("North", "South", "East", "West");
			switch (direction) {
			case NORTH: //gov HQ
				if (!vis_HQ) {
				game_end = govHQ_actions();
				if (game_end) { leave = true;}//leave and end game if user picks that
				vis_HQ = true;
				}
				else {
					readFile("nothing_left.txt");
				}
			break;
			case SOUTH: //AMR lab
				if (vis_HQ && vis_AMR) { //can't go back in
					readFile("nothing_left.txt");
				}
				else if (vis_HQ) {
					game_end = amr_actions();
					vis_AMR = true;
				}
				else {
					std::cout << "Nothing to do here, yet. Check HQ!\n";
				}
				break;
			case EAST: std::cout << "Fence: You can't go this way\n";
				break;
			case WEST:  //ship
				if (vis_HQ && vis_AMR) {
					std::cout << "Back on the ship!\n";
					visited_U = true;
					leave = true; //leave when both places visited
				}
				else {
					std::cout << "Can't leave with unfinished business!\n";
				}
				break;
			default: //shouldn't happen
				std::cout << "Unexpected error!\n";
				break;
			}
		}return game_end;
	}
}
//for zuria, returns t or false for end game
bool Map::move_on_Z() {
	bool end_game = false;
	if (!visited_U) {
		std::cout << cbodies[1]->get_name() << ":\n";
		readFile("wrong_day1.txt");
		return false;
	}
	else {
		bool vis_sscs = false; //for visit to sscs lab to ok leave
		int direction;
		bool leave = false; //breaks loop when leave is ok
		cbodies[1]->description("zuria.txt");

		while (!leave) {
			direction = menuOptions("North", "South", "East", "West");

			switch (direction) {
			case NORTH: //sscs lab
				end_game = sscs_actions();
				vis_sscs = true;
				if (end_game) { leave = true; }
				break;
			case SOUTH: //ship
				if (vis_sscs) {
					std::cout << "Back on the ship!\n";
					visited_Z = true;
					leave = true;
				}
				else {
					std::cout << "Can't leave with unfinished business!\n";
				}
				break;
			case EAST: //fence
				std::cout << "Fence: You can't go this way\n";
				break;
			case WEST: //fence
				std::cout << "Fence: You can't go this way\n";
				break;
			default: //shouldn't happen
				std::cout << "Unexpected error!\n";
				break;
			}
		}
	}
}
//for ceta, returns true or false for end game
bool Map::move_on_C() {

	bool end_game = false;
	if (!visited_U) {
		std::cout << cbodies[2]->get_name() << ":\n";
		readFile("wrong_day1.txt");
	}
	else if (!visited_R) {
		std::cout << cbodies[2]->get_name() << ":\n";
		std::cout << "\nYou have no business here. *Leaving*\n";
	}
	else {
		bool vis_H_HQ = false; //for visit to hacker's HQ
		int direction;
		bool leave = false;
		cbodies[2]->description("ceta.txt");
		while (!leave) {
		direction = menuOptions("North", "South", "East", "West");

			switch (direction) {
			case NORTH: //bar and HQ
				if (!vis_H_HQ) {
					end_game = bar_actions();
					vis_H_HQ = true;
				}
				else {
					std::cout << "No point going back.\n";
				}
				break;
			case SOUTH: //ship
				if (vis_H_HQ) {
					std::cout << "Back on the ship!\n";
					visited_C = true;
					leave = true;
				}
				else {
					std::cout << "Can't leave with unfinished business!\n";
				}
				break;
			case EAST: //market place
				if (vis_H_HQ) {
					std::cout << "No time to waste at market!\n";
				}
				else {
					std::cout << "You lost a vital day in the market.\n"
						<< "There is no way you can finish now!\n GAME OVER\n";
					leave = true;
					end_game = true;
				}
				break;
			case WEST: //deadend alley
				std::cout << "Deadend Alley: You can't go this way\n";
				break;
			default: //shouldn't happen
				std::cout << "Unexpected error!\n";
				break;
			}
		}
	}
	return end_game;
}
//for oots, returns t or f for end game
bool Map::move_on_O() {
	bool end_game = false;
	if (!visited_U) {
		std::cout << cbodies[3]->get_name() << ":\n";
		readFile("wrong_day1.txt");
		return false;
	}
	else if (!visited_R || !visited_C) {
		std::cout << cbodies[3]->get_name() << ":\n";
		std::cout << "\nYou have no business here. ** Leaving **\n";
	}
	else {
		bool vis_lab = false; //for visit to abandoned lab
		int direction;
		bool leave = false;
		cbodies[3]->description("oots.txt");
		while (!leave) {
			direction = menuOptions("North", "South", "East", "West");

			switch (direction) {
			case NORTH: //barren lot
				std::cout << "Barren Lot: You can't go this way\n";
				break;
			case SOUTH: //ship
				if (vis_lab) {
					std::cout << "Back on the ship!\n";
					visited_O = true;
					leave = true;
				}
				else {
					std::cout << "Can't leave with unfinished business!\n";
				}
				break;
			case EAST: //lab
				if (!vis_lab) {
					end_game = ootLab_actions();
					if (end_game) { leave = true; }
					vis_lab = true;
				}
				else {
					std::cout << "You've already finsihed here.\n";
				}
				break;
			case WEST: //empty street
				std::cout << "Empty Street: You can't go this way\n";
				break;
			default: //shouldn't happen
				std::cout << "Unexpected error!\n";
				break;
			}
		}
	}
	return end_game;
}
//for rift, returns t or f for end game
bool Map::move_on_R() {
	bool end_game = false;
	if (!visited_U) {
		std::cout << cbodies[4]->get_name() << ":\n";
		readFile("wrong_day1.txt");
	}
	else if (visited_R) {
		readFile("nothing_left.txt");
	}
	else {
		end_game = rift_actions();
		if (!end_game) { visited_R = true; }
	}
	return end_game;
}

//this is the fucntion that takes care of all the options n
// gove HQ, returns status of game end as bool
bool Map::govHQ_actions() {
	cbodies[0]->print_rm_info("govHQ.txt", 0, 0);
	//choice to continue or end
	int choice = menuOptions("Of course, I need to know what is going on",
		"I'm over it, I'm just gonna stay here and vacation");
	if (choice == 2) {
		std::cout << "\nGAME OVER. The universe has ended.\n";
		 return true;
	}
	else {
		cbodies[0]->print_rm_info("office.txt", 0, 1);
		//choice to answer questions
		choice = menuOptions("Oh that's right!How long do we have?",
			"Nah, I'm sure I'll figure it out before too late");
		if (choice == 1) {
			readFile("questions.txt");
		}
		readFile("end_office.txt");
		choice = menuOptions("Take items and leave", "Leave");
		if (choice == 1) {
			inventory.add_item("special access badge");
		}
		std::cout << "** Leaving Government HQ ** \n";
		return false;
	}
}
//this function controls the flow of he actions that take
//place at the amr lab it return a bool to indicate if
//the game has ended
bool Map::amr_actions() {
	bool end_game = false;
	cbodies[0]->print_rm_info("amr.txt", 0, 2);
	inventory.print_inventory();
	int search = inventory.search_inventory("special access badge");
	if (search == -1) {
		std::cout << "HERB ran back and get the badge for you!\n";
		inventory.add_item("special access badge");
		search = 1;
	}
	if (search != -1) {
		std::cout << "** Unloocking door with badge **\n";
		cbodies[0]->print_rm_info("amr_inside.txt", 0, 3);
		//answers to any questions
		int choice = menuOptions("Take items, leave", "Any dangers?");
		if (choice == 1) {
			inventory.add_item("sample containers");
		}
		else {
			readFile("dangers.txt");
			int choice = menuOptions("takes items, leave", "leave");
			if (choice == 1) {
				inventory.add_item("sample containers");
			}
		}
	}
	std::cout << "** Leaving AMR Lab ** \n";
	return end_game;
}

//this will control the flow of actions that can occur
//in the rift, it will return a bool to indicate if
// the game has ended
bool Map::rift_actions() {
	bool end = false;
	cbodies[4]->description("rift.txt");
	int choice = menuOptions("Sure, why not!", "What? no!");
	if (choice == 1) {
		inventory.add_item("rift samples");
	}
	std::cout << "*** Incoming message: Open? ***\n";
	choice = menuOptions("Of course!", "Of course NOT!");
	if (choice == 1) {
		readFile("mystry_mesg.txt");
		std::cout << "** Leaving RIFT ** \n";
	}
	else {
		readFile("pirate_death.txt");
		end = true;
	}

	return end;
}

//this will control the flow of the acctions that can occur
//at the bar on Ceta, it returns a bool for end game
//test
bool Map::bar_actions() {
	cbodies[2]->print_rm_info("bar.txt", 2, 0);
	int choice = menuOptions("Sure, seems like I'm missing something",
		"This is ridiculous. No way");
	if (choice == 2) {
		readFile("ship_blk.txt");
	}
	cbodies[2]->print_rm_info("hacHQ.txt", 2, 4);
	choice = menuOptions("I had a fishy feeling. How can I help?",
		"NO! I trust my governemnt, you guys are crazy");
	if (choice == 2) {
		return false; //game has not ended but not taking items
	}
	readFile("solution.txt");
	choice = menuOptions("More history, then take items and leave",
		"Just take items and leave");
	if (choice == 1) {
		readFile("more_info.txt");
	}
	std::cout << "** Leaving hacktivist HQ **\n";
	inventory.add_item("search device");
	return false; //game has not ended
}

bool Map::ootLab_actions() {
	cbodies[3]->print_rm_info("oot_lab.txt",3 , 2);
	//search inventory to use
	inventory.print_inventory();
	int search = inventory.search_inventory("search device");
	if (search == -1) {
		std::cout << "You don't have the right device!"
			<< "Not enough time to fix it, GAME OVER\n";
		return true; //end game
	}
	else {
		readFile("oot_loot.txt");
		int choice = menuOptions("yes", "no");
		if (choice == 1) {
			std::cout << "An exectuable file that says \"Simulation\""
				<< " and a \nfile that has this old passage in it\n";
			readFile("forty2.txt");
		}
		std::cout << "Add items?\n";
		choice = menuOptions("yes", "no");
		if (choice == 1) {
			inventory.add_item("executable");
			inventory.add_item("cryptic file");
		}
	}
	std::cout << "** You exit the building **\n";
	return false;
}

bool Map::sscs_actions() {
	bool end_game = false;
	if (!visited_O) {
		std::cout << "You try to come up with a solution here, but"
			<< " nothing is working out.\nYou decide to keep"
			<< " exploring. In hope of finding more info.\n";
		end_game = true;
	}
	else {
		int search = inventory.search_inventory("special access badge");
		if (search == -1) {
			std::cout << "You can't get in and wasted too much time waiting.\n"
				<< "GAME OVER";
			end_game = true;
		}
		else {
			std::cout << "** Unloocking door with badge **\n";
			cbodies[1]->print_rm_info("sscs_inside.txt", 1, 1);
			int choice = menuOptions("Use supercomputer without asking",
				"Ask to use supercomputer nicely");
			if (choice == 2) {
				std::cout << "Amidst all the arguing about computer use"
					<< "you have ran out of time. GAME OVER.";
				end_game = true; // game is over
			}
			//search inventory for thumb drive
			search = inventory.search_inventory("executable");
			if (search == -1) {
				std::cout << "You don't have the right tools. And not enough time left\n"
					<< "GAME OVER";
				end_game = true;
			}
			else {
				std::cout << "Program requires sample insertion.\n";
				inventory.print_inventory();
				std::cout << " ** Using executable** \n";
				std::cout << "Enter a single number as a parameter:\n";
				std::cout << "HERB mentions it probably has to do with"
				     << " the other file that was \n on the thumbdrive\n";
				choice = menuOptions("Look at that file", "I got this");
				if (choice == 1) {
					readFile("forty2.txt");
				}
				int num;
				std::cout << "Enter a single number as a parameter:\n>";
				std::cin >> num;
				if (num == 42)
				std::cout << "YOU'VE SAVED THE UNIVERSE!!\n";
				return true;
			}
		}
	}
	return end_game;
}


//for testing single map fxns
void Map::testing() {

}
