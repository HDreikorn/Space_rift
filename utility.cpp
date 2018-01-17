/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for the file operations
** it will have functions to read from files, write to files and print
** the data from the arrays
***********************************************************************/
#include <iostream>
#include <string>
#include "utility.hpp"

//***********************************************************************
// readFile() - this function will read from the file and then print
// each line in the file
//***********************************************************************
void readFile(std::string fileName) {
	std::fstream inFile;
	inFile.open(fileName);

	//if the file doesn't open
	if (inFile.fail()) {
		std::cout << "Failure opening file.\n";
	}
	std::string line;
	while (getline(inFile, line)) {
		std::cout << line <<std::endl;
	}
	std::cout << std::endl;

	inFile.close();
}

//the menu option will be an overloaded function that will create a 
//new menu with correct number of parameters, then get user choice
//and return it.
int menuOptions(std::string str1, std::string str2) {
	Menu *newMenu = new Menu(str1, str2);
	newMenu->display();
	int choice = newMenu->getChoice(2);
	delete newMenu;
	return choice;
}

int menuOptions(std::string str1, std::string str2,
	std::string str3) {
	Menu *newMenu = new Menu(str1, str2, str3);
	newMenu->display();
	int choice = newMenu->getChoice(3);
	delete newMenu;
	return choice;
}

int menuOptions(std::string str1, std::string str2,
	std::string str3, std::string str4) {
	Menu *newMenu = new Menu(str1, str2, str3, str4);
	newMenu->display();
	int choice = newMenu->getChoice(4);
	delete newMenu;
	return choice;
}

int menuOptions(std::string str1, std::string str2,
	std::string str3, std::string str4, std::string str5) {
	Menu *newMenu = new Menu(str1, str2, str3, str4, str5);
	newMenu->display();
	int choice = newMenu->getChoice(5);
	delete newMenu;
	return choice;
}