/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:27 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 15:04:46 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	_fixedPointValue = 0;
	return;
}

Fixed::Fixed(const int i) {
	_fixedPointValue = i << _fractionalBits;
	return;
}

Fixed::Fixed(const float f) {
	_fixedPointValue = (int)std::roundf(f * (1 << _fractionalBits));
	return;
}

Fixed::Fixed(const Fixed& rhs) {
	*this = rhs;
	return;
}

Fixed&  Fixed::operator=(const Fixed& rhs) {
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
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
	float f = (float)(this->getRawBits()) / (1 << _fractionalBits);
	return f;
}

int		Fixed::toInt(void) const {
	int	i = this->_fixedPointValue >> _fractionalBits;
	return i;
}

std::ostream& operator<<(std::ostream& out, Fixed const& in) {
	out << in.toFloat();
	return out;
}

//--------------------------------------------
// comparison operators
//--------------------------------------------

bool	Fixed::operator>(const Fixed& rhs) const {
	return this->toFloat() > rhs.toFloat();
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	return this->toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return this->toFloat() < rhs.toFloat();
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	return this->toFloat() <= rhs.toFloat();
}

bool	Fixed::operator==(const Fixed& rhs) const {
	return this->toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return this->toFloat() != rhs.toFloat();
}

//--------------------------------------------
// arithmic operators
//--------------------------------------------

Fixed	Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat()) ;
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat()) ;
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat()) ;
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat()) ;
}

//--------------------------------------------
// increment/decrement operators
//--------------------------------------------

Fixed&	Fixed::operator++(void) {
	++this->_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed&	Fixed::operator--(void) {
	--this->_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

//--------------------------------------------
// overloaded member functions
//--------------------------------------------

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}
