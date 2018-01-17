/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for the menu class
** which handles all menus needed in the game
***********************************************************************/
#include "Menu.hpp"
#include "validationUtility.hpp"
#include <iostream>

//overloaded constructors to print different menus
Menu::Menu(std::string op1, std::string op2)
{
	options.push_back(op1);
	options.push_back(op2);
}
Menu::Menu(std::string op1, std::string op2, std::string op3)
{
	options.push_back(op1);
	options.push_back(op2);
	options.push_back(op3);
}
Menu::Menu(std::string op1, std::string op2, std::string op3,
	std::string op4)
{
	options.push_back(op1);
	options.push_back(op2);
	options.push_back(op3);
	options.push_back(op4);
}
Menu::Menu(std::string op1, std::string op2, std::string op3,
	std::string op4, std::string op5)
{
	options.push_back(op1);
	options.push_back(op2);
	options.push_back(op3);
	options.push_back(op4);
	options.push_back(op5);
}


Menu::~Menu()
{
	options.clear();
}

//this function display the conents of the veector in menu form
void Menu::display()
{
	for (unsigned i = 0; i < options.size(); i++)
	{
		std::cout << i + 1 << ". " << options.at(i) <<
			std::endl;
	}
}

//This function clear the menu options so it can be used again
void Menu::clear()
{
	while (!options.empty())
	{
		options.pop_back();
	}
}

//this function will get the menu choice based on size then return
int Menu::getChoice(int size) {
	int userChoice;
	if (size == 2)
	{
		userChoice = only1to2();
	}
	if (size == 3)
	{
		userChoice = only1to3();
	}	
	if (size == 4)
	{
		userChoice = only1to4();
	}
	if (size == 5)
	{
		userChoice = only1to5();
	}
	return userChoice;

}