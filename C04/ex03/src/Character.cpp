/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:06:58 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/01 12:10:39 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

Character::Character( void ) : _cleanup(NULL), _toClean(0) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default Character constructor called" << std::endl;
	return;
}

Character::Character( std::string name ) : _cleanup(NULL), _toClean(0)  {
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
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
			_inventory[i] = NULL;
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
	for(int i = 0; i < this->_toClean; i++)
		delete this->_cleanup[i];
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
	this->_cleanup[this->_toClean] = m;
	this->_toClean++;
	return;
}

void Character::unequip(int idx) {
	this->_cleanup[this->_toClean] = this->_inventory[idx];
	this->_toClean++;
	this->_inventory[idx] = NULL;
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
