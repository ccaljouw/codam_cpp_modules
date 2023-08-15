/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:17:54 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 16:15:24 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( void ) {
	return;
}

HumanB::HumanB( std::string name ) : _name(name) {
	return;
}

HumanB::~HumanB( void ) {
	return;
}

void	HumanB::setWeapon( Weapon myWeapon ) {
	_myWeapon = myWeapon;
	return;
}

void	HumanB::attack( void ) const {
	std::cout << _name << " attacks with their " << _myWeapon.getType() << std::endl;
	return;
}