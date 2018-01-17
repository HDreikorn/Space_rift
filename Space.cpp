/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the implementation file for abstract space class
*************************************************************************/
#include "Space.hpp"


Space::Space() {}

Space::Space(std::string n): name(n), N(NULL), S(NULL), E(NULL), W(NULL)
{

}


Space::~Space(){}

void Space::description(std::string){}

void Space::print_rm_info(std::string, int, int)
{
}

std::string Space::get_name()
{
	return name;
}