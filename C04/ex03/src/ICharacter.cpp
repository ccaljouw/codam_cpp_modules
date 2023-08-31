/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ICharacter.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:56:11 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 18:03:00 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter constructor called"<< std::endl;
	return;
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called"<< std::endl;
	return;
}
