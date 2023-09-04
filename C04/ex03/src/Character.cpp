/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:06:58 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/04 12:47:29 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

Character::Character( void ) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_oldInventory = nullptr;
	this->_oldInventorySize = 0;
	std::cout << "Default Character constructor called" << std::endl;
	return;
}

Character::Character( std::string name )  {
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_oldInventory = nullptr;
	this->_oldInventorySize = 0;
	std::cout << "Character constructor called with type " << this->_name << std::endl;
	return;
}

Character::Character( Character const& rhs ) {
	*this = rhs;
	std::cout << "Character coppy constructor called with type " << this->_name << std::endl;
	return;
}

Character const& Character::operator=( Character const& rhs ) {
	this->_name = rhs.getName();
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
	for(int i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->equip(rhs._inventory[i]->clone());
	}
	std::cout << "Character coppy assignment constructor called with type " << this->_name << std::endl;
	return *this;
}

Character::~Character( void ) {
	std::cout << "Character destructor called on " << this->getName() << std::endl;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	// clean old inventory
	return;
}

std::string const & Character::getName( void ) const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			std::cout << "equipping " << this->getName() << " with " << m->getType() << std::endl;
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << this->getName() << " already fully equiped" << std::endl;
	this->addToOldInventory(m);
	return;
}

void Character::unequip(int idx) {
	if (this->_inventory[idx]) {
		this->addToOldInventory(this->_inventory[idx]);
		this->_inventory[idx] = nullptr;
	}
	return;
}

void Character::use(int idx, ICharacter& target) {
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	return;
}

void		Character::addToOldInventory(AMateria* m) {
	AMateria** temp;
	if (!this->_oldInventorySize)
		temp = new AMateria*[1];
	else {
		temp = new AMateria*[this->_oldInventorySize + 1];
		for (int i = 0; i < this->_oldInventorySize; i++)
			temp[i] = this->_oldInventory[i];
		delete [] this->_oldInventory;
	}
	this->_oldInventory = temp;
	this->_oldInventory[this->_oldInventorySize] = m;
	this->_oldInventorySize++;
	return;
}
