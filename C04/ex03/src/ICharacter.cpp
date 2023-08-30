/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ICharacter.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:56:11 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 18:22:37 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ICharacter.hpp"

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called"<< std::endl;
	return;
}