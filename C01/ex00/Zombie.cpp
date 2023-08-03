/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:50:54 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/03 16:46:08 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) {
	std::cout << "Zombie constructor called" << std::endl;
	return;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << "\033[0;32m" << this->_name << "\033[0m constructor called" << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << "\033[0;36m" << this->_name << "\033[0m destructor called" << std::endl;
	return;
}

void Zombie::announce( void ) const {
	std::cout << "\033[0;35m" << this->_name << "\033[0m: BraiiiiiiinnnzzzZ..." << std::endl;
}