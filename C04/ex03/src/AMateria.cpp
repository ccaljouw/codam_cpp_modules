/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:55:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/01 12:05:23 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) {
	std::cout << "Default AMateria constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const& type) {
	this->_type = type;
	std::cout << "AMateria constructor called with type " << this->_type << std::endl;
	return;
}

AMateria::AMateria( AMateria const& rhs) {
	*this = rhs;
	std::cout << "AMateria copy constructor called with type " << this->_type << std::endl;
	return;
}

AMateria const& AMateria::operator=( AMateria const& rhs ) {
	this->_type = rhs.getType();
	// copy inventory
	std::cout << "AMateria copy assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called with type " << this->_type << std::endl;
	return;
}

std::string const& AMateria::getType( void ) const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	return;
}
