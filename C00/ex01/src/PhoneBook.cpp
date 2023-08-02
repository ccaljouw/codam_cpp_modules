/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/02 15:51:25 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nr_contacts(0) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::addContact(void) {
	this->_contacts[this->_nr_contacts].setContact(this->_nr_contacts);
	this->_nr_contacts = (this->_nr_contacts + 1) % 8;
	return;
}

Contact	PhoneBook::_getContact(int i) const {
	return this->_contacts[i -1];
}

void	PhoneBook::searchPhonebook(void) const {
	
	std::string input;
	int			i = 0;
	
	if (this->_contacts[0].index == 0)
		std::cout << "You do not have any contacts yet" << std::endl;
	else
	{
		_printPhonebook();
		std::cout << "Type the index of the contact you want to display: " << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Ctrl+D was pressed, exiting program" << std::endl;
			exit(0);
		}
		if (input.length() == 1 && isdigit(input[0]))
			i = std::stoi(input);
		while (i < 1 || i >= 8 || this->_contacts[i - 1].index == 0)
		{ 
			std::cout << "The index you provided is incorrect" << std::endl;
			std::getline(std::cin, input);
			if (input.length() == 1 && isdigit(input[0]))
				i = std::stoi(input);
		}
		this->_contacts[i - 1].printContact();
	}
}

void	PhoneBook::_printPhonebook(void) const {
	for (int i = 0; i < 8 && this->_contacts[i].index; i++)
	{
		std::cout << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << this->_contacts[i].index;
		std::cout << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << (this->_contacts[i].first_name.length() > 10 ? \
			this->_contacts[i].first_name.substr(0,9)+"." : this->_contacts[i].first_name);
		std::cout << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << (this->_contacts[i].last_name.length() > 10 ? \
			this->_contacts[i].last_name.substr(0,9)+"." : this->_contacts[i].last_name);
		std::cout << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << (this->_contacts[i].nickname.length() > 10 ? \
			this->_contacts[i].nickname.substr(0,9)+"." : this->_contacts[i].nickname);
		std::cout << " | " << std::endl;
		std::cout << std::endl;
	}
}