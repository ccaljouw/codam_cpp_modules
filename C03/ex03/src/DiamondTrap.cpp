/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 16:34:30 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/04 12:28:18 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ): ScavTrap(), FragTrap() {
	return;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"),  FragTrap(name + "_frag_name") {
	this->_name = name;
	return;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called on " << this->_name << std::endl;
	return;
}

void DiamondTrap::whoAmI( void ) {
	std::cout << "I am DiamondTrap " << this->_name << " also known as "
		<< ClapTrap::_name << " and " << ScavTrap::_name << " and " << FragTrap::_name << std::endl;
	return;
}

void DiamondTrap::getStatus( void ) const {
	std::cout << "\n" << this->_name << " has " << this->_energyPoints 
		<< " energy points and " << this->_hitPoints << " hitpoints." << std::endl;
	if (this->_hitPoints && this->_energyPoints)
		std::cout << "It causes " << this->_attackDamage 
			<< " points of damages when attacking.\n" << std::endl;
	else
		std::cout << "It can no loger attack or repair itsef." << std::endl;
	return;
}
