/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:13:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:07:43 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria() {
	this->_type = "ice";
	return;
}

Ice::Ice(std::string const& type) : AMateria(type) {
	this->_type = "ice";
	return;
}

Ice::Ice( Ice const& rhs) : AMateria() {
	*this = rhs;
	return;
}

Ice const& Ice::operator=( Ice const& rhs ) {
	(void)rhs;
	this->_type = "ice";
	return *this;
}

Ice::~Ice( void ) {
	return;
}

Ice* Ice::clone() const {
	Ice *cl = new Ice("ice");
	return cl;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an icebot at " << target.getName() << " *" << std::endl;
	return;
}

std::ostream& operator<<(std::ostream& o, Ice const& i) {
	o << i.getType();
	return o;
}
