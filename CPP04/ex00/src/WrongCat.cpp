/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:06 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:00:34 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor called with type " << this->_type
	<< " and WrongAnimal type " << WrongAnimal::_type << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const& rhs) {
	*this = rhs;
	std::cout << "WrongCat copy constructor called with type " << this->_type << std::endl;
	return;
}

WrongCat const& WrongCat::operator=(WrongCat const& rhs) {
	this->_type = rhs.getType();
	std::cout << "WrongCat assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}


std::string WrongCat::getType(void) const {
	return this->_type;
}

void WrongCat::makeSound(void) const {
	std::cout << "Miaauw" << std::endl;
	return;
}

