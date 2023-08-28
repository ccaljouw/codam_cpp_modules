/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 13:41:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 16:05:42 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20; 
	std::cout << "ScavTrap default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20; 
	std::cout << "ScavTrap constructor called with name " << name << std::endl;
	return;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called on " << this->_name << std::endl;
	return;
}

void ScavTrap::attack( const std::string& target ) {
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

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode" << std::endl;
	return;
}