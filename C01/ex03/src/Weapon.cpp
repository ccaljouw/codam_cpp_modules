/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:17:57 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 16:17:28 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
	return;	
}

Weapon::Weapon( std::string type ) : _type(type) {
	return;	
}

Weapon::~Weapon( void ) {
	return;
}

std::string const&	Weapon::getType( void ) const{
	return this->_type;
}

void	Weapon::setType(std::string str) {
	this->_type = str;
	return;
}
