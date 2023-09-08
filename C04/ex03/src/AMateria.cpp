/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:55:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:07:00 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) {
	return;
}

AMateria::AMateria(std::string const& type) {
	this->_type = type;
	return;
}

AMateria::AMateria( AMateria const& rhs) {
	*this = rhs;
	return;
}

AMateria const& AMateria::operator=( AMateria const& rhs ) {
	this->_type = rhs.getType();
	return *this;
}

AMateria::~AMateria( void ) {
	return;
}

std::string const& AMateria::getType( void ) const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	return;
}

std::ostream& operator<<(std::ostream& o, AMateria const& i) {
	o << i.getType();
	return o;
}
