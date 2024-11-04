/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:54:36 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 12:52:01 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("Wrong animal") {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const& rhs) {
	*this = rhs;
	std::cout << "WrongAnimal copy constructor called with type " << this->_type << std::endl;
	return;
}

WrongAnimal const& WrongAnimal::operator=(WrongAnimal const& rhs) {
	this->_type = rhs.getType();
	std::cout << "WrongAnimal assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}

std::string WrongAnimal::getType(void) const {
	return this->_type;
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "Just a WrongAnimal" << std::endl;
	return;
}
