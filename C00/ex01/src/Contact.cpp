/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:47 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/02 15:54:53 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void) : index(0) {
	return;
}

Contact::~Contact(void) {
	return;
}

std::string Contact::_getInput(std::string str) {

	std::string input;
	
	while (!input.length())
	{
		std::cout << std::setw(24) << std::setfill(' ') << std::left << str << std::flush;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Ctrl+D: exiting program" << std::endl;
			exit(0);
		}
	}
	return (input);
}

void	Contact::setContact(int i) {
	int	valid  = 0;
	
	this->index = i + 1;
	this->first_name = _getInput("Enter first name: ");
	this->last_name = _getInput("Enter last name: ");
	this->nickname = _getInput("Enter nickname: ");
	while (valid == 0)
	{
		this->_phone_nr = _getInput("Enter phone number: ");
		valid = 1;
		for(unsigned long i = 0; i < _phone_nr.length(); i++)
			if (!isdigit(_phone_nr[i]))
				valid = 0;
		if (_phone_nr.length() != 10)
			valid = 0;
		if (valid == 0)
			std::cout << "Invallid phone number please try again" << std::endl;
	}
	this->_secret = _getInput("Enter deep dark secret: ");
	std::cout << std::endl;
	return;
}

int	Contact::printContact(void) const{
	if (index)
	{
		std::cout << std::endl << "first name:	" << this->first_name << std::endl;
		std::cout << "last name:	" << this->last_name << std::endl;
		std::cout << "nickname:	" << this->nickname << std::endl;
		std::cout << "phone:		" << this->_phone_nr << std::endl;
		std::cout << "secret:		" << this->_secret << std::endl << std::endl;
		return 0;
	}
	return -1;
}
