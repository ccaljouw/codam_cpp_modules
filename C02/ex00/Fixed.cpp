/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 13:03:27 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return;
}
