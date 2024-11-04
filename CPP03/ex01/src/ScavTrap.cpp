/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 13:41:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 12:09:22 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20; 
	std::cout << "ScavTrap default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20; 
	std::cout << "ScavTrap constructor called with name " << name << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) {
	*this = rhs;
	std::cout << "ScavTrap copy constructor called with name " 
		<< this->_name << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "ScavTrap assignment operator called with name " 
		<< this->_name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called on " << this->_name << std::endl;
	return;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout <<"ScavTrap " << this->_name 
			<< " does not have energy to attack" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< " causing " << _attackDamage << " points of damage." << std::endl;
	this->_energyPoints -= 1;
	return;
}

void ScavTrap::guardGate(void) {
	if (_hitPoints && _energyPoints)
		std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode" << std::endl;
	else
		std::cout <<"ScavTrap " << this->_name 
			<< " does not have energy to go into gatekeeper mode" << std::endl;
	return;
}
