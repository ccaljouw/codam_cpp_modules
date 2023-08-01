/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:47 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 19:18:09 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) : index(0) {
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::setContact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string secr) {
	this->index = i + 1;
	this->first_name = fn;
	this->last_name = ln;
	this->nickname = nn;
	this->_phone_nr = pn;
	this->_secret = secr;
	return;
}

int	Contact::printContact(void) const{
	if (index)
	{
		std::cout << std::endl << this->index << std::endl;
		std::cout << this->first_name << std::endl;
		std::cout << this->last_name << std::endl;
		std::cout << this->nickname << std::endl;
		std::cout << this->_phone_nr << std::endl;
		std::cout << this->_secret << std::endl << std::endl;
		return 0;
	}
	return -1;
}
