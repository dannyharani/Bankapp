// BankApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Utils.h"
#include "Bank.h"

int main()
{

	Bank bank = Bank(5);

	bank.interact();

}
