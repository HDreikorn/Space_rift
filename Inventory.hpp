/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for inventory class
***********************************************************************/
#include <string>
#include <vector>

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

class Inventory
{
private:
	std::vector <std::string> inventory;
	std::string name;
public:
	Inventory();
	Inventory(std::string);
	~Inventory();
	std::string get_name();
	void print_inventory();
	void add_item(std::string);
	int search_inventory(std::string);
};

#endif 



