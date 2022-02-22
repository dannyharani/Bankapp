#include "Bank.h"
#include <iostream>

void Bank::deposit(User user, float amount)
{

	BALANCE.at(retrieveId(user)) += amount;

}


bool Bank::withdraw(User user, float amount)
{
	if (BALANCE.at(retrieveId(user)) < amount) 
	{
		std::cout << std::endl << "INVALID AMOUNT" << std::endl;
		return false;
	}
	else 
	{
		BALANCE.at(retrieveId(user)) -= amount;
	}
	return true;
}

int Bank::retrieveId(User user)
{
	for (int i = 0; i < USERS.size(); i++)
	{
		if (user == USERS.at(i))
			return i;
	}

	return -1;
}

void Bank::addUser(User user, float initial_balance)
{
	USERS.push_back(user);
	BALANCE.push_back(initial_balance);
}

Bank::Bank(int size)
{
	Bank::BANKSIZE = size;

	std::vector<User> USERS(BANKSIZE);
	std::vector<float> BALANCE(BANKSIZE);
	
}

void Bank::interact()
{
	std::string RESPONSE = "";
	std::cout << "Welcome to your bank management system\nLet's add some users!" << std::endl;

	while (RESPONSE != "EXIT")
	{
		std::string name = "", number;
		
		std::cout << std::endl << "Enter their full-name: ";
		std::getline(std::cin, name);


		std::cout <<std::endl<< "Now enter a phone number: ";
		std::getline(std::cin, number);

		int year, day, month;
		float balance;
		
		std::cout << std::endl << "Year of birth: ";
		std::cin >> year;

		std::cout << std::endl << "Birth-month: ";
		std::cin >> month;

		std::cout << std::endl << "Birth-day: ";
		std::cin >> day;

		std::cout << std::endl << "Finally, enter their initial balance: ";
		std::cin >> balance;

		User tmp = User(name, number, day, month, year);
		addUser(tmp, balance);

		std::cout << std::endl << "Would you like to exit (EXIT) or continue(ANY): ";
		std::cin >> RESPONSE;
		std::cin.ignore();
	}

	std::cout << std::endl << "Here are all bank users: " << std::endl << std::endl;

	for (int i = 0; i < USERS.size(); i++)
	{
		std::cout << i+1 << " - " << USERS.at(i).getInfo() << std::endl;
	}

	int opperation = 0;
	enum option { DISPLAY = 1, ADD_FUNDS, WITHDRAW_FUNDS };

	while (true)
	{
		std::cout << std::endl << "Do you want to (1)-Display, (2)-Add funds, (3)-Withdraw funds: ";
		std::cin >> opperation;
		
		int identifier;
		float tmp;

		if (opperation == DISPLAY)
		{
			std::cout << std::endl;
			for (int i = 0; i < USERS.size(); i++)
			{
				std::cout << i + 1 << " - " << USERS.at(i).getInfo() << " BALANCE: " << BALANCE.at(i) << std::endl;
			}
		}
		else if (opperation == ADD_FUNDS)
		{
			std::cout << std::endl << "Which user would you like to add funds to (1-" << USERS.size() << "): ";
			std::cin >> identifier;

			std::cout << std::endl << "How much would you like to deposit: ";
			std::cin >> tmp;

			deposit(USERS.at(identifier - 1), tmp);
		}
		else if (opperation == WITHDRAW_FUNDS)
		{
			std::cout << std::endl << "Which user would you like to withdraw funds from (1-" << USERS.size() << "): ";
			std::cin >> identifier;

			do {

				std::cout << std::endl << "How much would you like to withdraw: ";
				std::cin >> tmp;
				
			} while (!withdraw(USERS.at(identifier-1), tmp));
		}

		std::cout << std::endl << "Would you like to quit your session(1-Quit, 2-continue): ";
		std::cin >> opperation;
		std::cin.ignore();

		if (opperation == 1)
		{
			break;
		}
		
	}

}