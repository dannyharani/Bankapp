#pragma once
#include "User.h"
#include <vector>

class Bank
{
private:
	int BANKSIZE;
	std::vector<User> USERS;
	std::vector<float> BALANCE;

private:
	void addUser(User user, float inital_balance);
	void deposit(User user, float amount);
	bool withdraw(User user, float amount);
	int retrieveId(User user);
	int showFunds(User user);

public:
	Bank(int size);

	void interact();
};

