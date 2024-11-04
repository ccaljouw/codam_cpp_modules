/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:17:54 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 20:08:32 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( void ) : _myWeapon(0) {
	return;
}

HumanB::HumanB( std::string name ) : _name(name), _myWeapon(0) {
	return;
}

HumanB::~HumanB( void ) {
	return;
}

void	HumanB::setWeapon( Weapon& myWeapon ) {

	_myWeapon = &myWeapon;
	return;
}

void	HumanB::attack( void ) const {
	if (_myWeapon)
		std::cout << _name << " attacks with their " << _myWeapon->getType() << std::endl;
	else
		std::cout << _name << " attacks without any weapon" << std::endl;
	return;
}