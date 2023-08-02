/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 10:56:14 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/02 17:53:35 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// public functions
Account::Account( int initial_deposit ) {
	Account();
	// makeDeposit(initial_deposit);
	return;
}

Account::~Account( void ) {
	return;
}

// int	Account::getNbAccounts( void ) {
// 	return _nbAccounts;
// }

// int	Account::getTotalAmount( void ) {
// 	return _totalAmount;
// }

// int	Account::getNbDeposits( void ) {
// 	return ;
// }

// int	Account::getNbWithdrawals( void ) {
// 	return ;
// }

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	return;
}

// void	makeDeposit( int deposit ) {
// 	return;
// }

// bool	makeWithdrawal( int withdrawal ) {
// 	return ;
// }
// int		checkAmount( void ) const {
// 	return;
// }

// void	displayStatus( void ) const {
// 	return;
// }

//private functions
Account::Account(void) {
	return;
}

void	Account::_displayTimestamp( void ) {
	time_t	tt;
	tm 		*ti;
	
	ti = localtime(&tt); // get right time
	std::cout << asctime(ti) << std::endl; // remove when time is correct
	std::cout << "[";
	std::cout << std::setw(4) << ti->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << ti->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << ti->tm_mday; 
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ti->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ti->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ti->tm_sec;
	std::cout << "]";
	return ;
}