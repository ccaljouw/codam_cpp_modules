/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:54:36 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 16:05:07 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ) {
	std::cout << "Default AAnimal constructor called" << std::endl;
	return;
}

AAnimal::AAnimal( std::string type ) {
	this->_type = type;
	std::cout << "AAnimal constructor called with type " << type << std::endl;
	return;
}

AAnimal::AAnimal( AAnimal const& rhs) {
	*this = rhs;
	std::cout << "AAnimal copy constructor called with type " << this->_type << std::endl;
	return;
}

AAnimal const& AAnimal::operator=( AAnimal const& rhs) {
	this->_type = rhs.getType();
	std::cout << "AAnimal assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
	return;
}

std::string AAnimal::getType( void ) const {
	return this->_type;
}

