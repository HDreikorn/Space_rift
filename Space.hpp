/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for abstract space class
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
private:
	std::string name;

protected:
	//pointers for changing locations
	Space *N;
	Space *S;
	Space *E;
	Space *W;

public:
	Space();
	Space(std::string);
	virtual ~Space();
	virtual void description(std::string)= 0;
	std::string get_name();
	virtual void print_rm_info(std::string, int, int) = 0;
};

#endif


