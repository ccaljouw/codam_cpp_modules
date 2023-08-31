/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:13:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 16:02:00 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria() {
	this->_type = "ice";
	std::cout << "Ice constructor called with type " << this->_type << std::endl;
	return;
}

Ice::Ice(std::string const& type) : AMateria(type) {
	this->_type = "ice";
	std::cout << "Ice constructor called with type " << this->_type << std::endl;
	return;
}

Ice::Ice( Ice const& rhs) : AMateria() {
	*this = rhs;
	std::cout << "Ice copy constructor called with type " << this->_type << std::endl;
	return;
}

Ice const& Ice::operator=( Ice const& rhs ) {
	(void)rhs; //??
	this->_type = "ice";
	std::cout << "Ice copy assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Ice::~Ice( void ) {
	std::cout << "Ice destructor called with type " << this->_type << std::endl;
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
