/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 15:57:08 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 16:08:23 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30; 
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30; 
	std::cout << "FragTrap constructor called with name " << name << std::endl;
	return;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called on " << this->_name << std::endl;
	return;
}

void FragTrap::attack( const std::string& target ) {
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
	std::cout << "High Five?!" << std::endl;
	return;
}