/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 15:57:08 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 12:21:28 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30; 
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30; 
	std::cout << "FragTrap constructor called with name " << name << std::endl;
	return;
}


FragTrap::FragTrap(const FragTrap& rhs) {
	*this = rhs;
	std::cout << "FragTrap copy constructor called with name " 
		<< this->_name << std::endl;
	return;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "FragTrap assignment operator called with name " 
		<< this->_name << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called on " << this->_name << std::endl;
	return;
}

void FragTrap::attack(const std::string& target) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout <<"FragTrap " << this->_name 
			<< " does not have energy to attack" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target
		<< " causing " << _attackDamage << " points of damage." << std::endl;
	this->_energyPoints -= 1;
	return;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints && _energyPoints)
		std::cout << "High Five from " << this->_name << "!" << std::endl;
	else
		std::cout <<"FragTrap " << this->_name 
			<< " does not have energy to high five at the moment" << std::endl;
	return;
}

void FragTrap::getStatus(void) const {
	std::cout << "\n" << this->_name << " has " << this->_energyPoints 
		<< " energy points and " << FragTrap::_hitPoints << " hitpoints." << std::endl;
	if (this->_hitPoints && this->_energyPoints)
		std::cout << "It causes " << this->_attackDamage 
			<< " points of damages when attacking.\n" << std::endl;
	else
		std::cout << "It can no loger attack or repair itsef." << std::endl;
	return;
}
