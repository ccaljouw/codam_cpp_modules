/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:45:20 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 16:06:08 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource(void) {
	std::cout << "IMaterial constructor called"<< std::endl;
	return;
}

IMateriaSource::~IMateriaSource(void) {
	std::cout << "IMaterial destructor called"<< std::endl;
	return;
}
