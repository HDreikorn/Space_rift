/************************************************************************
** Program Name: Fantasy Combat Game                                   *
** Author: Hillary Dreikorn                                            *
** Date: 11/12/2017                                                    *
** Description: This is the implementation file  for the validation    *
**              that will be used in the fantasy combat game.          *
***********************************************************************/
#include "validationUtility.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/************************************************************************
*                             isRightType()                            *
* This function will take user input and validate for right type then  *
* return the value once correct type is entered. For this program the  *
* function is validating for integers.                                 *
************************************************************************/
int isRightType()
{
	std::string userInput;
	int returnInput = 0;
	bool validation = true;

	while (validation)
	{
		getline(std::cin, userInput);
		for (int i = 0; i < userInput.length(); i++)
		{
			if (!isdigit(userInput[i]))
			{
				validation = true;
			}
			else
			{
				validation = false;
			}
		}
		if (validation)
		{
			std::cout << "Only numbers! Try again: ";
		}
	}

	//convert string to int
	returnInput = std::atoi(userInput.c_str());
	//return validated input to function called from
	return returnInput;
}

/************************************************************************
*                             posNumOnly()                             *
* This function will take user input and validate for right type then  *
* it will validate for input to be positive numbers only. Then it will *
* return the value back to the function it was called from.            *
************************************************************************/
int posNumOnly()
{
	int posNum;
	bool validate = true;
	//calling isRightType to make sure correct data type first
	posNum = isRightType();

	//loop to make sure number is positive too
	while (validate)
	{
		if (posNum < 1)
		{
			std::cout << "Invalid choice! Try again.\n";
			posNum = isRightType();
		}

		else
		{
			validate = false;
		}
	}
	return posNum;
}

/************************************************************************
*                             only1to5()                               *
* This function will take user input and validate for right type then  *
* it will validate for input to 1 to 5 only. Then it will              *
* return the value back to the function it was called from.            *
************************************************************************/
int only1to5()
{
	int num;
	bool validate = true;
	//calling isRightType to make sure correct data type first
	num = isRightType();

	//loop to make sure number is positive too
	while (validate)
	{
		if (num < 1 || num >5)
		{
			std::cout << "Only options are 1, 2, 3, 4, or 5! Try again.\n";
			num = isRightType();
		}

		else
		{
			validate = false;
		}
	}
	return num;

}

/************************************************************************
*                             only1to4()                               *
* This function will take user input and validate for right type then  *
* it will validate for input to 1 to 4 only. Then it will              *
* return the value back to the function it was called from.            *
************************************************************************/
int only1to4()
{
	int num;
	bool validate = true;
	//calling isRightType to make sure correct data type first
	num = isRightType();

	//loop to make sure number is positive too
	while (validate)
	{
		if (num < 1 || num >4)
		{
			std::cout << "Only options are 1, 2, 3, or 4! Try again.\n";
			num = isRightType();
		}

		else
		{
			validate = false;
		}
	}
	return num;
}
/************************************************************************
*                             only1to3()                               *
* This function will take user input and validate for right type then  *
* it will validate for input to 1 to 3 only. Then it will              *
* return the value back to the function it was called from.            *
************************************************************************/
int only1to3()
{
	int num;
	bool validate = true;
	//calling isRightType to make sure correct data type first
	num = isRightType();

	//loop to make sure number is positive too
	while (validate)
	{
		if (num < 1 || num >3)
		{
			std::cout << "Only options are 1, 2 or 3! Try again.\n";
			num = isRightType();
		}

		else
		{
			validate = false;
		}
	}
	return num;
}

/************************************************************************
*                             only1to2()                               *
* This function will take user input and validate for right type then  *
* it will validate for input to 1 to 2 only. Then it will              *
* return the value back to the function it was called from.            *
************************************************************************/
int only1to2()
{
	int num;
	bool validate = true;
	//calling isRightType to make sure correct data type first
	num = isRightType();

	//loop to make sure number is positive too
	while (validate)
	{
		if (num < 1 || num >2)
		{
			std::cout << "Only options are 1 or 2! Try again.\n";
			num = isRightType();
		}

		else
		{
			validate = false;
		}
	}
	return num;
}
