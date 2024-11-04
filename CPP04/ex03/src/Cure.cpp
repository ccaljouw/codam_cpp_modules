/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:14:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:07:33 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria() {
	this->_type = "cure";
	return;
}

Cure::Cure(std::string const& type) : AMateria(type) {
	this->_type = "cure";
	return;
}

Cure::Cure( Cure const& rhs) : AMateria() {
	*this = rhs;
	return;
}

Cure const& Cure::operator=( Cure const& rhs ) {
	(void)rhs;
	this->_type = "cure";
	return *this;
}

Cure::~Cure( void ) {
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

std::ostream& operator<<(std::ostream& o, Cure const& i) {
	o << i.getType();
	return o;
}
