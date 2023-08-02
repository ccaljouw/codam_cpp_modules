/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 10:56:14 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/02 21:01:54 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// public functions
Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";";
	std::cout << "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";";
	std::cout << "created" << std::endl;
	return;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";";
	std::cout << "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";";
	std::cout << "closed" << std::endl;
	return;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << "\033[0;34m" << _nbAccounts << "\033[0m" << ";";
	std::cout << "total:" << "\033[0;34m" << _totalAmount << "\033[0m" << ";";
	std::cout << "deposits:" << "\033[0;34m" << _totalNbDeposits << "\033[0m" << ";";
	std::cout << "withdrawals:"<< "\033[0;34m" << _totalNbWithdrawals << "\033[0m" << std::endl;
	return;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << this->_accountIndex << "\033[0m" << ";";
	std::cout << "p_amount:" << "\033[0;34m" << this->_amount << "\033[0m" << ";";
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << "deposit:" << "\033[0;34m" << deposit << "\033[0m" << ";";
	std::cout << "amount:" << "\033[0;34m" << this->_amount << "\033[0m" << ";";
	std::cout << "nb_deposits:" << "\033[0;34m" << this->_nbDeposits << "\033[0m" << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << this->_accountIndex << "\033[0m" << ";";
	std::cout << "p_amount:" << "\033[0;34m" << this->_amount << "\033[0m" << ";";
	if (withdrawal <= _amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals = 1;
		std::cout << "withdrawal:"<< "\033[0;34m" << withdrawal << "\033[0m" << ";";
		std::cout << "amount:" << "\033[0;34m" << this->_amount << "\033[0m" << ";";
		std::cout << "nb_withdrawals:" << "\033[0;34m" << this->_nbWithdrawals << "\033[0m" << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		return 0;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return 1;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << this->_accountIndex << "\033[0m" << ";";
	std::cout << "amount:" << "\033[0;34m" << this->_amount << "\033[0m" << ";";
	std::cout << "deposits:" << "\033[0;34m" << this->_nbDeposits << "\033[0m" << ";";
	std::cout << "withdrawals:" << "\033[0;34m" << this->_nbWithdrawals << "\033[0m" << std::endl;
	return;
}

//private functions
Account::Account(void) {
	return;
}

void	Account::_displayTimestamp( void ) {
	time_t	tt;
	tm 		*tm_local;
	
	tt = time(NULL);
	tm_local = localtime(&tt);
	std::cout << "[";
	std::cout << std::setw(4) << tm_local->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_mday; 
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_sec;
	std::cout << "] ";
	return ;
}