#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	static int i = 0;

	Account::_accountIndex = 0;
	i++;
	Account::_amount = initial_deposit;
	std::cout << "[19920104_091532] index:0;amount:42;created"
	return ;
}