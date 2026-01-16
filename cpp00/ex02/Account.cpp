#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>

std::string get_time_stamp(void)
{
	time_t now = std::time(NULL);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
	return std::string(buffer);
}

Account::Account(int initial_deposit)
{
	static int i = 0;
	time_t timestamp;
	char buffer[16];

	Account::_accountIndex = 0;
	i++;
	Account::_amount = initial_deposit;
	time(&timestamp);
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&timestamp));
	std::cout << "[" << buffer << "]" "index:"<< 0 << ";amount:" << 42 << ";created" << std::endl;
	return ;
}

