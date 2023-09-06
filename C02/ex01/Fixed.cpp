/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 09:40:08 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int i) {
	_fixedPointValue = i << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float f) {
	_fixedPointValue = (int)std::roundf(f * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Fixed&  Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
	return;
}

float	Fixed::toFloat(void) const {
	return (float)(this->getRawBits()) / float(1 << _fractionalBits);
}

int		Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, Fixed const& in) {
	out << in.toFloat();
	return out;
}
