/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for inventory class
************************************************************************/
#include "Inventory.hpp"
#include <iostream>



Inventory::Inventory(): name("No items")
{}

Inventory::Inventory(std::string n) : name(n) 
{}

Inventory::~Inventory()
{}

//used to retried private data member name
std::string Inventory::get_name() {
	return name;
}

//prints the contents of the inventory vector
void Inventory::print_inventory() {
	std::cout << "Inventory :\n";
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i] << "\n";
	}
}

//this will add the item by name to inventory vector
void Inventory::add_item(std::string item) {
	inventory.push_back(item);
}

//this will search the vector for the string
//given as a parameter in the inventory vector
//it will return the number for the position found
//and wil return -1 if not found
//referenced from: Gaddis C++ Early Objects, Ch.9
int Inventory::search_inventory(std::string item) {
	int index = 0;
	int position = -1;
	bool found = false;
	int size = inventory.size();

	while (index < size && !found) {
		if (inventory[index] == item) {
			found == true;
			position = index;
		}
	index++;
	}
	return position;
}