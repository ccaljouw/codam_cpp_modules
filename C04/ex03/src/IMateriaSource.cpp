/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:45:20 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 19:46:20 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/IMateriaSource.hpp"
#include <iostream>

IMateriaSource::~IMateriaSource() {
	std::cout << "IMaterial destructor called"<< std::endl;
	return;
}