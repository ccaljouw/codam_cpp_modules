/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/24 15:25:36 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const int num ) : _fixedPointValue( num << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( const float num ) : _fixedPointValue( std::roundf( num * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed( const Fixed& rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed&  Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
	return;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits()) / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return this->_fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<( std::ostream& o, Fixed const& i) {
	return o << i.toFloat();
}

