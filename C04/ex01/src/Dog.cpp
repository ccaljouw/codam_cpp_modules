/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:16 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 15:29:46 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal("DogAnimal") {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default Dog constructor called with type " << this->_type 
	<< " and Animal type " << Animal::_type << std::endl;
	return;
}

Dog::Dog( std::string type ) : Animal(type) {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called with type " << this->_type 
		<< " and Animal type " << Animal::_type << std::endl;
	return;
}

Dog::Dog( Dog const& rhs) {
	*this = rhs;
	this->_brain->setIdeas(rhs._brain->getIdeas());
	std::cout << "Dog copy constructor called with type " << this->_type << std::endl;
	return;
}

Dog const& Dog::operator=( Dog const& rhs) {
	this->_type = rhs.getType();
	this->_brain->setIdeas(rhs._brain->getIdeas());
	std::cout << "Dog assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Dog::~Dog( void ) {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return;
}

void Dog::makeSound( void ) const {
	std::cout << "I am a " << this->_type << " also known as " << Animal::_type << " Woof!" << std::endl;
	return;
}

