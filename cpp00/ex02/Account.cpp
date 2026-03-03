#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	char buffer[16];

	time(&timestamp);
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&timestamp));
	std::cout << "[" << buffer << "]";
	return ;
}

Account::Account(int initial_deposit):
_accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
	<< " index:"<< _accountIndex 
	<< ";amount:" << _amount 
	<< ";created" << std::endl;
	return ;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout 
	<< " index:" << _accountIndex 
	<< ";amount:" << _amount 
	<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout 
	<< " accounts:" << getNbAccounts() << ";"
	<< "total:" << Account::_totalAmount << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
	<< " index:" << _accountIndex
	<< ";p_amount:" << _amount;
	if (deposit < 0)
		std::cout << ";deposit:refused";
	else
	{
		_totalNbDeposits++;
		_nbDeposits++;
		_amount += deposit;
		_totalAmount += deposit;
		std::cout 
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits;
	}
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount - withdrawal < 0)
		withdrawal = -1;
	_displayTimestamp();
	std::cout 
	<< " index:" << _accountIndex 
	<< ";p_amount:" << _amount;
	if (withdrawal > -1)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return (true);
	}
	std::cout
	<< ";withdrawal:refused"<< std::endl;
	return (false);
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< " index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

