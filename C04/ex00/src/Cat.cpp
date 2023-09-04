/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:06 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:20:35 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal("CatAnimal") {
	this->_type = "Cat";
	std::cout << "Default Cat constructor called with type " << this->_type
	<< " and Animal type " << Animal::_type << std::endl;
	return;
}

Cat::Cat( std::string type ) : Animal(type) {
	this->_type = "Cat";
	std::cout << "Cat constructor called with type " << this->_type 
		<< " and Animal type " << Animal::_type << std::endl;
	return;
}

Cat::Cat( Cat const& rhs) {
	*this = rhs;
	std::cout << "Cat copy constructor called with type " << this->_type << std::endl;
	return;
}

Cat const& Cat::operator=( Cat const& rhs) {
	this->_type = rhs.getType();
	std::cout << "Cat assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	return;
}

void Cat::makeSound( void ) const {
	std::cout << "I am a " << this->_type << " also known as " << Animal::_type << " Miaauw!" << std::endl;
	return;
}