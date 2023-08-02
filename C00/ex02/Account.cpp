/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 10:56:14 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/02 17:43:11 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

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
	
	ti = localtime(&tt);
	std::cout  << asctime(ti) << " " << ti->tm_year << "_" << ti->tm_mon << "_" << ti->tm_mday << "-" \
			<< ti->tm_hour << "_" << ti->tm_min << "_" << ti->tm_sec;
	//print timestamp format: [YYYYMMDD_HHMMSS]
	return ;
}