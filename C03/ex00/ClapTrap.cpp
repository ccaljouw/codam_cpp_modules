/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:15:18 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 13:23:29 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _attackDamage(10) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( const std::string name ) : _name(name), _hitPoints(10), 
											   _energyPoints(10), _attackDamage(10) {
	std::cout << "ClapTrap constructor called with name " << name << std::endl;
	return;
}

ClapTrap::ClapTrap( const ClapTrap& rhs ) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "ClapTrap copy constructor called with name " 
			  << this->_name << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs ) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "ClapTrap copy assignment constructor called with name " 
			  << this->_name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called on name " << this->_name << std::endl;
	return;
}

void ClapTrap::attack( const std::string& target ) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout <<"ClapTrap <_name> " << this->_name 
				  << " does not have energy to attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << " causing " << _attackDamage << " points of damage." << std::endl;
	this->_energyPoints -= 1;
	return;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " was attacked losing " 
				  << amount << " hitpoints." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name 
				  << "was attacked causing it to lose all reamining damage points" 
				  << std::endl;
		this->_hitPoints = 0;
	}
	return;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout <<"ClapTrap " << this->_name 
				  << " does not have energy to repair itself" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout <<"ClapTrap " << this->_name << " repeired itself with " 
			  << amount << " hitpoints." << std::endl;
	return;
}

void ClapTrap::getStatus( void ) {
	std::cout << "\n" << this->_name << " has " << this->_energyPoints << " energy points and "
			  << this->_hitPoints << " hitpoints." << std::endl;
	if (this->_hitPoints && this->_energyPoints)
		std::cout << "It causes " << this->_attackDamage 
				<< " points of damages when attacking.\n" << std::endl;
	else
		std::cout << "It can no loger attack or repair itsef." << std::endl;
	return;
}

unsigned int ClapTrap::getAttackDamage( void ) {
	return this->_attackDamage;
}