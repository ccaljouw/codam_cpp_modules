/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:55:06 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 16:06:19 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat( void ) : AAnimal("CatAAnimal") {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default Cat constructor called with type " << this->_type
	<< " and AAnimal type " << AAnimal::_type << std::endl;
	return;
}

Cat::Cat( std::string type ) : AAnimal(type) {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called with type " << this->_type 
		<< " and AAnimal type " << AAnimal::_type << std::endl;
	return;
}

Cat::Cat( Cat const& rhs) {
	this->_type = rhs.getType();
	this->_brain = new Brain();
	this->_brain->setIdeas(rhs._brain->getIdeas());
	std::cout << "Cat copy constructor called with type " << this->_type << std::endl;
	return;
}

Cat const& Cat::operator=( Cat const& rhs) {
	this->_type = rhs.getType();
	this->_brain->setIdeas(rhs._brain->getIdeas());
	std::cout << "Cat assignment constructor called with type " << this->_type << std::endl;
	return *this;
}

Cat::~Cat( void ) {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return;
}

void Cat::makeSound( void ) const {
	std::cout << "I am a " << this->_type << " also known as " << AAnimal::_type << " Miaauw!" << std::endl;
	return;
}
