/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:17:51 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 15:42:55 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& myWeapon) : _name(name), _myWeapon(myWeapon) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void	HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _myWeapon.getType() << std::endl;
	return;
}