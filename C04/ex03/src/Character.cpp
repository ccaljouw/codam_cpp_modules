/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:06:58 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/04 12:07:37 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

Character::Character( void ) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_oldInventorySize = 0;
	this->_oldInventory = nullptr;
	std::cout << "Default Character constructor called" << std::endl;
	return;
}

Character::Character( std::string name ) {
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_oldInventorySize = 0;
	this->_oldInventory = nullptr;
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
	for(int i = 0; i < this->_oldInventorySize; i++)
		delete this->_oldInventory[i];
	for(int i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->equip(rhs._inventory[i]->clone());
	}
	std::cout << "Character coppy assignment constructor called with type " << this->_name << std::endl;
	return *this;
}

Character::~Character( void ) {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for(int i = 0; i < this->_oldInventorySize; i++) {
		std::cout << "delete:" << i << std::endl;
		delete this->_oldInventory[i];
	}
	delete [] this->_oldInventory;
	std::cout << "Character destructor called on " << this->getName() << std::endl;
	return;
}

std::string const & Character::getName( void ) const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			std::cout << "equipping " << this->getName() << " with " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << this->getName() << " already fully equiped" << std::endl;
	this->_oldInventory[this->_oldInventorySize] = m;
	this->_oldInventorySize++;
	return;
}

void Character::unequip(int idx) {
	std::cout << "old inventory size:" << this->_oldInventorySize << std::endl;
	if (!this->_inventory[idx])
		return;
	if(!this->_oldInventorySize) {
		this->_oldInventory = new AMateria*[1];
		this->_oldInventory[0] = this->_inventory[idx];
	}
	else {
		AMateria** temp = new AMateria*[this->_oldInventorySize + 1];
		for(int i = 0; i < _oldInventorySize; i++)
			temp[i] = this->_oldInventory[i];
		delete [] _oldInventory;
		this->_oldInventory = temp;
	}
	this->_oldInventory[this->_oldInventorySize] = 	this->_inventory[idx];
	this->_oldInventorySize++;
	this->_inventory[idx] = nullptr;
	return;
}

void Character::use(int idx, ICharacter& target) {
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
		delete this->_inventory[idx];
		this->_inventory[idx] = nullptr;
	}
	return;
}
