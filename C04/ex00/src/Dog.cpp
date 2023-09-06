/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:16 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/06 13:57:10 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Default Dog constructor called with type " << this->_type 
	<< " and Animal type " << Animal::_type << std::endl;
	return;
}

Dog::Dog(Dog const& rhs) {
	*this = rhs;
	std::cout << "Dog copy constructor called with type " << this->_type << std::endl;
	return;
}

Dog const& Dog::operator=(Dog const& rhs) {
	this->_type = rhs.getType();
	std::cout << "Dog assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	return;
}

std::string Dog::getType(void) const {
	return this->_type;
}

void Dog::makeSound(void) const {
	std::cout << "I am a " << this->_type << " also known as " << Animal::_type << " Woof!" << std::endl;
	return;
}

