/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for the menu class
** which handles all menus needed in the game
***********************************************************************/
#include <string>
#include <vector>

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
	private:
		std::vector<std::string> options;
	public:
		//overloading constructor for different menus
		Menu(std::string, std::string);
		Menu(std::string, std::string, std::string);
		Menu(std::string, std::string, std::string, std::string);
		Menu(std::string, std::string, std::string, std::string, std::string);
		~Menu();
		void display();
		void clear();
		int getChoice(int);
};

#endif

