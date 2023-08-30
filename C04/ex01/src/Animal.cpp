/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:54:36 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 12:52:01 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal( void ) {
	std::cout << "Default Animal constructor called" << std::endl;
	return;
}

Animal::Animal( std::string type ) {
	this->_type = type;
	std::cout << "Animal constructor called with type " << type << std::endl;
	return;
}

Animal::Animal( Animal const& rhs) {
	*this = rhs;
	std::cout << "Animal copy constructor called with type " << this->_type << std::endl;
	return;
}

Animal const& Animal::operator=( Animal const& rhs) {
	this->_type = rhs.getType();
	std::cout << "Animal assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
	return;
}

std::string Animal::getType( void ) const {
	return this->_type;
}

void		Animal::makeSound( void ) const {
	std::cout << "Just an Animal" << std::endl;
	return;
}
