/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 19:20:25 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nr_contacts(0) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::addContact(void) {
	std::string fn;
	std::string ln;
	std::string	nn;
	std::string pn;
	std::string secr;

	std::cout << "first name: 			";
	std::cin >> fn;
	std::cout << "last name: 			";
	std::cin >> ln;
	std::cout << "nickname: 			";
	std::cin >> nn;
	std::cout << "phone number: 			";
	std::cin >> pn;
	std::cout << "deepest darkest secret: 	";
	std::cin >> secr;
	std::cout << std::endl;
	//check empty strings
	this->_contacts[this->_nr_contacts].setContact(this->_nr_contacts, fn, ln, nn, pn, secr);
	this->_nr_contacts = (this->_nr_contacts + 1) % 8;
	return;
}

Contact	PhoneBook::getContact(int i) const {
	return this->_contacts[i -1];
}

void	PhoneBook::searchPhonebook(void) const {
	
	int i = 0;
	if (this->_contacts[0].index == 0)
		std::cout << "You do not have any contacts yet" << std::endl;
	else
	{
		printPhonebook();
		std::cout << "Type the index of the contact you want to display: " << std::endl;
		std::cin >> i;
		while (i < 1 || i >= 8 || this->_contacts[i - 1].index == 0)
		{
			std::cout << "The index you provided is incorrect" << std::endl;
			std::cin >> i;
		}
		this->_contacts[i - 1].printContact();
	}
}

void	PhoneBook::printPhonebook(void) const {
	for (int i = 0; i < 8 && this->_contacts[i].index; i++)
	{
		std::cout << this->_contacts[i].index << std::endl;
		std::cout << this->_contacts[i].first_name << std::endl;
		std::cout << this->_contacts[i].last_name << std::endl;
		std::cout << this->_contacts[i].nickname << std::endl;
	}
}