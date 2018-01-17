/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for game engine class that
** will control the glow of the game
***********************************************************************/
#include "GameEngine.hpp"
#include "utility.hpp"
#include "Menu.hpp"
#include "Map.hpp"

GameEngine::GameEngine() {}


GameEngine::~GameEngine() {}

void GameEngine::intro() {
	readFile("title.txt");
	readFile("intro.txt");
	int read = menuOptions("yes", "no");

	//this portion is if user wants to read assignment deats
	if (read == 1) {
		readFile("assignment.txt");
	}

	//continuing introduction
	readFile("procyon.txt");
	int location = menuOptions("Ulnar", "Zuria", "Poincare Belt",
		"Oots","Uh, remind me which is which");

	//this is if user wants to know about the locations
	if (location == 5) {
		readFile("planetDscrptn.txt");
		std::cout << "So where to?\n";
		location = menuOptions("Ulnar", "Zuria",
			"Ceta Station in Belt", "Oots");
	}
	curr_location = location;
}

void GameEngine::run() {
	//now start the map portion of the game
	Map *game_map = new Map;
	game_map->load_map();


	bool end = false;
	int day = 1;
	//go to location of choice while not dead
	//or time is not up
	while (!end) {
		std::cout << "************\n";
		std::cout << "* DAY : " << day << "  *\n";
		std::cout << "************\n";
		switch (curr_location) {
		case ULNAR:
			end = game_map->move_on_U();
			break;
		case ZURIA:
			end = game_map->move_on_Z();
			break;
		case CETA:
			end = game_map->move_on_C();
			break;
		case OOTS: 
			end = game_map->move_on_O();
			break;
		case RIFT: 
			end = game_map->move_on_R();
			break;
		default:
			std::cout << "Error!\n"; break;
		}
		if (!end) {
			curr_location = menuOptions("Ulnar", "Zuria",
				"Ceta Station in Belt", "Oots", "Rift");
		}
		day++;
		if ( !end && day == 6) {
			std::cout << "\nYou have have ran out of time. The universe\n"
			<< "is ending.....POOF! gone. dead. no more. zilch. zip. 0\n";
			end = true;
		}
	}

	//free map memory to make sure all desctructors are used 
	//from other classes
	delete game_map;
}

void GameEngine::test() {
	Map *game_map = new Map;
	game_map->load_map();

	game_map->testing();

	delete game_map;
}

