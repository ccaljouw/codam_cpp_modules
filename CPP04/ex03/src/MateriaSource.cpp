/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:45:20 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:21:23 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include <iostream>


MateriaSource::MateriaSource( void ) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const& rhs) {
	*this = rhs;
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
	return *this;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete _inventory[i];
	}
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

void	MateriaSource::printInventory(void) const {
	std::cout << "Current material inventory:" << std::endl;
	for(int i = 0; i < 4; i++) {
		std::cout << "[" << i << "]";
		if(this->_inventory[i])
			std::cout << this->_inventory[i]->getType() << std::endl;
		else
			std::cout << "empty slot" << std::endl;
	}
	return;
}

