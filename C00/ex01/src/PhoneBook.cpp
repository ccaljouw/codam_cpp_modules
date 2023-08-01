/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 16:21:06 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nr_contacts(0) {
	std::cout << "Phonebook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Phonebook destructor called" << std::endl;
	return;
}

void	PhoneBook::addContact(void) {
	std::string fn;
	std::string ln;
	std::string	nn;
	std::string pn;
	std::string secr;

	std::cout << "first name: ";
	std::cin >> fn;
	std::cout << "last name: ";
	std::cin >> ln;
	std::cout << "nickname: ";
	std::cin >> nn;
	std::cout << "phone number: ";
	std::cin >> pn;
	std::cout << "deepest darkest secret: ";
	std::cin >> secr;
	this->_contacts[this->_nr_contacts % 8].setContact(this->_nr_contacts, fn, ln, nn, pn, secr);
	this->_nr_contacts += 1;
	std::cout << "nr of contacts now: " << this->_nr_contacts << std::endl;
	return;
}

int		PhoneBook::getNrContacts(void) const {
	return this->_nr_contacts;
}

Contact	PhoneBook::getContact(int i) const {
	return this->_contacts[i -1];
}

void	PhoneBook::printPhonebook(void) const {
	for (int i = 0; i < this->_nr_contacts && i < 8; i++)
	{
		std::cout << this->_contacts[i].getIndex() << std::endl;
		std::cout << this->_contacts[i].getFirstName() << std::endl;
		std::cout << this->_contacts[i].getLastName() << std::endl;
		std::cout << this->_contacts[i].getNickname() << std::endl;
	}
}