/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:16 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 10:46:23 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Default Dog constructor called with type " << this->_type 
		<< " and Animal type " << Animal::_type << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
	return;
}

Dog::Dog(Dog const& rhs) {
	this->_type = rhs.getType();
	this->_brain = new Brain;
	this->_brain->setIdeas(rhs.getBrain()->getIdeas());
	std::cout << "Dog copy constructor called with type " << this->_type << std::endl;
	return;
}

Dog const& Dog::operator=(Dog const& rhs) {
	this->_type = rhs.getType();
	this->_brain->setIdeas(rhs.getBrain()->getIdeas());
	std::cout << "Dog assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}

std::string Dog::getType(void) const {
	return this->_type;
}

void Dog::makeSound(void) const {
	std::cout << "I am a " << this->_type << " also known as " << Animal::_type << " Woof!" << std::endl;
	return;
}

Brain const*	Dog::getBrain(void) const {
	return this->_brain;
}


