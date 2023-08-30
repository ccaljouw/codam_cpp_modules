/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:14:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 18:33:29 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure(std::string const& type) : AMateria(type) {
	this->_type = "cure";
	std::cout << "Cure constructor called with type " << this->_type << std::endl;
	return;
}

Cure::Cure( Cure const& rhs) : AMateria() {
	*this = rhs;
	std::cout << "Cure copy constructor called with type " << this->_type << std::endl;
	return;
}

Cure const& Cure::operator=( Cure const& rhs ) {
	this->_type = "cure";
	std::cout << "Cure copy assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Cure::~Cure( void ) {
	std::cout << "Cure destructor called with type " << this->_type << std::endl;
	return;
}

Cure* Cure::clone() const {
	Cure *cl = new Cure("cure");
	return cl;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
	return;
}
