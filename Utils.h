#pragma once
#include "User.h"

class Utils
{
private:
	const std::string password;
	enum INPUT_TYPE {STRING, PASSWORD, INT};


public:
	std::string requestUserInput(std::string message);


};

