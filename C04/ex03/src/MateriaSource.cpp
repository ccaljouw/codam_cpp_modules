/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:45:20 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 18:18:36 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include <iostream>


MateriaSource::MateriaSource( void ) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default MateriaSource constructor called" << std::endl;
	return;
}

MateriaSource::MateriaSource(MateriaSource const& rhs) {
	*this = rhs;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return;
}

MateriaSource const& MateriaSource::operator=(MateriaSource const& rhs) {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for(int i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	std::cout << "MateriaSource copy assignment constructor called" << std::endl;	
	return *this;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete _inventory[i];
	}
	std::cout << "MateriaSource destructor called"<< std::endl;
	return;
}

void MateriaSource::learnMateria(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if(!this->_inventory[i]) {
			this->_inventory[i] = m;
			break;
		}
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < 4; i++) {
		if(this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	return 0;
}
