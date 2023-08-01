/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:47 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 17:18:54 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) : _index(0) {
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::setContact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string secr) {
	this->_index = i + 1;
	this->_first_name = fn;
	this->_last_name = ln;
	this->_nickname = nn;
	this->_phone_nr = pn;
	this->_secret = secr;
	return;
}

void	Contact::printContact(void) const{
	if (_index)
	{
		std::cout << this->_index << std::endl;
		std::cout << this->_first_name << std::endl;
		std::cout << this->_last_name << std::endl;
		std::cout << this->_nickname << std::endl;
		std::cout << this->_phone_nr << std::endl;
		std::cout << this->_secret << std::endl;
	}
	else
		std::cout << "The index you provided is incorrect" << std::endl;
	return;
}

int	Contact::getIndex(void) const{
	return this->_index;
}

std::string	Contact::getFirstName(void) const {
	return this->_first_name;
}

std::string	Contact::getLastName(void) const {
	return this->_last_name;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}