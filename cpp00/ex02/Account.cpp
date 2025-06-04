#include "Account.hpp"

#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static unsigned int	i = 0;

	i++;
	this->_nbAccounts = i;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = i - 1;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << i - 1 << ";"
	<< "amount:" << initial_deposit << ";"
	<< "created" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	time_temp;
	struct tm	time2;
	char	output[19];

	time_temp = time(0);
	time2 = *localtime(&time_temp);
	std::strftime(output, sizeof(output), "[%Y%m%d_%H%M%S] ", &time2);
	std::cout << output;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus()	const
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		std::cout << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

Account::~Account()
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed" << std::endl;
}
