/************************************************************************
** Program Name: Space Rift, Final Project
** Author: Hillary Dreikorn
** Date: 11/22/2017
** Description: This is the declaration file for game engine class that
** will control the glow of the game
***********************************************************************/
#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

class GameEngine
{
private:
	int curr_location;
	enum Bodies
	{
		ULNAR = 1,
		ZURIA = 2,
		CETA = 3,
		OOTS = 4,
		RIFT = 5
	};
public:
	GameEngine();
	~GameEngine();
	void intro();
	void run();
	void test();
};

#endif 
