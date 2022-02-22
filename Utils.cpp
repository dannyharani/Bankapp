#include "Utils.h"
#include <iostream>


std::string Utils::requestUserInput(std::string message)
{
	std::string userIn;

	std::cout << message;
	std::cin >> userIn;

	return userIn;
}