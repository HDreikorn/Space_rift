/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/14/2017
** Description: This is the declaration file for the file functions
***********************************************************************/
#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <fstream>
#include <string>
#include "Menu.hpp"

void readFile(std::string file);

//overloaded menu options display and choice
int menuOptions(std::string, std::string);
int menuOptions(std::string, std::string,std::string);
int menuOptions(std::string, std::string, std::string, std::string);
int menuOptions(std::string, std::string, std::string, std::string,
	std::string);

//void writeFile(std::fstream &file, int *array, int size);
//void printArr(int *array, int size);
//void printFound(std::string, int);


#endif
